# ComplexCalculator

This repository contains implementations of complex number operations in both Python (`Complex.py`) and C++ (`complex.cpp`).

## Usage

- **Python**: Run `Complex.py` to perform various complex number calculations and conversions. The script provides a menu-driven interface for easy interaction.

- **C++**: Compile `complex.cpp` into a library and link it with `main_complex.cpp` to perform complex number operations in C++. The program offers a menu-based interface similar to the Python script.

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
arg_deg = z.arg('d')
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
```

## C++ Usage Example

```cpp
#include <iostream>
#include "complex.h"

int main()
{
    complex z1, z2;
    std::cout << "Enter the first complex number:" << std::endl;
    std::cin >> z1;

    std::cout << "Enter the second complex number:" << std::endl;
    std::cin >> z2;

    std::cout << "1st number: " << z1 << std::endl;
    std::cout << "2nd number: " << z2 << std::endl;

    char choice;
    do
    {
        std::cout << "\nChoose an operation (+, -, *, /, ^, q to quit): ";
        std::cin >> choice;

        switch (choice)
        {
        case '+':
            std::cout << "Sum: " << (z1 + z2) << std::endl;
            break;
        case '-':
            std::cout << "Difference: " << (z1 - z2) << std::endl;
            break;
        case '*':
            std::cout << "Product: " << (z1 * z2) << std::endl;
            break;
        case '/':
            std::cout << "Quotient: " << (z1 / z2) << std::endl;
            break;
        case '^':
            std::cout << "Power: " << (z1 ^ z2) << std::endl;
            break;
        case 'q':
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 'q');

    return 0;
}

```

## Building the C++ Program

To build the C++ program, use the following commands:

```bash
g++ -c complex.cpp -o complex.o
ar rcs libcomplex.a complex.o
g++ main_complex.cpp -o main_complex -L. -lcomplex
./main_complex
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.