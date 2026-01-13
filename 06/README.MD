# C++ Module 06 — C++ casts

This module focuses on **explicit type conversions** and safe runtime type identification in C++.

Repository structure:
- `ex00/` — Scalar conversion (`ScalarConverter`)
- `ex01/` — Pointer serialization (`Serializer`)
- `ex02/` — Identify real type (`dynamic_cast`)

---

## Build

Each exercise has its own `Makefile`.

### Compile
~~~bash
make
~~~

### Clean object files
~~~bash
make clean
~~~

### Full clean (objects + binary)
~~~bash
make fclean
~~~

### Rebuild
~~~bash
make re
~~~

> Note: The module is expected to compile with `-Wall -Wextra -Werror` and remain compatible with `-std=c++98`.

---

## ex00 — Conversion of scalar types (ScalarConverter)

### Goal
Implement a `ScalarConverter` class that **cannot be instantiated** and exposes a single static method:

- `static void convert(const std::string& literal);`

It takes a string representation of a common C++ literal and prints its value as:
- `char`
- `int`
- `float`
- `double`

### Supported inputs
- **char**: `a`, `Z`, etc. (single character; non-displayable inputs are not expected)
- **int**: `0`, `-42`, `42`
- **float**: `0.0f`, `-4.2f`, `4.2f`
- **double**: `0.0`, `-4.2`, `4.2`

Pseudo-literals must be handled:
- float: `nanf`, `+inff`, `-inff`
- double: `nan`, `+inf`, `-inf`

### Output rules
- If conversion is impossible or overflows: print `impossible`
- For `char`:
  - If printable: `char: 'X'`
  - If not printable: `char: Non displayable`

Example (expected style):
~~~text
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
~~~

### Casting approach (what to explain on defense)
- Parsing: `std::strtod`
- Conversions: `static_cast<...>`
- Limits: `std::numeric_limits`
- Print formatting: fixed with one decimal (`std::fixed << std::setprecision(1)`)

---

## ex01 — Serialization (Serializer)

### Goal
Implement a `Serializer` class (not instantiable) with two static methods:

- `static uintptr_t serialize(Data* ptr);`
- `static Data* deserialize(uintptr_t raw);`

### Requirements
- `Data` must be a **non-empty struct** (has data members).
- `serialize()` converts a pointer to an integer type `uintptr_t`.
- `deserialize()` converts the integer back to a pointer.
- The restored pointer must compare equal to the original pointer.

### Casting approach
- Use `reinterpret_cast`:
  - `reinterpret_cast<uintptr_t>(ptr)`
  - `reinterpret_cast<Data*>(raw)`

---

## ex02 — Identify real type

### Goal
Create:
- `Base` class with **public virtual destructor only**
- Empty derived classes: `A`, `B`, `C` (public inheritance)

Implement:
- `Base* generate();`  
  Randomly creates `A`, `B`, or `C` and returns as `Base*`.

- `void identify(Base* p);`  
  Prints actual type: `A`, `B`, or `C`.

- `void identify(Base& p);`  
  Prints actual type: `A`, `B`, or `C`.  
  **Using a pointer inside this function is forbidden.**

Restrictions:
- `std::typeinfo` / including `<typeinfo>` is forbidden.

### Casting approach
- `identify(Base* p)`:
  - `dynamic_cast<A*>(p)` / `dynamic_cast<B*>(p)` / `dynamic_cast<C*>(p)`

- `identify(Base& p)`:
  - Use reference casts with `dynamic_cast<A&>(p)` inside `try/catch`
  - If it throws → not that type → try the next

---

## Common notes

- No memory leaks (delete what you `new`).
- Keep classes clean and readable.
- Avoid forbidden functions and features per module rules.

---
