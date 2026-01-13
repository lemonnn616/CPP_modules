# 42 C++ Modules — CPP00 → CPP09 (Overview)

A single repository-style README that documents the whole **Piscine C++ / C++ Modules** journey from **CPP00** to **CPP09**.

This project set is designed to progressively build real C++ fundamentals:
- OOP (classes, encapsulation, inheritance, polymorphism)
- canonical form (copy/assignment/destructor)
- memory management and deep copies
- exceptions and RAII thinking
- templates and generic programming
- STL containers + algorithms + parsing

> This README is a **global index**. Each module (and each exercise) can still have its own local README if you want, but this file is meant to be the “main entry point”.

---

## Repository structure

A common layout looks like this:

~~~
CPP00/
  ex00/
  ex01/
  ex02/
CPP01/
  ex00/
  ex01/
  ...
...
CPP09/
  ex00/
  ex01/
  ex02/
~~~

Inside each exercise folder you typically have:
- `Makefile`
- `main.cpp`
- implementation files (`*.cpp`)
- headers (`*.hpp`)
- sometimes runtime files (e.g. `data.csv`)

---

## Build & run (general)

Go into an exercise directory and use:

~~~
make
./<program> [args...]
~~~

Standard Makefile targets (expected everywhere):

~~~
make        # compile
make clean  # remove object files (*.o)
make fclean # clean + remove binary
make re     # rebuild
~~~

### Compiler flags
Most 42 C++ modules historically use **C++98**, but some students/versions use **C++11** in later modules.
Always follow your local `Makefile`:
- `-Wall -Wextra -Werror`
- `-std=c++98` or `-std=c++11`

---

## Coding rules & habits (recommended)

### Canonical form (Rule of Three)
Whenever a class manages resources (heap memory, file handles, etc.), implement:
- copy constructor
- copy assignment operator
- destructor

And don’t forget the default constructor if it makes sense.

### RAII mindset
If you `new`, you must `delete` (or use ownership structures that delete for you).
Avoid leaks and double frees. Prefer safe ownership patterns.

### Const correctness
Use `const` for getters and for read-only parameters:
- `const std::string&`
- `T const&`
- `method() const`

### Keep outputs readable
These modules are often validated by output behavior:
- clear messages
- consistent formatting
- correct error printing

---

# Module-by-module summary

## CPP00 — Basics of C++ / Classes / I/O

**Core topics**
- namespaces, streams (`std::cout`, `std::cerr`)
- basic classes and headers
- `static` members
- simple formatting and input handling

**Typical exercises**
- `ex00`: “Megaphone” (basic argv + formatting)
- `ex01`: “PhoneBook” (small CLI app, arrays, input validation)
- `ex02`: “Account” (static counters, class design)

**What you learn**
- how to structure a tiny program into `.hpp/.cpp`
- how to handle user input reliably
- how to design a small class API

---

## CPP01 — Memory, References, File I/O

**Core topics**
- stack vs heap
- pointers and references
- `new/delete`
- file streams (`std::ifstream`, `std::ofstream`)
- simple string manipulation

**Typical exercises**
- zombies / allocation practice
- references vs pointers (`HumanA/HumanB`, `Weapon`)
- file replace program (read → transform → write)
- simple logger / complaint systems (Harl)

**What you learn**
- ownership and lifetime
- avoiding leaks
- safe file parsing and rewriting

---

## CPP02 — Operator Overloading / Fixed-point / Canonical form

**Core topics**
- Orthodox Canonical Form (Rule of Three)
- operator overloading (`+ - * /`, comparisons, `<<`)
- fixed-point representation
- immutability patterns

**Typical exercises**
- `Fixed` class + arithmetic and comparisons
- point/barycentric logic (BSP)
- correctness under copying/assignment

**What you learn**
- designing value types properly
- writing clean overloads without surprises

---

## CPP03 — Inheritance (ClapTrap family)

**Core topics**
- inheritance basics
- protected vs private
- method overriding
- constructor chaining

**Typical exercises**
- `ClapTrap`
- `ScavTrap`
- `FragTrap`
- `DiamondTrap` (+ multiple inheritance issues)

**What you learn**
- how base/derived construction works
- how to avoid ambiguity in multiple inheritance
- how and when to override behavior

---

## CPP04 — Polymorphism / Abstract classes / Interfaces

