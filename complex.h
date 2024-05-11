#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class complex {
    friend std::ostream &operator<<(std::ostream &, const complex &);
    friend std::istream &operator>>(std::istream &, complex &);

private:
    char drg, *u;
    double x, y;

public:
    bool p = false;
    void angle(bool from_rad);
    static double convert(double i, char u, bool from_rad);
    static double convert(double i, char u);
    static char *unit(char u);
    double mod();
    double arg();
    complex conjugate();
    complex reci();
    complex pol(char u);
    complex rec();
    complex operator+(complex &m);
    complex operator-(complex &m);
    complex operator*(complex &m);
    complex operator/(complex &m);
    complex operator^(complex &m);
};

#endif