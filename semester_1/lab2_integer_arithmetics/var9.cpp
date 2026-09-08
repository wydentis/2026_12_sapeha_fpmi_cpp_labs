#include <iostream>

bool is_palindrome(int num) {
    if (num < 0) {
        return false;
    }

    int original = num;
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return reversed == original;
}

int main() {
    int a, b;
    std::cin >> a >> b;

    for (int i = std::min(a, b); i <= std::max(a, b); i++) {
        if (is_palindrome(i)) {
            std::cout << i << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}
