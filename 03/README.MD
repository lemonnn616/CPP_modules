# C++ Module 03 — Inheritance (CPP03)

This module introduces **inheritance** in C++98: creating derived classes, overriding behavior, showing proper constructor/destructor chaining, and handling the classic **diamond problem** with multiple inheritance.

The project is split into **4 exercises** (`ex00` → `ex03`). Each exercise is its own small program with its own `Makefile`.

---

## Folder layout

Typical structure:

    CPP03/
    ├── ex00/   # ClapTrap
    ├── ex01/   # ScavTrap (inherits ClapTrap)
    ├── ex02/   # FragTrap (inherits ClapTrap)
    └── ex03/   # DiamondTrap (inherits ScavTrap + FragTrap)

---

## Build & run

All exercises use:

- compiler: `c++`
- flags: `-Wall -Wextra -Werror -std=c++98`

### ex00

    cd ex00
    make
    ./claptrap

Clean:

    make clean     # removes .o
    make fclean    # removes .o + binary
    make re        # fclean + make

### ex01

    cd ex01
    make
    ./scavtrap

### ex02

    cd ex02
    make
    ./fixed        # (your exercise binaries: "fixed" + "bsp")

You have multiple sub-exercises in CPP02 in your repo. For CPP03 the binaries are:
`claptrap`, `scavtrap`, `fragtrap`, `diamondtrap`.

### ex02 (CPP03)

    cd ex02
    make
    ./fragtrap

### ex03

    cd ex03
    make
    ./diamondtrap

---

## Exercise 00 — ClapTrap

### Goal
Create your first class and make it “behave” like a simple game entity.

### Class: `ClapTrap`

**Attributes (initial values):**
- `name` (from constructor)
- `hitPoints = 10`
- `energyPoints = 10`
- `attackDamage = 0`

**Public methods:**
- `attack(const std::string& target)`
- `takeDamage(unsigned int amount)`
- `beRepaired(unsigned int amount)`

**Rules you implement (important for evaluation):**
- Attacking costs **1 energy**.
- Repairing costs **1 energy**.
- If `hitPoints <= 0` → cannot attack/repair.
- If `energyPoints <= 0` → cannot attack/repair.
- Each action prints a message describing what happened.
- Constructors/destructor also print messages (so chaining is visible later).

### What your tests show
Your `main.cpp` creates objects, copies them, assigns them, and then calls actions until energy is exhausted. That’s exactly the kind of test evaluators like: it proves behavior in “normal” and “edge” states.

---

## Exercise 01 — ScavTrap (inherits ClapTrap)

### Goal
Your first derived class + overriding behavior + extra ability.

### Class: `ScavTrap : public ClapTrap`

**Stats override (re-initialize for ScavTrap):**
- `hitPoints = 100`
- `energyPoints = 50`
- `attackDamage = 20`

**New ability:**
- `guardGate()`  
  Prints that ScavTrap entered **Gate Keeper mode**.

**Overridden method:**
- `attack(...)` prints a different message (ScavTrap-specific).

### Construction/Destruction chaining
Your tests show:
- Creating a `ScavTrap` first constructs `ClapTrap`
- Destroying happens in reverse order  
This is a key requirement: the evaluator wants to see this clearly in output.

---

## Exercise 02 — FragTrap (inherits ClapTrap)

### Goal
Another derived class, very similar to ScavTrap, but with different stats + a different special ability.

### Class: `FragTrap : public ClapTrap`

**Stats:**
- `hitPoints = 100`
- `energyPoints = 100`
- `attackDamage = 30`

**Special ability:**
- `highFivesGuys()`  
  Prints a positive high-five request.

**Note**
Even if the logic is similar, the **constructor/destructor messages must be different** to make the inheritance chain visible.

---

## Exercise 03 — DiamondTrap (multiple inheritance + diamond problem)

### Goal
Create a class that inherits from both `ScavTrap` and `FragTrap`, while ensuring there is **only one** `ClapTrap` subobject.

### The diamond problem (why it matters)

Without precautions, this happens:

    ClapTrap
     /   \
 ScavTrap FragTrap
     \   /
  DiamondTrap

DiamondTrap would contain **two** separate ClapTrap bases → duplicated `name`, duplicated stats, ambiguous calls.

### Your solution: virtual inheritance

In your headers, you use:

- `class FragTrap : virtual public ClapTrap`
- `class ScavTrap : virtual public ClapTrap`

This ensures `DiamondTrap` contains **exactly one** `ClapTrap` base.

### Class: `DiamondTrap : public ScavTrap, public FragTrap`

**Must contain its own private `name`** (same identifier as ClapTrap’s name variable, but a separate member in DiamondTrap).

**Naming rules:**
- `DiamondTrap::name` = provided name
- `ClapTrap::name` = `provided_name + "_clap_name"`

**Which stats are taken from where:**
- Hit points → from `FragTrap`
- Energy points → from `ScavTrap`
- Attack damage → from `FragTrap`
- `attack()` → must behave like `ScavTrap::attack()`

**New ability:**
- `whoAmI()` prints:
  - DiamondTrap’s own name
  - ClapTrap’s name (`*_clap_name`)

### What your implementation does
- `DiamondTrap::attack()` calls `ScavTrap::attack(target)` explicitly to avoid ambiguity.
- `whoAmI()` prints both names and clearly demonstrates name separation.

---

## Implementation notes (what evaluators usually look for)

### 1) Orthodox Canonical Form (Rule of 3)
For every class where it matters, implement:
- default constructor
- copy constructor
- copy assignment operator
- destructor

Even if the class is simple, the module expects you to practice this pattern.

### 2) Avoiding ambiguous base members
In multiple inheritance, you often must call base methods explicitly:

    ScavTrap::attack(target);
    ClapTrap::operator=(other);

Your code already demonstrates this well.

### 3) Clean output & readable behavior
The module is very output-driven: messages help the evaluator verify:
- object lifetime (construction/destruction order)
- correct overridden methods
- correct edge-case handling (no HP / no energy)

---

## Quick sanity checks you can do before evaluation

### ex00
- Attack consumes energy.
- Repair consumes energy.
- When energy is 0 → attack/repair prints “can’t”.
- When HP is 0 → attack/repair prints “can’t”.
- Copy and assignment keep the same state.

### ex01/ex02
- Derived stats are correct.
- `attack()` output differs from ClapTrap’s output.
- Special method prints correct message.

### ex03
- Only **one ClapTrap** exists (virtual inheritance).
- `whoAmI()` prints both names correctly.
- `attack()` uses ScavTrap’s version (no ambiguity).
- Construction/destruction order is visible.

---

## How to present this module during defense (simple explanation)

- “`ClapTrap` is the base entity with HP/EP/AD and basic actions.”
- “`ScavTrap` and `FragTrap` reuse the base behavior and adjust stats + add a feature.”
- “`DiamondTrap` combines both and demonstrates the diamond problem.”
- “I used **virtual inheritance** so there is only one ClapTrap base.”
- “`whoAmI()` demonstrates that DiamondTrap has its own name, and ClapTrap name is stored separately.”

---
