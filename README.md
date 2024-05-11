# ComplexCalculator

This repository contains implementations of complex number operations in both Python (`Complex.py`) and C++ (`complex.cpp`).

## Usage

- **Python**: Run `Complex.py` to perform various complex number calculations and conversions. The script provides a menu-driven interface for easy interaction.

- **C++**: Compile and run `complex.cpp` to perform complex number operations in C++. The program also offers a menu-based interface similar to the Python script.

## Features

- Calculate modulus and argument of complex numbers
- Perform addition, subtraction, multiplication, division, and exponentiation of complex numbers
- Convert complex numbers between rectangular and polar forms

## Python Usage Example

```python
from Complex import Complex

# Create a complex number
z = Complex(3, 4, disp=True)

# Calculate modulus
mod = z.mod()
print(f"Modulus: {mod}")

# Calculate argument in degrees
arg_deg = z.arg('d').b[0]
print(f"Argument (degrees): {arg_deg}")

# Calculate conjugate
conj = z.conjg()
print(f"Conjugate: {conj}")

# Calculate reciprocal
reci = z.reci()
print(f"Reciprocal: {reci}")

# Convert to polar form
pol = z.pol()
print(f"Polar form: {pol}")

# Convert to rectangular form
rec = z.rec()
print(f"Rectangular form: {rec}")
```

## C++ Usage Example

```cpp
#include <iostream>
#include "complex.h"  // Include the header file

int main() {
    complex z1, z2;
    std::cout << "Enter a complex number (x y): ";
    std::cin >> z1;

    std::cout << "Enter another complex number (x y): ";
    std::cin >> z2;

    complex sum = z1 + z2;
    std::cout << "Sum: " << sum << std::endl;

    complex diff = z1 - z2;
    std::cout << "Difference: " << diff << std::endl;

    complex product = z1 * z2;
    std::cout << "Product: " << product << std::endl;

    complex quotient = z1 / z2;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.