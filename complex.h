#ifndef COMPLEX_H
#define COMPLEX_H

class complex
{
  private:
	static char drg;

	void angle(bool);

  public:
	double x, y;
	static char *u;
	static bool p;
	complex(double real = 0, double imag = 0) : x(real), y(imag) {}

	static double convert(double, char, bool = true);

	static char *unit(char);

	double mod();
	double arg();

	complex conjugate();
	complex reci();
	complex pol(char = 'd');
	complex rec();

	complex operator+(complex &);
	complex operator-(complex &);
	complex operator*(complex &);
	complex operator/(complex &);
	complex operator^(complex &);

	friend std::ostream &operator<<(std::ostream &, const complex &);
	friend std::istream &operator>>(std::istream &, complex &);
};

#endif