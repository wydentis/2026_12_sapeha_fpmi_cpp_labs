// Tests for complex.cpp
// Build & run:  g++ -std=c++17 -Wall -Wextra complex_test.cpp -o complex_test && ./complex_test

#define main complex_main  // complex.cpp has its own main(); rename it here
#include "complex.cpp"
#undef main

#include <cmath>
#include <iostream>

namespace {

int failures = 0;
int checks = 0;

bool Near(double a, double b, double eps = 1e-9) { return std::fabs(a - b) < eps; }

void ExpectComplex(const char* expr, const Complex& got, double re, double im, int line) {
    ++checks;
    if (!Near(got.re, re) || !Near(got.im, im)) {
        ++failures;
        std::cout << "FAIL (line " << line << "): " << expr << "\n"
                  << "    expected " << re << " + " << im << "i\n"
                  << "    got      " << got.re << " + " << got.im << "i\n";
    }
}

void ExpectDouble(const char* expr, double got, double expected, int line) {
    ++checks;
    if (!Near(got, expected)) {
        ++failures;
        std::cout << "FAIL (line " << line << "): " << expr << "\n"
                  << "    expected " << expected << ", got " << got << "\n";
    }
}

#define EXPECT_COMPLEX(expr, re, im) ExpectComplex(#expr, (expr), (re), (im), __LINE__)
#define EXPECT_DOUBLE(expr, val) ExpectDouble(#expr, (expr), (val), __LINE__)

void TestAbs() {
    EXPECT_DOUBLE(Abs(Complex{0, 0}), 0.0);
    EXPECT_DOUBLE(Abs(Complex{3, 4}), 5.0);
    EXPECT_DOUBLE(Abs(Complex{-3, -4}), 5.0);
    EXPECT_DOUBLE(Abs(Complex{0, -7}), 7.0);
    EXPECT_DOUBLE(Abs(Complex{1, 1}), std::sqrt(2.0));
}

void TestAdd() {
    EXPECT_COMPLEX(Add(Complex{1, 2}, Complex{2, 3}), 3, 5);
    EXPECT_COMPLEX(Add(Complex{1, 2}, Complex{0, 0}), 1, 2);
    EXPECT_COMPLEX(Add(Complex{1, -2}, Complex{-1, 2}), 0, 0);
    EXPECT_COMPLEX(Add(Complex{0.5, 1.5}, Complex{0.25, -0.75}), 0.75, 0.75);
}

void TestSub() {
    EXPECT_COMPLEX(Sub(Complex{1, 2}, Complex{2, 3}), -1, -1);
    EXPECT_COMPLEX(Sub(Complex{5, 5}, Complex{5, 5}), 0, 0);
    EXPECT_COMPLEX(Sub(Complex{0, 0}, Complex{1, -1}), -1, 1);
}

void TestMul() {
    // (1+2i)(2+3i) = 2 + 3i + 4i + 6i^2 = -4 + 7i
    EXPECT_COMPLEX(Mul(Complex{1, 2}, Complex{2, 3}), -4, 7);
    // i * i = -1
    EXPECT_COMPLEX(Mul(Complex{0, 1}, Complex{0, 1}), -1, 0);
    // multiplying by 1 is identity
    EXPECT_COMPLEX(Mul(Complex{3, -4}, Complex{1, 0}), 3, -4);
    // multiplying by i rotates by 90 degrees: (3-4i)*i = 4 + 3i
    EXPECT_COMPLEX(Mul(Complex{3, -4}, Complex{0, 1}), 4, 3);
    // z * conj(z) = |z|^2
    EXPECT_COMPLEX(Mul(Complex{3, 4}, Complex{3, -4}), 25, 0);
    // anything * 0 = 0
    EXPECT_COMPLEX(Mul(Complex{7, 8}, Complex{0, 0}), 0, 0);
}

void TestDiv() {
    // (-4+7i)/(2+3i) = 1+2i  (inverse of the Mul test above)
    EXPECT_COMPLEX(Div(Complex{-4, 7}, Complex{2, 3}), 1, 2);
    // 1 / i = -i
    EXPECT_COMPLEX(Div(Complex{1, 0}, Complex{0, 1}), 0, -1);
    // z / 1 = z
    EXPECT_COMPLEX(Div(Complex{3, -4}, Complex{1, 0}), 3, -4);
    // z / z = 1
    EXPECT_COMPLEX(Div(Complex{3, 4}, Complex{3, 4}), 1, 0);
    // divide by a real number
    EXPECT_COMPLEX(Div(Complex{4, 6}, Complex{2, 0}), 2, 3);
    // (1+2i)/(3+4i) = (11 + 2i) / 25
    EXPECT_COMPLEX(Div(Complex{1, 2}, Complex{3, 4}), 0.44, 0.08);
}

void TestMulDivRoundTrip() {
    const Complex values[] = {{1, 2}, {-3, 0.5}, {0, -1}, {2.5, -7}, {100, 0.01}};
    for (const Complex& a : values) {
        for (const Complex& b : values) {
            Complex r = Div(Mul(a, b), b);
            ExpectComplex("Div(Mul(a, b), b) == a", r, a.re, a.im, __LINE__);
        }
    }
}

void ExpectThrows(const char* expr, const Complex& a, const Complex& b, int line) {
    ++checks;
    try {
        Complex r = Div(a, b);
        ++failures;
        std::cout << "FAIL (line " << line << "): " << expr << "\n"
                  << "    expected an exception, got " << r.re << " + " << r.im << "i\n";
    } catch (...) {
        // expected
    }
}

#define EXPECT_DIV_THROWS(a, b) ExpectThrows("Div(" #a ", " #b ") throws", (a), (b), __LINE__)

void TestDivByZero() {
    EXPECT_DIV_THROWS((Complex{1, 2}), (Complex{0, 0}));
    EXPECT_DIV_THROWS((Complex{0, 0}), (Complex{0, 0}));
    EXPECT_DIV_THROWS((Complex{-3.5, 0}), (Complex{0.0, -0.0}));
}

void TestSetters() {
    Complex c{1, 2};
    SetRe(c, 10);
    EXPECT_COMPLEX(c, 10, 2);
    SetIm(c, -5);
    EXPECT_COMPLEX(c, 10, -5);
}

}  // namespace

int main() {
    TestAbs();
    TestAdd();
    TestSub();
    TestMul();
    TestDiv();
    TestMulDivRoundTrip();
    TestDivByZero();
    TestSetters();

    std::cout << (checks - failures) << "/" << checks << " checks passed\n";
    return failures == 0 ? 0 : 1;
}
