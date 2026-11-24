#include "oop_complex.h"

Complex::Complex(double real, double imag) {
    real_ = real;
    imag_ = imag;
}

Complex::Complex(const Complex& other) {
    imag_ = other.imag_;
    real_ = other.real_;
}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        real_ = other.real_;
        imag_ = other.imag_;
    }

    return *this;
}

bool Complex::operator==(const Complex& other) const {
    return real_ == other.real_ && imag_ == other.imag_;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

Complex Complex::operator+() const {
    return *this;
}

Complex Complex::operator-() const {
    return Complex(-real_, -imag_);
}

Complex& Complex::operator+=(const Complex& other) {
    real_ += other.real_;
    imag_ += other.imag_;

    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    real_ -= other.real_;
    imag_ -= other.imag_;

    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    auto new_real_ = real_ * other.real_ - imag_ * other.imag_;
    auto new_imag_ = real_ * other.imag_ + imag_ * other.real_;

    real_ = new_real_;
    imag_ = new_imag_;

    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    double denominator = other.real_ * other.real_ + other.imag_ * other.imag_;
    auto new_real_ = (real_ * other.real_ + imag_ * other.imag_) / denominator;
    auto new_imag_ = (imag_ * other.real_ - real_ * other.imag_) / denominator;

    real_ = new_real_;
    imag_ = new_imag_;

    return *this;
}

double& Complex::Real() {
    return real_;
}

double Complex::Real() const {
    return real_;
}

void Complex::Real(double real) {
    real_ = real;
}

double& Complex::Imag() {
    return imag_;
}

double Complex::Imag() const {
    return imag_;
}

void Complex::Imag(double imag) {
    imag_ = imag;
}

double Complex::Abs() const {
    return std::hypot(real_, imag_);
}

std::ostream& operator<<(std::ostream& out, const Complex& z) {
    char div = '+';
    if (z.imag_ < 0) {
        div = '-';
    }
    out << z.real_ << div << std::abs(z.imag_) << 'i';

    return out;
}

std::istream& operator>>(std::istream& in, Complex& z) {
    double r, i;
    if (in >> r >> i) {
        z.real_ = r;
        z.imag_ = i;
    }

    return in;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.Real() + rhs.Real(), lhs.Imag() + rhs.Imag());
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.Real() - rhs.Real(), lhs.Imag() - rhs.Imag());
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    auto cmpl = Complex(lhs);
    cmpl *= rhs;
    return cmpl;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    auto cmpl = Complex(lhs);
    cmpl /= rhs;
    return cmpl;
}