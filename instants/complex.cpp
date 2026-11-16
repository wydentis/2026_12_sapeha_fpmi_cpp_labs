#include <cmath>
#include <stdexcept>

struct Complex {
    double re, im;
};

double Abs(const Complex& c) { return std::hypot(c.re, c.im); }

Complex Add(const Complex& a, const Complex& b) {
    return Complex{a.re + b.re, a.im + b.im};
}

Complex Sub(const Complex& a, const Complex& b) {
    return Complex{a.re - b.re, a.im - b.im};
}

Complex Mul(const Complex& a, const Complex& b) {
    return Complex{a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re};
}

Complex Div(const Complex& a, const Complex& b) {
    double denominator = b.re * b.re + b.im * b.im;
    if (denominator == 0) throw std::invalid_argument("division by zero");
    return Complex{(a.re * b.re + a.im * b.im) / denominator,
                   (a.im * b.re - a.re * b.im) / denominator};
}

void SetRe(Complex& c, double re) { c.re = re; }

void SetIm(Complex& c, double im) { c.im = im; }

int main() { return 0; }