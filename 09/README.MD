# C++ Module 09 — STL

This module contains three small programs that practice **STL containers**, **parsing/validation**, and **algorithmic thinking**.

## Project layout

~~~text
cpp_module_09/
├── ex00/ # btc
├── ex01/ # RPN
└── ex02/ # PmergeMe
~~~

Each exercise has its own `Makefile` and produces a single executable.

> **Container rule (Module 09):** once a container is used for an exercise, it should not be reused in the rest of the module.  
> This project follows that idea with:
> - `ex00`: `std::map`
> - `ex01`: `std::stack`
> - `ex02`: `std::vector` + `std::deque`

---

## Build

Go into an exercise directory and run:

~~~bash
make
~~~

Useful Makefile rules:

~~~bash
make        # build
make clean  # remove .o
make fclean # remove .o + binary
make re     # rebuild
~~~

---

## Exercise 00 — Bitcoin Exchange (`btc`)

### Goal

Compute the value of a given amount of bitcoin for a given date using a CSV database (`data.csv`).

- Program name: `btc`
- Takes **one file** as argument
- Input file lines follow: `date | value`
- Date format: `YYYY-MM-DD`
- Value: positive integer or float in range `[0..1000]`
- If the input date does not exist in the DB, use the **closest lower date** available.

### Files

- `main.cpp`
- `BitcoinExchange.cpp`
- `BitcoinExchange.hpp`
- `Makefile`
- `data.csv` (must be present at runtime)

### How it works (high level)

- Loads `data.csv` into `std::map<std::string, double>`.
- For each input line:
  - validates date format and calendar correctness
  - validates numeric value and range
  - finds the exchange rate using `map.lower_bound()` and falls back to the closest earlier date

### Usage

~~~bash
./btc input.txt
~~~

Example `input.txt`:

~~~text
date | value
2011-01-03 | 3
2011-01-03 | 1.2
2012-01-11 | 1
~~~

Output format:

~~~text
YYYY-MM-DD => value = value*rate
~~~

Typical errors (printed to stderr):

- `Error: could not open file.`
- `Error: bad input => <line or date>`
- `Error: not a positive number.`
- `Error: too large a number.`

---

## Exercise 01 — Reverse Polish Notation (`RPN`)

### Goal

Evaluate an **inverted Polish** (RPN) mathematical expression.

- Program name: `RPN`
- Takes **one string argument** (the expression)
- Supported operators: `+ - * /`
- No brackets, no decimals required
- On any error: print `Error` to **stderr**

### Files

- `main.cpp`
- `RPN.cpp`
- `RPN.hpp`
- `Makefile`

### How it works (high level)

- Tokenizes the input by spaces.
- Pushes digits (`0..9`) to a `std::stack<int>`.
- On operator: pops two numbers, applies operation, pushes result back.
- Final stack must contain exactly one value.

### Usage

~~~bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
~~~

Output:

~~~text
42
~~~

---

## Exercise 02 — PmergeMe (`PmergeMe`)

### Goal

Sort a sequence of **positive integers** using a **merge-insert sort** approach (Ford–Johnson / merge-insertion requirement in the subject), and compare timing between two containers.

- Program name: `PmergeMe`
- Takes a sequence of positive integers as arguments
- Prints:
  1) `Before: ...`
  2) `After:  ...`
  3) time for the first container
  4) time for the second container
- Must be able to handle at least **3000** integers

### Files

- `main.cpp`
- `PmergeMe.cpp`
- `PmergeMe.hpp`
- `Makefile`

### Containers used

- `std::vector<unsigned int>` and `std::deque<unsigned int>`

### Usage

~~~bash
./PmergeMe 3 5 9 7 4
~~~

Example output (timings will differ):

~~~text
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector : ...
Time to process a range of 5 elements with std::deque : ...
~~~

Error cases (prints `Error` to stderr), e.g.:

- non-digit tokens
- zero or negative values
- values exceeding `INT_MAX`

Duplicates handling is left to the implementer’s discretion.

---

## Notes

- Each exercise is self-contained and built from its own folder.
- No external libraries are used; only the C++ standard library.
- Ensure `data.csv` is available for `ex00` at runtime (commonly placed inside `ex00/`).

