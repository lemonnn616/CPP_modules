# CPP Module 01 (C++98)

**CPP Module 01** is part of the 42 / Codam C++ curriculum.  
This module focuses on **memory allocation**, **references**, **pointers**, **basic class design**, **file I/O**, **pointers to member functions**, and using **switch** for control flow.

Each exercise is self-contained (its own folder + Makefile) and is compiled with:

- `-Wall -Wextra -Werror -std=c++98`

---

## ✅ What’s inside

This module typically contains the following exercises:

- **ex00 — BraiiiiiiinnnzzzZ** (stack vs heap allocation)
- **ex01 — Moar brainz!** (arrays with `new[]` / `delete[]`)
- **ex02 — HI THIS IS BRAIN** (pointers vs references)
- **ex03 — Unnecessary violence** (reference vs pointer member)
- **ex04 — Sed is for losers** (file I/O + string replacement)
- **ex05 — Harl 2.0** (pointers to member functions)
- **ex06 — Harl filter** (switch + fall-through logic)

> Note: Names of executables and folder structure depend on your repository layout, but the logic and goals match the module requirements.

---

## 🧱 Build & Run

Go into any exercise directory and run `make`.

Example:
    
    cd ex00
    make
    ./zombie

Cleanup:

    make clean
    make fclean
    make re

All exercises are designed to run **without external dependencies**.

---

## ex00 — BraiiiiiiinnnzzzZ

### Goal
Understand when it makes sense to allocate objects on the **stack** vs the **heap**.

### Key parts
- `Zombie` class with:
  - private `std::string _name`
  - `announce()` method printing:
    - `<name>: BraiiiiiiinnnzzzZ...`
  - destructor prints debug message when zombie is destroyed

- `Zombie* newZombie(std::string name)`
  - allocates a Zombie on the heap (`new`) and returns it

- `void randomChump(std::string name)`
  - creates a Zombie on the stack and immediately calls `announce()`

### Typical run
- Create heap zombie → `delete` it
- Create stack zombie → auto-destroyed when leaving scope

### What this teaches
- Heap lifetime is manual → you must `delete`
- Stack lifetime is automatic → destroyed at end of scope
- Destructors help verify correct memory handling

---

## ex01 — Moar brainz!

### Goal
Allocate **N objects in one allocation** using `new[]` and free them with `delete[]`.

### Core function
`Zombie* zombieHorde(int N, std::string name);`

Requirements:
- Allocate an array of `N` zombies in a **single** allocation
- Initialize each zombie with a name (often `name #i`)
- Return pointer to the first zombie
- Free the entire array using:
  - `delete[] horde;`

### What this teaches
- `new[]` vs `new`
- `delete[]` vs `delete`
- initializing objects after default construction
- avoiding leaks when managing dynamic arrays

---

## ex02 — HI THIS IS BRAIN

### Goal
Demystify **references** by comparing them with pointers.

Program must create:
- `std::string brain = "HI THIS IS BRAIN";`
- `std::string* stringPTR = &brain;`
- `std::string& stringREF = brain;`

Then print:
- addresses:
  - address of `brain`
  - pointer value (`stringPTR`)
  - address of `stringREF`
- values:
  - `brain`
  - `*stringPTR`
  - `stringREF`

### What this teaches
- A reference is another name for the same object (cannot be null)
- A pointer stores an address (can be null, can be reassigned)
- Both can access the same underlying object

---

## ex03 — Unnecessary violence

### Goal
Understand when to use a **reference** vs a **pointer** as a class member.

### Classes
#### `Weapon`
- has `std::string _type`
- `getType()` returns `const std::string&`
- `setType(std::string)`

#### `HumanA`
- always has a weapon → stores a **reference**
  - `Weapon& _weapon;`
- must receive weapon in constructor

#### `HumanB`
- may or may not have weapon → stores a **pointer**
  - `Weapon* _weapon;`
- can be constructed without weapon
- `setWeapon()` assigns the pointer
- `attack()` must handle “no weapon” case

### Why reference for HumanA?
Because HumanA is guaranteed to always be armed. A reference:
- cannot be null
- must be initialized immediately

### Why pointer for HumanB?
Because HumanB may start unarmed. A pointer:
- can be null
- can be set later

---

## ex04 — Sed is for losers

### Goal
Work with file streams and string processing, without using C file functions.

Program:
    
    ./replace <filename> <s1> <s2>

Behavior:
- opens `<filename>`
- writes output into `<filename>.replace`
- replaces every occurrence of `s1` with `s2`

Constraints:
- C file functions are forbidden
- `std::string::replace` is forbidden
- must handle errors:
  - bad args
  - file can't open
  - empty file
  - empty `s1` (commonly treated as invalid)

### What this teaches
- `std::ifstream` / `std::ofstream`
- robust argument validation
- reading line by line using `std::getline`
- manual substring replacement using:
  - `find`, `substr`, `append`, etc.

---

## ex05 — Harl 2.0

### Goal
Use **pointers to member functions** to dispatch behavior without a huge if/else chain.

`Harl` has methods:
- `debug()`
- `info()`
- `warning()`
- `error()`

And one public method:

    void complain(std::string level);

Implementation idea:
- array of strings:
  - `{"DEBUG","INFO","WARNING","ERROR"}`
- array of member function pointers:
  - `&Harl::debug`, etc.
- find matching level and call the corresponding method:
  - `(this->*functions[i])();`

### What this teaches
- member function pointers syntax
- mapping strings to behavior cleanly
- avoiding repetitive conditional logic

---

## ex06 — Harl filter

### Goal
Filter logs: print messages from a given level and above.

Run:

    ./harlFilter <level>

Expected behavior:
- If level is:
  - `DEBUG` → prints DEBUG, INFO, WARNING, ERROR
  - `INFO`  → prints INFO, WARNING, ERROR
  - `WARNING` → prints WARNING, ERROR
  - `ERROR` → prints ERROR only
- Otherwise prints a default message

This exercise is commonly solved with:
- `switch` on an index
- intentional **fall-through** (no `break` until the end)

### What this teaches
- `switch` structure
- fall-through logic
- clean filtering behavior

---

## 🧠 What I learned (module takeaways)

- Difference between **stack allocation** and **heap allocation**
- Proper use of `new` / `delete` and `new[]` / `delete[]`
- How **references** differ from pointers
- Designing classes based on invariants (always-has vs optional-has)
- File I/O using C++ streams
- Implementing safe string replacement without forbidden calls
- Using **pointers to member functions** for clean dispatch
- Using **switch** + fall-through for filtered output

---

## 🔎 Quick tips for evaluation

- Always match `new` with `delete` and `new[]` with `delete[]`
- Destructors are useful for verifying correct lifetime handling
- Don’t forget to handle invalid inputs and edge cases (especially in ex04/ex06)
- Keep output formatting consistent (each message ends with `\n`)
- Make sure each exercise builds with `-std=c++98`

---
