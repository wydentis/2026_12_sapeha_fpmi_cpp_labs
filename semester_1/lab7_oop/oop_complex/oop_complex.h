#pragma once

#include <iostream>
#include <cmath>

class Complex {
public:
    Complex(double real = 0.0, double imag = 0.0);
    Complex(const Complex& other);

    Complex& operator=(const Complex& other);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    Complex operator+() const;
    Complex operator-() const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    friend std::ostream& operator<<(std::ostream& out, const Complex& z);
    friend std::istream& operator>>(std::istream& in, Complex& z);

    double& Real();
    double Real() const;
    void Real(double real);
    double& Imag();
    double Imag() const;
    void Imag(double imag);

    double Abs() const;

private:
    double real_;
    double imag_;
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);