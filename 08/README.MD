# C++ Module 08 — Templated Containers, Iterators, Algorithms

This repository contains my solutions for **C++ Module 08** (42/Codam): using STL containers, iterators, and algorithms.

## Requirements

- Compiler: `c++`
- Flags: `-Wall -Wextra -Werror`
- Standard:
  - The official subject expects **C++98 compatibility** (your code should still compile with `-std=c++98` when added).
  - This repo may use **C++11** conveniences in places (e.g., `auto`, range-based loops). If you want strict C++98 compliance, remove C++11-only features and switch the Makefiles accordingly.

## Project Structure

```
.
├── ex00/   # Easy find
├── ex01/   # Span
└── ex02/   # MutantStack (iterable std::stack)
```

Each exercise directory contains its own `Makefile` and a small `main.cpp` for testing.

## How to Build

Go into an exercise directory and run:

```bash
make
```

Useful Makefile targets:

```bash
make clean      # remove .o files
make fclean     # remove .o files + binary
make re         # full rebuild
```

## Exercises

### ex00 — Easy find

**Goal:** Write a function template `easyfind` that searches for the first occurrence of an `int` inside a container of integers.

- Uses `std::find` internally.
- Returns an iterator to the found element.
- Throws an exception (e.g., `std::out_of_range`) if not found.
- You don’t need to handle associative containers.

**Run:**
```bash
cd ex00
make
./easyfind
```

---

### ex01 — Span

**Goal:** Implement a `Span` class that can store up to **N integers**.

Mandatory features:
- `addNumber(int)` — adds one number; throws if full.
- `shortestSpan()` — minimal distance between two stored numbers; throws if less than 2 elements.
- `longestSpan()` — maximal distance; throws if less than 2 elements.

Bonus/strongly recommended:
- Add multiple numbers using an iterator range (so you can easily test with **10,000+** values).

**Run:**
```bash
cd ex01
make
./span
```

---

### ex02 — MutantStack

**Goal:** Make `std::stack` iterable.

Implement `MutantStack`:
- Built on top of `std::stack`.
- Exposes iterators (`begin()`, `end()`, and optionally reverse iterators).
- Keeps regular stack behavior (`push`, `pop`, `top`, `size`, ...).

**Run:**
```bash
cd ex02
make
./mutantstack
```

## Notes

- Always avoid memory leaks when using `new`.
- Prefer STL algorithms/containers where appropriate (this is the purpose of Module 08).
- Keep outputs readable and end lines with `\n`.

---

