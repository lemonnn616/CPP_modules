# C++ Module 07 — Templates

This module introduces **C++ templates** through three exercises:
- `ex00`: basic function templates (`swap`, `min`, `max`)
- `ex01`: template function `iter` applying a function to each array element
- `ex02`: template class `Array<T>` with deep copy and bounds checking

---

## Project structure

```text
.
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   └── whatever.hpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   └── iter.hpp
└── ex02/
    ├── Makefile
    ├── main.cpp
    ├── Array.hpp
    └── Array.tpp
```

---

## Build & run

Each exercise has its own Makefile.

### Common commands

- Build:
  - `make`
- Clean objects:
  - `make clean`
- Full clean (objects + binary):
  - `make fclean`
- Rebuild:
  - `make re`
- Run:
  - `./<binary_name>`

---

## Exercise 00 — `whatever`

**Goal:** Implement function templates:
- `swap(T&, T&)`
- `min(const T&, const T&)` — returns the smallest; **if equal, returns the second**
- `max(const T&, const T&)` — returns the greatest; **if equal, returns the second**

**Files:**
- `whatever.hpp` (templates must be in the header)
- `main.cpp`
- `Makefile`

### Run

```bash
cd ex00
make
./templates
```

### Notes
- `min/max` require the type to support comparison operators.
- You can test with `int`, `std::string`, and your own structs (if you define comparisons).

---

## Exercise 01 — `iter`

**Goal:** Implement a function template `iter`:
- takes an array pointer
- takes the array length (as a const value)
- takes a function called for each element

The callback may accept:
- `T&` for non-const arrays
- `const T&` for const arrays

**Files:**
- `iter.hpp` (template in header)
- `main.cpp`
- `Makefile`

### Run

```bash
cd ex01
make
./iter
```

### Notes
- Common approach: provide **two overloads**:
  - one for `T*` + `void (*)(T&)`
  - one for `const T*` + `void (*)(const T&)`

---

## Exercise 02 — `Array`

**Goal:** Implement a class template `Array<T>` that:
- can be default-constructed as an **empty array**
- can be constructed with `unsigned int n` as a **size**
- supports **deep copy** (copy ctor and assignment)
- allocates with `new[]` (no “preventive allocation”)
- provides `operator[]` with **bounds checking**
  - out-of-bounds access must throw an `std::exception`
- provides `size()` that returns the number of elements

**Files:**
- `Array.hpp`
- `Array.tpp` (optional but recommended for template implementation)
- `main.cpp`
- `Makefile`

### Run

```bash
cd ex02
make
./array
```

### Notes
- Copying must be **independent**: modifying the copy must not affect the original.
- `operator[]` must work for both:
  - `Array<T>` (returns `T&`)
  - `const Array<T>` (returns `const T&`)
- Always free memory with `delete[]` in the destructor.

---

## Testing tips

- For `ex00`: check correctness for equal values (must return the **second** in `min/max`).
- For `ex01`: test both mutable and const arrays; test with different element types.
- For `ex02`: test:
  - empty arrays
  - deep copy behavior
  - assignment operator self-assignment
  - out-of-bounds exceptions on both const/non-const arrays

---

## Important requirements

- Templates must be defined in headers (`.hpp` / `.h`) or included `.tpp` files.
- Follow the required file names and directories (`ex00`, `ex01`, `ex02`).
- Make sure `make`, `make clean`, `make fclean`, `make re` work as expected.

---
