#include <iostream>
#include "complex.h"
using namespace std;
void printchar(char c, int n)
{
	for (; n > 0; --n)
		cout << c;
}
void printjoin(char c, const char *s)
{
	cout << *s;
	for (++s; *s != '\0'; ++s)
		cout << c << *s;
}
void printchoices(const char *choices)
{
	int i;
	for (i = 0; *choices != '\0'; ++choices)
	{
		if (!i)
			cout << ++i << ". ";
		else if (*choices == ' ')
			cout << endl
				 << ++i << '.';
		cout << *choices;
	}
	cout << endl;
}
int main()
{
	char u;
	complex z1, z2;
	int ch, pr1, pr2;
	do
	{
		printchar('*', 16);
		cout << " ";
		printjoin(' ', "COMPLEX");
		cout << "  ";
		printjoin(' ', "NUMBER");
		cout << " ";
		printchar('*', 16);
		cout << endl;
		printchoices("Modulus Argument Conjugate Reciprocal Polar Rectangular Add Subtract Multiply Divide Power Exit");
		cout << "Enter your choice :\t";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "Enter a complex no :" << endl;
			cin >> z1;
			cout << "z = " << z1 << endl;
			cout << "|z| = " << z1.mod() << endl;
			break;
		case 2:
			cout << "Enter a complex no :" << endl;
			cin >> z1;
			cout << "Enter its Angle Unit (d/r/g) :\t";
			cin >> u;
			cout << "z = " << z1 << endl;
			cout << "arg(z) = " << complex::convert(z1.arg(), u) << complex::unit(u) << endl;
			break;
		case 3:
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr1;
			if (pr1 == 1)
				z1.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z1;
			cout << "z = " << z1 << endl;
			cout << "Conjg(z) = " << z1.conjugate() << endl;
			if (pr1 == 1)
				z1.p = false;
			break;
		case 4:
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr1;
			if (pr1 == 1)
				z1.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z1;
			cout << "z = " << z1 << endl;
			cout << "z^-1 = " << z1.reci() << endl;
			if (pr1 == 1)
				z1.p = false;
			break;
		case 5:
			cout << "Enter a complex no :" << endl;
			cin >> z1;
			cout << "Enter its Angle Unit (d/r/g) :\t";
			cin >> u;
			cout << "z = " << z1 << endl;
			cout << "Pol(z) = " << z1.pol(u) << endl;
			break;
		case 6:
			z1.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z1;
			cout << "z = " << z1 << endl;
			cout << "Rec(z) = " << z1.rec() << endl;
			z1.p = false;
			break;
		case 7:
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr1;
			if (pr1 == 1)
				z1.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z1;
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr2;
			if (pr2 == 1)
				z2.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z2;
			cout << "z1 = " << z1 << endl;
			cout << "z2 = " << z2 << endl;
			cout << "z1 + z2 = " << z1 + z2 << endl;
			if (pr1 == 1)
				z1.p = false;
			if (pr2 == 1)
				z2.p = false;
			break;
		case 8:
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr1;
			if (pr1 == 1)
				z1.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z1;
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr2;
			if (pr2 == 1)
				z2.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z2;
			cout << "z1 = " << z1 << endl;
			cout << "z2 = " << z2 << endl;
			cout << "z1 - z2 = " << z1 - z2 << endl;
			if (pr1 == 1)
				z1.p = false;
			if (pr2 == 1)
				z2.p = false;
			break;
		case 9:
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr1;
			if (pr1 == 1)
				z1.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z1;
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr2;
			if (pr2 == 1)
				z2.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z2;
			cout << "z1 = " << z1 << endl;
			cout << "z2 = " << z2 << endl;
			cout << "z1 * z2 = " << z1 * z2 << endl;
			if (pr1 == 1)
				z1.p = false;
			if (pr2 == 1)
				z2.p = false;
			break;
		case 10:
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr1;
			if (pr1 == 1)
				z1.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z1;
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr2;
			if (pr2 == 1)
				z2.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z2;
			cout << "z1 = " << z1 << endl;
			cout << "z2 = " << z2 << endl;
			cout << "z1 / z2 = " << z1 / z2 << endl;
			if (pr1 == 1)
				z1.p = false;
			if (pr2 == 1)
				z2.p = false;
			break;
		case 11:
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr1;
			if (pr1 == 1)
				z1.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z1;
			printchoices("Polar Rectangular");
			cout << "Enter your choice :\t";
			cin >> pr2;
			if (pr2 == 1)
				z2.p = true;
			cout << "Enter a complex no :" << endl;
			cin >> z2;
			cout << "z1 = " << z1 << endl;
			cout << "z2 = " << z2 << endl;
			cout << "z1 ^ z2 = " << (z1 ^ z2) << endl;
			if (pr1 == 1)
				z1.p = false;
			if (pr2 == 1)
				z2.p = false;
			break;
		case 12:
			break;
		default:
			cout << "Invalid choice." << endl;
		}
	} while (ch != 12);
	return 0;
}
