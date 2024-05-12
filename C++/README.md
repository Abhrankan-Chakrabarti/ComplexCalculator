# ComplexCalculator C++ Implementation

This C++ implementation of ComplexCalculator provides a set of functionalities for performing various operations on complex numbers, including calculating modulus, argument, conjugate, reciprocal, and converting between rectangular and polar forms.

## Features

- Calculate modulus and argument of complex numbers
- Perform addition, subtraction, multiplication, division, and exponentiation of complex numbers
- Convert complex numbers between rectangular and polar forms

## Usage

1. Compile `complex.cpp` into a library:
   ```bash
   g++ -c complex.cpp -o complex.o
   ar rcs libcomplex.a complex.o
   ```

2. Compile `main_complex.cpp` and link it with the `libcomplex.a` library:
   ```bash
   g++ main_complex.cpp -o main_complex -L. -lcomplex
   ```

3. Run the compiled executable `main_complex`:
   ```bash
   ./main_complex
   ```

4. Follow the on-screen instructions to perform different operations on complex numbers.

## Example

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

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.