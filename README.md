# Complex Number Operations in C++

This C++ program provides a comprehensive set of operations for working with complex numbers. It includes functionalities for converting between polar and rectangular forms, calculating modulus, argument, conjugate, reciprocal, and performing basic arithmetic operations on complex numbers.

## Features

- **Modulus (`mod`)**: Calculate the modulus of a complex number.
- **Argument (`arg`)**: Calculate the argument (angle) of a complex number.
- **Conjugate (`conjugate`)**: Calculate the conjugate of a complex number.
- **Reciprocal (`reci`)**: Calculate the reciprocal of a complex number.
- **Polar Conversion (`pol`)**: Convert a complex number to polar form.
- **Rectangular Conversion (`rec`)**: Convert a complex number to rectangular form.
- **Arithmetic Operations**: Addition, subtraction, multiplication, division, and exponentiation of complex numbers.

## Usage

1. **Compilation**: Compile the program using a C++ compiler (e.g., g++):

   ```bash
   g++ complex.cpp -o complex
   ```

2. **Execution**: Run the compiled program:

   ```bash
   ./complex
   ```

3. **Operation**: Follow the on-screen menu to select the desired complex number operation and input the required values, including the angle unit for argument calculation.

## Examples

### Modulus Calculation

```
Enter your choice :   1
Enter a complex no :
Enter the Real Part :   3
Enter the Imaginary Part :   4
z = 3+4i
|z| = 5
```

### Argument Calculation

```
Enter your choice :   2
Enter a complex no :
Enter the Real Part :   3
Enter the Imaginary Part :   4
Enter its Angle Unit (d/r/g) :   d
z = 3+4i
arg(z) = 53.1301°
```

## Author

Abhrankan Chakrabarti

## License

This project is licensed under the [MIT License](LICENSE).
