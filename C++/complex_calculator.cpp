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
