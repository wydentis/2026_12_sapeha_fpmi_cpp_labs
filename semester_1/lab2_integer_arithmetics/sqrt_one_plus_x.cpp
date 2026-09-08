#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    const int PRECISION = 10;
    const double EPS = std::pow(10, -PRECISION);

    double x;

    std::cin >> x;

    if (std::fabs(x) >= 1) {
        std::cout << "no";
        return 1;
    }

    double prev = x / 2;

    double res = 1.0 + prev;

    int k = 1;

    while (std::fabs(prev) > EPS) {
        double now = prev * ((1.0 - 2.0 * k) / (2.0 * k + 2.0)) * x;
        prev = now;
        res += now;
        ++k;
    }

    std::cout << std::setprecision(PRECISION);
    std::cout << "res: " << res << std::endl;
    std::cout << "std: " << std::sqrt(1 + x);

    return 0;
}