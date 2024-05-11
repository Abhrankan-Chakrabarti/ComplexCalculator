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
#include "complex.h"

int main() {
    Complex z(3, 4, false, true, 'i');

    // Calculate modulus
    double mod = z.mod();
    cout << "Modulus: " << mod << endl;

    // Calculate argument in radians
    Complex arg = z.arg("r");
    cout << "Argument (radians): " << arg << endl;

    // Calculate conjugate
    Complex conj = z.conjg();
    cout << "Conjugate: " << conj << endl;

    // Calculate reciprocal
    Complex reci = z.reci();
    cout << "Reciprocal: " << reci << endl;

    // Convert to polar form
    Complex pol = z.pol();
    cout << "Polar form: " << pol << endl;

    // Convert to rectangular form
    Complex rec = z.rec();
    cout << "Rectangular form: " << rec << endl;

    return 0;
}
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.