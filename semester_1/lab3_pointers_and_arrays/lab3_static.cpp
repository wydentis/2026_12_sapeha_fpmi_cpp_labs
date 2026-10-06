#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

// вариант 9
int main() {
    int n;

    std::cout << "n: ";
    if (!(std::cin >> n) || n < 1) {
        std::cout << "incorrect massive size\n";
        return 1;
    }

    int a[n];

    std::cout << "modes: 1 - from user, 2 - random\nmode: ";
    int mode;
    if (!(std::cin >> mode) || (mode != 1 && mode != 2)) {
        std::cout << "incoorect mode\n";
        return 1;
    }

    if (mode == 1) {
        std::cout << "input elements: ";
        for (int i = 0; i < n; i++) {
            if (!(std::cin >> a[i])) {
                std::cout << "input error\n";
                return 1;
            }
        }
    }

    if (mode == 2) {
        int lo, hi;
        std::cout << "input bounds [a, b]: ";
        if (!(std::cin >> lo >> hi)) {
            std::cout << "input error\n";
            return 1;
        }

        if (lo > hi) {
            std::swap(lo, hi);
        }

        std::srand(static_cast<unsigned>(std::time(nullptr)));
        for (int i = 0; i < n; i++) {
            a[i] = lo + std::rand() % (hi - lo + 1);
        }
    }

    std::cout << "start massive: \n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    int negative_bound = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            int x = a[i];
            for (int k = i; k > negative_bound; k--) {
                a[k] = a[k - 1];
            }
            a[negative_bound++] = x;
        }
    }

    std::cout << "\nresult massive: \n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}