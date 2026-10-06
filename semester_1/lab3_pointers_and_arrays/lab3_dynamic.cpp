#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

void dlt(int* x, int* y, double* z) {
    delete[] x;
    delete[] y;
    delete[] z;
}

// вариант 11
int main() {
    int n;

    std::cout << "n: ";
    if (!(std::cin >> n) || n < 1) {
        std::cout << "incorrect vector size\n";
        return 1;
    }

    int* x = new int[n];
    int* y = new int[n];
    double* z = new double[n];

    std::cout << "modes: 1 - from user, 2 - random\nmode: ";
    int mode;
    if (!(std::cin >> mode) || (mode != 1 && mode != 2)) {
        std::cout << "incorrect mode\n";
        dlt(x, y, z);
        return 1;
    }

    if (mode == 1) {
        std::cout << "input x elements: ";
        for (int i = 0; i < n; i++) {
            if (!(std::cin >> x[i])) {
                std::cout << "input error\n";
                dlt(x, y, z);
                return 1;
            }
        }
        std::cout << "input y elements: ";
        for (int i = 0; i < n; i++) {
            if (!(std::cin >> y[i])) {
                std::cout << "input error\n";
                dlt(x, y, z);
                return 1;
            }
        }
    }

    if (mode == 2) {
        int lo, hi;
        std::cout << "input bounds [a, b]: ";
        if (!(std::cin >> lo >> hi)) {
            std::cout << "input error\n";
            dlt(x, y, z);
            return 1;
        }

        if (lo > hi) {
            std::swap(lo, hi);
        }

        std::srand(static_cast<unsigned>(std::time(nullptr)));
        for (int i = 0; i < n; i++) {
            x[i] = lo + std::rand() % (hi - lo + 1);
        }
        for (int i = 0; i < n; i++) {
            y[i] = lo + std::rand() % (hi - lo + 1);
        }
    }

    std::cout << "x: ";
    for (int i = 0; i < n; i++) {
        std::cout << x[i] << " ";
    }
    std::cout << "\ny: ";
    for (int i = 0; i < n; i++) {
        std::cout << y[i] << " ";
    }
    std::cout << "\n";

    long long dot = 0;
    for (int i = 0; i < n; i++) {
        dot += 1LL * x[i] * y[i];
    }

    if (dot == 0) {
        std::cout << "dot product is 0, vector z cannot be built\n";
    } else {
        for (int i = 0; i < n; i++) {
            z[i] = std::sqrt((double)x[i] * x[i] + (double)y[i] * y[i]) /
                   (double)dot;
        }
        std::cout << "dot product: " << dot << "\nz: ";
        for (int i = 0; i < n; i++) {
            std::cout << z[i] << " ";
        }
        std::cout << "\n";
    }

    dlt(x, y, z);
    return 0;
}