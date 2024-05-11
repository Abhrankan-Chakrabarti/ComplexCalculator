#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    void setReal(double r) { real = r; }
    void setImaginary(double i) { imaginary = i; }

    double modulus() const {
        return sqrt(real * real + imaginary * imaginary);
    }

    double argument() const {
        return atan2(imaginary, real);
    }

    Complex conjugate() const {
        return Complex(real, -imaginary);
    }

    Complex reciprocal() const {
        double mod = modulus();
        return Complex(real / (mod * mod), -imaginary / (mod * mod));
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imaginary * other.imaginary,
                       real * other.imaginary + imaginary * other.real);
    }

    Complex operator/(const Complex& other) const {
        double mod = other.modulus();
        return Complex((real * other.real + imaginary * other.imaginary) / (mod * mod),
                       (imaginary * other.real - real * other.imaginary) / (mod * mod));
    }

    friend ostream& operator<<(ostream& os, const Complex& complex) {
        os << complex.real << " + " << complex.imaginary << "i";
        return os;
    }
};

#endif /* COMPLEX_H */