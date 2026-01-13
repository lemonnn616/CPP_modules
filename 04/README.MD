# CPP Module 04 — Subtype Polymorphism, Abstract Classes & Interfaces

This module focuses on runtime polymorphism, virtual destructors, deep copy, abstract classes, and interface-like design in C++.

---

## Repository layout

Each exercise lives in its own directory:

- ex00/ — Polymorphism (Animal/Dog/Cat + WrongAnimal/WrongCat)
- ex01/ — Brain + deep copy (Rule of Three)
- ex02/ — Abstract base class (Animal not instantiable)
- ex03/ — Interfaces & recap (AMateria / ICharacter / IMateriaSource)

Each folder contains its own Makefile and a main.cpp with tests.

---

## Build & run

Go into the exercise folder and run:

    make
    ./<binary_name>

Clean rules (same for all exercises):

    make clean      # remove object files
    make fclean     # remove objects + binary
    make re         # full rebuild

Optional leak check:

    valgrind --leak-check=full ./<binary_name>

Note about the C++ standard: these Makefiles use -std=c++11. If you need strict C++98 compliance for evaluation, switch to -std=c++98 and remove C++11-only features (e.g. override, = delete, range-based for, etc.).

---

# ex00 — Polymorphism (animals)

## Goal
Implement a base class Animal with:
- protected: std::string type;
- getType() accessor
- virtual makeSound() so that derived classes override it properly

Derived classes:
- Dog → type = "Dog", prints dog sound
- Cat → type = "Cat", prints cat sound

Also implement the “wrong” example to demonstrate missing virtual dispatch:
- WrongAnimal
- WrongCat

## What to look for
- Calling makeSound() through a base pointer (Animal*) must call the derived implementation for Dog/Cat.
- In the wrong version, calling through WrongAnimal* should not dispatch to WrongCat as expected (because the base method is not virtual).

Run:
    cd ex00
    make
    ./animals

---

# ex01 — Brain & deep copy (brain)

## Goal
Add a Brain class:
- std::string ideas[100];

Update Dog and Cat:
- Have private: Brain* brain;
- Allocate with new Brain() in the constructor
- Free with delete brain in the destructor

In main:
- Create an array of Animal* (half Dogs, half Cats)
- Delete all as Animal* and ensure correct destructor order
- Prove deep copy (copying a Dog/Cat must duplicate the Brain content, not share it)

## What to look for
- No memory leaks.
- Copy constructor and copy assignment operator for Dog/Cat perform deep copy:
  - brain = new Brain(*other.brain);
- After copying, changing ideas in the copy must not affect the original.

Run:
    cd ex01
    make
    ./brain

---

# ex02 — Abstract class (brain)

## Goal
Make the base class Animal non-instantiable:
- Convert makeSound() into a pure virtual function:
  - virtual void makeSound() const = 0;

Everything else should behave like ex01:
- Polymorphic deletion works
- Dog/Cat still allocate and delete Brain
- Deep copy is still required

Run:
    cd ex02
    make
    ./brain

---

# ex03 — Interfaces & recap (materia)

## Goal
Implement a classic “interface-like” design using pure abstract classes.

## 1) AMateria (abstract base)
- Stores _type
- getType() returns the materia type
- clone() is pure virtual
- use(ICharacter&) is virtual (base version can do nothing)

## 2) Materia types
- Ice → type "ice"
  - use() prints: * shoots an ice bolt at <name> *
  - clone() returns new Ice(*this)
- Cure → type "cure"
  - use() prints: * heals <name>'s wounds *
  - clone() returns new Cure(*this)

## 3) Character interface + implementation
ICharacter interface:
- getName()
- equip(AMateria*)
- unequip(int idx) must not delete the materia
- use(int idx, ICharacter& target)

Character concrete class:
- Inventory: 4 slots (AMateria* _inv[4])
- Equip goes into the first empty slot (0 → 3)
- If inventory full → do nothing
- If idx invalid or empty → do nothing
- Must support deep copy:
  - On copy, clone each equipped materia
  - On assignment, delete old materias before cloning new ones
- Must delete materias on destruction

Implementation detail used here:
- Unequipped materias are stored on a “floor” container so they can be deleted later (to avoid leaks).

## 4) Materia source interface + implementation
IMateriaSource interface:
- learnMateria(AMateria*)
- createMateria(std::string const& type)

MateriaSource concrete class:
- Stores up to 4 learned materias as templates
- learnMateria() stores the pointer if there is space (otherwise deletes it)
- createMateria(type) returns a new cloned materia, or 0 if unknown

Run:
    cd ex03
    make
    ./materia

Expected output includes lines like:
- * shoots an ice bolt at bob *
- * heals bob's wounds *

---

## Key concepts covered

- Subtype polymorphism via virtual methods
- Why virtual destructors matter for deleting through base pointers
- Rule of Three (copy ctor / copy assignment / destructor) with owned resources
- Deep copy vs shallow copy
- Abstract classes (pure virtual functions)
- “Interfaces” in C++ via pure abstract classes
- Prototype pattern via clone()

---
