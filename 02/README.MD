# CPP Module 02 (CPP02) — Fixed-point numbers, operator overloading, OCF

This module introduces:
- **Orthodox Canonical Form (OCF)** (a.k.a. “canonical class form”)
- **Fixed-point numbers** as a custom numeric type
- **Operator overloading** (comparisons, arithmetic, increments)
- A small geometry task (**BSP**) using the fixed-point class

The code is written for **C++98** and must compile with:
    c++ -Wall -Wextra -Werror -std=c++98

Repository layout (typical):
    ex00/
    ex01/
    ex02/
    ex03/

---

## Rules & constraints (quick checklist)

- Compile with `-Wall -Wextra -Werror` and stay compatible with `-std=c++98`.
- From Module 02 onward, classes must follow **Orthodox Canonical Form** unless stated otherwise.
- No `using namespace ...` and no `friend` (unless explicitly allowed).
- No STL until Modules 08/09 (so avoid `<algorithm>`, `vector`, etc. here).
- No function implementations in headers (except templates).
- Avoid memory leaks (if you use `new`, you must `delete`).

---

## Orthodox Canonical Form (OCF) refresher

A class in OCF implements these 4 member functions:

1) Default constructor  
2) Copy constructor  
3) Copy assignment operator  
4) Destructor  

This module’s classes are designed around that pattern so that copying/assigning is explicit and predictable.

---

## Exercise overview

### ex00 — “My First Class in Orthodox Canonical Form”
**Goal:** create a minimal `Fixed` class that stores a fixed-point value.

**What you implement**
- Private:
  - `int _rawBits;`
  - `static const int _fractionalBits = 8;`
- Public:
  - default ctor, copy ctor, copy assignment, dtor
  - `int getRawBits() const;`
  - `void setRawBits(int const raw);`

**Build & run**
    cd ex00
    make
    ./fixed

**Expected behavior**
- You see constructor/destructor logs and `getRawBits()` output (mostly zeros).
- The exercise is mostly about correct OCF wiring and copy semantics.

---

### ex01 — “Towards a more useful fixed-point number class”
**Goal:** add real numeric meaning to `Fixed`.

**Adds**
- Constructors:
  - `Fixed(int)`
  - `Fixed(float)`
- Conversions:
  - `float toFloat() const;`
  - `int toInt() const;`
- Output operator:
  - `operator<<` prints the **float representation** of the fixed-point number.

**Implementation idea (fixed-point)**
- Store values as `raw = real_value * (1 << fractionalBits)`.
- `toFloat()` returns `raw / (1 << fractionalBits)`.
- `toInt()` returns `raw >> fractionalBits`.

**Build & run**
    cd ex01
    make
    ./fixed

**Notes**
- Rounding is used when converting from float to the internal fixed representation.
- You should still see OCF-related logs (depending on your implementation).

---

### ex02 — “Now we’re talking” (operator overloading)
**Goal:** make `Fixed` behave like a numeric type.

**You overload**
- Comparisons:
  - `> < >= <= == !=`
- Arithmetic:
  - `+ - * /`
- Increment/Decrement:
  - `++a`, `a++`, `--a`, `a--`

**Important detail**
- Increment/decrement changes the value by the smallest representable epsilon:
  - `epsilon = 1 / 2^fractionalBits`
  - with `_fractionalBits = 8`, `epsilon = 1/256 = 0.00390625`

**Also add static helpers**
- `Fixed::min(a, b)` (mutable and const overloads)
- `Fixed::max(a, b)` (mutable and const overloads)

**Build & run**
    cd ex02
    make
    ./fixed

**Expected sample**
You should observe outputs similar to:
- `0`
- `0.00390625`
- `0.0078125`
- etc.

**Division by zero**
- If you divide by 0, it’s acceptable that the program crashes (per subject).

---

### ex03 — “BSP” (point inside triangle)
**Goal:** use your `Fixed` class for geometry.

You implement:
- `Point` class in OCF:
  - `Fixed const x;`
  - `Fixed const y;`
- A function:
  - `bool bsp(Point const a, Point const b, Point const c, Point const point);`

**Behavior**
- Returns `true` if `point` is strictly inside triangle `abc`
- Returns `false` if `point` is:
  - a vertex, or
  - on an edge, or
  - outside

**Approach used (area method)**
1) Compute triangle area `S(abc)`
2) Compute `S(pbc)`, `S(apc)`, `S(abp)`
3) If any of the smaller areas is 0 → point is on an edge → `false`
4) If `S(abc) == S(pbc) + S(apc) + S(abp)` → inside → `true`

**Build & run**
    cd ex03
    make
    ./bsp

---

## How to build everything quickly

From the CPP02 root:
    for d in ex00 ex01 ex02 ex03; do (cd "$d" && make); done

To clean:
    for d in ex00 ex01 ex02 ex03; do (cd "$d" && make fclean); done

---

## What reviewers often check

- OCF exists everywhere it’s required (constructors, assignment, destructor).
- No header-only implementations (except templates; not needed here).
- Correct operator overload signatures (especially prefix vs postfix).
- `operator<<` prints a float-like value (not raw bits).
- `Point` has `const Fixed` members and assignment is handled safely.
- `bsp()` returns false on edges/vertices (strict inside only).
- Code compiles with `-std=c++98` + required flags.

---

## Common pitfalls

- Mixing float math everywhere instead of relying on fixed-point conversions.
- Post-increment returning the updated value instead of the previous copy.
- Returning references to temporaries in `min/max`.
- Forgetting `const` correctness (especially in comparison operators and getters).
- Implementing methods in `.hpp` (can fail evaluation rules).
- Not handling `Point` assignment properly with `const` members (assignment may be a no-op by design).

---

## Makefile targets (per exercise)

- `make` / `make all` — build the executable
- `make clean` — remove `.o` files
- `make fclean` — remove `.o` files + executable
- `make re` — rebuild from scratch (fclean + all)

---

## Summary

CPP02 builds a real numeric type (`Fixed`) in C++98:
- Ex00: OCF + raw storage
- Ex01: int/float conversion + stream output
- Ex02: operators + epsilon increments + min/max
- Ex03: geometry with `Point` + `bsp()` strict-inside test
