#include <iostream>

bool isOnlyFromOdd(int num) {
    while (num != 0) {
        if (num % 10 % 2 == 0) {
            return false;
        }
        num /= 10;
    }

    return true;
}

int main() {
    int a, b;

    std::cout << "input number a: ";
    if (!(std::cin >> a) || a <= 0) {
        std::cout << "error: wrong input";
        return 0;
    }

    std::cout << "input number b: ";
    if (!(std::cin >> b) || b <= 0) {
        std::cout << "error: wrong input";
        return 0;
    }

    if (a > b) {
        std::swap(a, b);
    }

    int ans = 0;

    for (int i = a; i <= b; i++) {
        if (isOnlyFromOdd(i)) {
            std::cout << i << std::endl;
            ans++;
        }
    }

    std::cout << "count of only from odd nums: " << ans;

    return 0;
}