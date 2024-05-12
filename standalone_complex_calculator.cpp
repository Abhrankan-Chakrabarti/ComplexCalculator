#include <iostream>
#include <math.h>
using namespace std;
class complex
{
	friend ostream &operator<<(ostream &, const complex &);
	friend istream &operator>>(istream &, complex &);

  private:
	char drg, *u;
	double x, y;

  public:
	bool p = false;
	void angle(bool from_rad)
	{
		switch (this->drg)
		{
		case 'r':
		case 'R':
			break;
		case 'g':
		case 'G':
			this->y *= from_rad ? 200 / M_PI : M_PI / 200;
			break;
		default:
			this->y *= from_rad ? 180 / M_PI : M_PI / 180;
		}
	}
	static double convert(double i, char u, bool from_rad)
	{
		complex z;
		z.y = i, z.drg = u;
		z.angle(from_rad);
		return z.y;
	}
	static double convert(double i, char u)
	{
		return convert(i, u, true);
	}
	static char *unit(char u)
	{
		switch (u)
		{
		case 'r':
		case 'R':
			return (char *)" rad";
		case 'g':
		case 'G':
			return (char *)"g";
		default:
			return (char *)"\u00b0";
		}
	}
	double mod()
	{
		return sqrt(x * x + y * y);
	}
	double arg()
	{
		if (x > 0)
			return atan(y / x);
		if (x == 0)
		{
			if (y > 0)
				return M_PI / 2;
			if (y < 0)
				return -M_PI / 2;
			return 0;
		}
		if (y >= 0)
			return atan(y / x) + M_PI;
		return atan(y / x) - M_PI;
	}
	complex conjugate()
	{
		complex z1;
		z1.x = x;
		z1.y = -y;
		z1.p = p;
		z1.u = u;
		return z1;
	}
	complex reci()
	{
		complex z1, z2;
		z1.x = 1, z1.y = 0, z2.x = this->x, z2.y = this->y;
		z1.p = z2.p = this->p, z1.u = z2.u = this->u;
		z1.drg = z2.drg = this->drg;
		return z1 / z2;
	}
	complex pol(char u)
	{
		complex z, p;
		z.x = this->x, z.y = this->y;
		p.x = z.mod(), p.y = convert(z.arg(), u), p.p = true, p.u = complex::unit(u);
		return p;
	}
	complex rec()
	{
		complex z1, z2;
		z1.x = this->x, z1.y = this->y, z1.drg = this->drg;
		z1.angle(false);
		z2.x = z1.x * cos(z1.y), z2.y = z1.x * sin(z1.y);
		return z2;
	}
	complex operator+(complex &m)
	{
		complex z1, z2;
		z1.x = this->x, z1.y = this->y, z1.p = p, z1.u = u;
		if (p || m.p)
		{
			if (p && m.p && y == convert(1, drg) * convert(m.y, m.drg, false))
			{
				z1.x += m.x;
				return z1;
			}
			if (p)
				z1 = z1.rec();
			if (m.p)
				m = m.rec();
		}
		z2.x = z1.x + m.x;
		z2.y = z1.y + m.y;
		if (p)
			z2 = z2.pol(drg);
		return z2;
	}
	complex operator-(complex &m)
	{
		complex z1, z2;
		z1.x = this->x, z1.y = this->y, z1.p = p, z1.u = u;
		if (p || m.p)
		{
			if (p && m.p && y == convert(1, drg) * convert(m.y, m.drg, false))
			{
				z1.x -= m.x;
				return z1;
			}
			if (p)
				z1 = z1.rec();
			if (m.p)
				m = m.rec();
		}
		z2.x = z1.x - m.x;
		z2.y = z1.y - m.y;
		if (p)
			z2 = z2.pol(drg);
		return z2;
	}
	complex operator*(complex &m)
	{
		complex z1;
		if (p)
		{
			if (!m.p)
				m = m.pol(drg);
			else if (drg != m.drg)
				m.y = convert(1, drg) * convert(m.y, m.drg, false), m.u = u;
			z1.x = x * m.x;
			z1.y = y + m.y;
			z1.p = p, z1.u = u;
			return z1;
		}
		if (m.p)
			m = m.rec();
		z1.x = x * m.x - y * m.y;
		z1.y = x * m.y + m.x * y;
		return z1;
	}
	complex operator/(complex &m)
	{
		complex z1;
		double c;
		if (p)
		{
			if (!m.p)
				m = m.pol(drg);
			else if (drg != m.drg)
				m.y = convert(1, drg) * convert(m.y, m.drg, false), m.u = u;
			z1.x = x / m.x;
			z1.y = y - m.y;
			z1.p = p, z1.u = u;
			return z1;
		}
		if (m.p)
			m = m.rec();
		c = m.x * m.x + m.y * m.y;
		z1.x = (x * m.x + y * m.y) / c;
		z1.y = (m.x * y - x * m.y) / c;
		return z1;
	}
	complex operator^(complex &m)
	{
		complex z1, z2;
		z1.x = x, z1.y = y;
		if (!p)
			z1 = z1.pol('d');
		if (m.p)
			m = m.rec();
		z2.x = z1.x / exp(convert(z1.y, 'd', false) * m.y), z2.y = m.x * z1.y, z2.p = true, z2.u = z1.u;
		return z2;
	}
};

ostream &operator<<(ostream &ob, const complex &pt)
{
	ob << pt.x;
	if (pt.y > 0)
		ob << (pt.p ? "\u2220" : "+") << pt.y << (pt.p ? pt.u : "i");
	else if (pt.y < 0)
		ob << (pt.p ? "\u2220" : "") << pt.y << (pt.p ? pt.u : "i");
	return ob;
}
istream &operator>>(istream &os, complex &ptr)
{
	char u;
	cout << (ptr.p ? "Enter the Magnitude :\t" : "Enter the Real Part :\t");
	os >> ptr.x;
	if (ptr.p)
	{
		cout << "Enter its Angle Unit (d/r/g) :\t";
		cin >> u;
	}
	cout << (ptr.p ? "Enter its Inclination :\t" : "Enter the Imaginary Part :\t");
	os >> ptr.y;
	if (ptr.p)
		ptr.drg = u, ptr.u = complex::unit(u);
	return os;
}
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