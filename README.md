# Quadratic Equation - C++

A C++ class that models a quadratic equation of the form:

```
A·X² + B·X + C = 0
```

The class manages its own roots internally, recalculating them whenever a coefficient changes, and supports arithmetic between equations and scalars.

## Concepts demonstrated

- Operator overloading (`+`, `<<`, member and non-member/friend forms)
- Rule of Three & Rule of Five (copy constructor, move constructor, copy assignment, move assignment, destructor)
- Dynamic memory management (manual `new[]` / `delete[]`, no leaks, no double-free)
- Const-correctness
- Exception safety (`std::invalid_argument` thrown on invalid state, with no resource leaks on the throwing path)
- `noexcept` usage on the move constructor and move assignment operator

## Features

- Computes the equation's roots from the discriminant:
  - 2 real roots if the discriminant is positive
  - 1 real root if the discriminant is zero
  - 0 real roots if the discriminant is negative
- Roots are automatically recalculated whenever `a`, `b`, or `c` is changed via the setters
- Supports:
  - `Equation + Equation` → adds coefficients term by term
  - `Equation + double` and `double + Equation` → adds to the `c` term
  - `std::cout << equation` → prints in the form `A.A X^2 + B.B X + C.C = 0`
- Throws `std::invalid_argument` if `a` is ever set to `0` (via constructor, `set_a`, or as the result of an addition) — a quadratic equation cannot have `a = 0`

## Example

```cpp
#include"Equation.hpp"

int main() {
    Equation eq(1, 3, -4);
    std::cout << eq << std::endl;              // 1.0 X^2 + 3.0 X + -4.0 = 0
    std::cout << eq.get_solutions_size();      // 2
    std::cout << eq.get_solutions()[0];        // 1.0
    std::cout << eq.get_solutions()[1];        // -4.0

    Equation sum = Equation(1, 5, 3) + Equation(2, 6, 4);
    std::cout << sum << std::endl;             // 3.0 X^2 + 11.0 X + 7.0 = 0
}
```

## Build

```bash
g++ *.cpp -Wall -Wextra -Weffc++ -std=c++14 -pedantic -o program
```

Compiles with zero warnings under this flag set.

## Files

| File | Description |
|---|---|
| `Equation.hpp` | Class declaration |
| `Equation.cpp` | Class implementation |
