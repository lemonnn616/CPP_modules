# CPP Module 00

**CPP00** is the first module of the 42 / Codam C++ curriculum.  
The goal is to get comfortable with **C++98 basics**: iostreams, classes, member functions, simple formatting, and static class state.

This module contains 3 exercises:
- `ex00` — **Megaphone** (CLI + uppercase conversion)
- `ex01` — **PhoneBook** (basic classes + fixed-size storage)
- `ex02` — **Account** (static members + timestamped logs)

---

## ✅ Build rules

All exercises compile with:

- `c++ -Wall -Wextra -Werror -std=c++98`

Each exercise contains its own Makefile with the usual targets:

    make
    make clean
    make fclean
    make re

---

## 📢 ex00 — Megaphone

### Goal
Print all provided arguments in **uppercase**.

### Behavior
- If no arguments are provided, print:

    * LOUD AND UNBEARABLE FEEDBACK NOISE *

- Otherwise, print all arguments concatenated and uppercased.

### Build & run

    cd ex00
    make
    ./megaphone "shhhhh... I think the students are asleep..."
    ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
    ./megaphone

Implementation notes:
- Uses `std::toupper()` and prints via `std::cout`.

---

## 📞 ex01 — PhoneBook

### Goal
Implement a small interactive phonebook without dynamic allocation.

### Program
The executable is:

- `phonebook`

### Commands
At runtime, the program accepts:

- `ADD` — create a new contact (all fields must be non-empty)
- `SEARCH` — print a table of contacts and show one by index
- `EXIT` — quit the program

The program also handles `EOF` (Ctrl+D) cleanly.

### Data model
- `PhoneBook` stores up to **8** contacts in a fixed array.
- When adding more than 8, it **overwrites the oldest** (circular behavior).
- `Contact` stores:
  - first name
  - last name
  - phone number
  - age

### SEARCH table formatting
The contact list is displayed as a table with columns width **10** using `std::setw`:
- `Index`
- `First Name`
- `Last Name`
- `Phone Num.`

If a field is longer than 10 characters, it is truncated to 9 characters + `.`.

### Build & run

    cd ex01
    make
    ./phonebook

---

## 🏦 ex02 — Account

### Goal
Recreate the behavior of a banking system using a class with **static state**.

### Program
The executable is:

- `account`

It is built from:

- `Account.cpp`
- `tests.cpp`
- `Account.hpp`

### What it demonstrates
- Static counters shared by all instances:
  - number of accounts
  - total amount
  - total deposits / withdrawals
- Per-account state:
  - index
  - balance
  - number of deposits / withdrawals
- Timestamped output in the format:

    [YYYYMMDD_HHMMSS] ...

### Expected output
Running `./account` should match the provided reference log format (timestamps will differ, but the structure and values should match).

### Build & run

    cd ex02
    make
    ./account

---

## 🧠 What I learned

- Writing C++98 programs using iostreams instead of C-style I/O
- Basic class design (encapsulation with getters/setters)
- Fixed-size storage and simple ring buffer logic
- Formatting CLI output with `iomanip`
- Using static class members to keep global state consistent
