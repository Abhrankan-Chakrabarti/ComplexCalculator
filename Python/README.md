# ComplexCalculator Python Implementation

This Python implementation of ComplexCalculator provides a set of functionalities for performing various operations on complex numbers, including calculating modulus, argument, conjugate, reciprocal, and converting between rectangular and polar forms.

## Usage

Run the `Complex.py` script to start the complex number calculator. The script provides a menu-driven interface for easy interaction. Follow the on-screen instructions to perform different operations on complex numbers.

## Features

- Calculate modulus and argument of complex numbers
- Perform addition, subtraction, multiplication, division, and exponentiation of complex numbers
- Convert complex numbers between rectangular and polar forms

## Example

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

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.