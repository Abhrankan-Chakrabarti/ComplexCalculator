#include <iostream>
#include <math.h>
#include "complex.h"

using namespace std;

char complex::drg;
char *complex::u;
bool complex::p = false;

void complex::angle(bool from_rad)
{
	switch (drg)
	{
	case 'r':
	case 'R':
		break;
	case 'g':
	case 'G':
		y *= from_rad ? 200 / M_PI : M_PI / 200;
		break;
	default:
		y *= from_rad ? 180 / M_PI : M_PI / 180;
	}
}

double complex::convert(double i, char u, bool from_rad)
{
	complex z;
	z.y = i, z.drg = u;
	z.angle(from_rad);
	return z.y;
}

char *complex::unit(char u)
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

double complex::mod()
{
	return sqrt(x * x + y * y);
}

double complex::arg()
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

complex complex::conjugate()
{
	complex z1;
	z1.x = x;
	z1.y = -y;
	z1.p = p;
	z1.u = u;
	return z1;
}

complex complex::reci()
{
	complex z1, z2;
	z1.x = 1, z1.y = 0, z2.x = this->x, z2.y = this->y;
	z1.p = z2.p = this->p, z1.u = z2.u = this->u;
	z1.drg = z2.drg = this->drg;
	return z1 / z2;
}

complex complex::pol(char u)
{
	complex z, p;
	z.x = this->x, z.y = this->y;
	p.x = z.mod(), p.y = complex::convert(z.arg(), u), p.p = true, p.u = complex::unit(u);
	return p;
}

complex complex::rec()
{
	complex z1, z2;
	z1.x = this->x, z1.y = this->y, z1.drg = this->drg;
	z1.angle(false);
	z2.x = z1.x * cos(z1.y), z2.y = z1.x * sin(z1.y);
	return z2;
}

complex complex::operator+(complex &m)
{
	complex z1, z2;
	z1.x = this->x, z1.y = this->y, z1.p = p, z1.u = u;
	if (p || m.p)
	{
		if (p && m.p && y == complex::convert(1, drg) * complex::convert(m.y, m.drg, false))
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

complex complex::operator-(complex &m)
{
	complex z1, z2;
	z1.x = this->x, z1.y = this->y, z1.p = p, z1.u = u;
	if (p || m.p)
	{
		if (p && m.p && y == complex::convert(1, drg) * complex::convert(m.y, m.drg, false))
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

complex complex::operator*(complex &m)
{
	complex z1;
	if (p)
	{
		if (!m.p)
			m = m.pol(drg);
		else if (drg != m.drg)
			m.y = complex::convert(1, drg) * complex::convert(m.y, m.drg, false), m.u = u;
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

complex complex::operator/(complex &m)
{
	complex z1;
	double c;
	if (p)
	{
		if (!m.p)
			m = m.pol(drg);
		else if (drg != m.drg)
			m.y = complex::convert(1, drg) * complex::convert(m.y, m.drg, false), m.u = u;
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

complex complex::operator^(complex &m)
{
	complex z1, z2;
	z1.x = x, z1.y = y;
	if (!p)
		z1 = z1.pol();
	if (m.p)
		m = m.rec();
	z2.x = z1.x / exp(complex::convert(z1.y, 'd', false) * m.y), z2.y = m.x * z1.y, z2.p = true, z2.u = z1.u;
	return z2;
}

ostream &operator<<(ostream &out, const complex &c)
{
	out << c.x;
	if (c.y > 0)
		out << (c.p ? "\u2220" : "+") << c.y << (c.p ? c.u : "i");
	else if (c.y < 0)
		out << (c.p ? "\u2220" : "") << c.y << (c.p ? c.u : "i");
	return out;
}

istream &operator>>(istream &in, complex &c)
{
	char u;
	cout << (c.p ? "Enter the Magnitude :\t" : "Enter the Real Part :\t");
	in >> c.x;
	if (c.p)
	{
		cout << "Enter its Angle Unit (d/r/g) :\t";
		in >> u;
	}
	cout << (c.p ? "Enter its Inclination :\t" : "Enter the Imaginary Part :\t");
	in >> c.y;
	if (c.p)
		c.drg = u, c.u = complex::unit(u);
	return in;
}