#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int fib[n + 1];
    fib[0] = 0;
    if (n >= 1) {
        fib[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    std::cout << fib[n];

    return 0;
}