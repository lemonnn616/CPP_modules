# C++ Module 05 — Repetition and Exceptions

This repository contains my solutions for **42 C++ Module 05**, focused on **exceptions**, **repetition**, and **class interactions** (Bureaucrats and Forms). :contentReference[oaicite:1]{index=1}

---

## Overview

Module 05 introduces an “office bureaucracy” mini-world to practice:
- Exception handling and custom exception types
- Rule of Three / Orthodox Canonical Form (when required)
- Const correctness and grade-bound constraints
- Operator overloading (`operator<<`)
- Abstract base classes and polymorphism (forms)
- Execution preconditions (signed + sufficient grade)

Directory layout:
- `ex00/` — Bureaucrat
- `ex01/` — Bureaucrat + Form (signing)
- `ex02/` — Bureaucrat + AForm (abstract) + concrete forms (execution)
- `ex03/` — Intern (factory that creates forms)

---

## Requirements (subject)

- Compile with `-Wall -Wextra -Werror`
- Must still compile with `-std=c++98` (as required by the C++ modules) :contentReference[oaicite:2]{index=2}
- No external libraries

---

## How to Build and Run

Each exercise is independent. Go into its folder and run `make`.

### ex00 — Bureaucrat

```bash
cd ex00
make
./bureaucrat
```

### ex01 — Form signing

```bash
cd ex01
make
./bureaucrat
```

### ex02 — Abstract forms + execution

```bash
cd ex02
make
./bureaucrat
```

### ex03 — Intern creates forms

```bash
cd ex03
make
./bureaucrat
```

---

## Makefile Targets

```bash
make        # build
make clean  # remove .o files
make fclean # remove .o files + binaries
make re     # full rebuild
```

---

## Exercises

## ex00 — “Mommy, when I grow up, I want to be a bureaucrat!”

Implements `Bureaucrat`:
- **name** is constant
- **grade** is in range **[1..150]** (1 is the highest)
- `incrementGrade()` / `decrementGrade()` adjust grade with boundary checks
- Throws:
  - `Bureaucrat::GradeTooHighException`
  - `Bureaucrat::GradeTooLowException`
- Overloads `operator<<`:
  - `<name>, bureaucrat grade <grade>.`

Key idea: **construction and mutation must both enforce the same constraints**.

---

## ex01 — “Form up, maggots!”

Adds `Form`:
- Constant name
- Boolean `signed` state (starts as `false`)
- Constant grade required to sign
- Constant grade required to execute
- Throws:
  - `Form::GradeTooHighException`
  - `Form::GradeTooLowException`

Adds:
- `Form::beSigned(Bureaucrat const&)`
  - Signs if bureaucrat grade is high enough
  - Otherwise throws `Form::GradeTooLowException`
- `Bureaucrat::signForm(Form&)`
  - Attempts to sign and prints success/failure message

Key idea: **Bureaucrat and Form communicate via exceptions**.

---

## ex02 — “No, you need form 28B, not 28C...”

Upgrades the base form:
- `Form` becomes **abstract** and is renamed **`AForm`**
- Adds **execution**:
  - `AForm::execute(Bureaucrat const& executor) const` (pure virtual in base, implemented behavior split between base + derived, depending on design)
  - Execution requires:
    1) form is signed
    2) executor grade is high enough  
  - Otherwise throws an appropriate exception

Concrete forms:
- **ShrubberyCreationForm**  
  - sign: 145, exec: 137  
  - creates `<target>_shrubbery` file and writes ASCII trees
- **RobotomyRequestForm**  
  - sign: 72, exec: 45  
  - “drilling noises”, 50% success rate
- **PresidentialPardonForm**  
  - sign: 25, exec: 5  
  - prints that `<target>` was pardoned by Zaphod Beeblebrox

Also adds:
- `Bureaucrat::executeForm(AForm const&)`
  - Attempts execution and prints success/failure

Key idea: **polymorphism + shared validation logic** (signed + grade checks).

---

## ex03 — “At least this beats coffee-making”

Implements `Intern` with:
- `AForm* makeForm(std::string const& formName, std::string const& target)`
  - Creates the correct concrete form based on `formName`
  - Prints: `Intern creates <form>`
  - If name is unknown, prints an explicit error message

Important note from subject: avoid unreadable “huge if/else chains”; use a clean mapping approach. :contentReference[oaicite:3]{index=3}

Key idea: **factory pattern** (creating objects by string key).

---

## Notes

- Grades: **1 is the best**, **150 is the worst**.
- Exceptions are used to signal invalid state transitions:
  - invalid construction grade
  - increment/decrement out of range
  - signing/executing with insufficient grade
  - executing unsigned forms
- Memory management matters when creating forms dynamically.

---

## Example Output

The exact output depends on the tests in `main.cpp`, but you should see:
- Bureaucrats being created with grades
- Exceptions caught at grade boundaries (e.g., incrementing grade 1)
- Signing success/failure with reasons
- Form execution success/failure with reasons
- Intern creating different forms by name

---