**Core topics**
- virtual functions + dynamic dispatch
- destructors must be `virtual` in polymorphic bases
- deep copy vs shallow copy (heap members)
- abstract classes and pure virtual methods
- interface-style design (`IMateriaSource`, `ICharacter`)

**Typical exercises**
- `Animal`, `Dog`, `Cat`
- `WrongAnimal` example (what happens without virtual)
- `Brain` as a heap resource → deep copy required
- Materia system (`AMateria`, `Ice`, `Cure`, characters and source)

**What you learn**
- real OOP polymorphism
- safe destruction through base pointers
- implementing deep copies correctly

---

## CPP05 — Exceptions / Bureaucracy forms

**Core topics**
- exceptions (`try/catch`, custom exception classes)
- invariant enforcement (grade must be within range)
- object interaction and responsibility splitting
- more complex class graphs

**Typical exercises**
- `Bureaucrat` with grade rules + exceptions
- `Form` / `AForm` with signing and execution requirements
- concrete forms:
  - `ShrubberyCreationForm`
  - `RobotomyRequestForm`
  - `PresidentialPardonForm`
- `Intern` factory that creates forms by string name

**What you learn**
- using exceptions to enforce class invariants
- clean error messages and robust flows
- factory pattern basics

---

## CPP06 — Casting / RTTI / Serialization

**Core topics**
- `static_cast`, `reinterpret_cast`, `dynamic_cast`
- converting scalar literals safely
- RTTI type identification
- pointer <-> integer serialization

**Typical exercises**
- `ScalarConverter`: print literal as `char`, `int`, `float`, `double`
- `Serializer`: `Data*` ↔ `uintptr_t`
- `identify`: detect actual derived type via RTTI (`dynamic_cast`)

**What you learn**
- when each cast is appropriate
- handling edge cases (`nan`, `inf`, non-displayable chars)
- safe RTTI usage patterns

---

## CPP07 — Templates

**Core topics**
- function templates
- class templates
- template separation (`.hpp` + `.tpp`)
- generic programming constraints (operators required by types)

**Typical exercises**
- `whatever`: `swap`, `min`, `max`
- `iter`: apply function to each element in an array
- `Array<T>`: bounds-checked dynamic array template

**What you learn**
- writing reusable code without losing type safety
- template compilation model (headers must contain definitions)

---

## CPP08 — STL Containers / Algorithms

**Core topics**
- iterators and algorithms (`std::find`, `std::sort`, etc.)
- container constraints and efficiency
- exception-based error handling in algorithms

**Typical exercises**
- `easyfind`: generic search in container
- `Span`: store numbers, compute shortest/longest span
- `MutantStack`: iterable stack adapter

**What you learn**
- writing generic functions over containers
- algorithmic thinking (sorting + min diff)
- adapting STL structures cleanly

---

## CPP09 — Advanced STL / Parsing / Algorithmic tasks

**Core topics**
- parsing and validation (robust input handling)
- ordered maps and lookup strategies
- stack-based expression evaluation
- performance measurement and container comparison

**Exercises**
- `btc` (BitcoinExchange): date/value parsing, map lookup with closest earlier date
- `RPN`: Reverse Polish Notation evaluation using a stack
- `PmergeMe`: merge-insert style sorting + time comparison between containers

**What you learn**
- building strict parsers
- choosing correct containers for the job
- complexity tradeoffs and benchmarking

---

# Suggested testing checklist (all modules)

## Build checks
- `make` works with `-Wall -Wextra -Werror`
- `make re` rebuilds cleanly
- no leftover binaries after `make fclean`

## Runtime checks
- correct output formatting
- correct error messages on invalid input
- no crashes for edge cases

## Memory checks
Use valgrind where possible (Linux):

~~~
valgrind --leak-check=full --show-leak-kinds=all ./<program> [args]
~~~

Look for:
- “definitely lost” = leaks
- invalid reads/writes
- double free

---

# Quick navigation (recommended)

If you want a clean navigation summary in your repo root, keep modules named exactly:

~~~
CPP00  CPP01  CPP02  CPP03  CPP04  CPP05  CPP06  CPP07  CPP08  CPP09
~~~

And each module:

~~~
ex00  ex01  ex02 ... (depending on module)
~~~

This makes review/exam navigation easier and consistent.

---

## Notes

- Each module builds on previous ones; don’t skip the “boring” rules (const, copy, destructors).
- Most hidden tests target:
  - deep copy correctness
  - boundary checks and exceptions
  - invalid input behavior
  - leaks and destructor correctness

---

CPP00–CPP09
~~~
