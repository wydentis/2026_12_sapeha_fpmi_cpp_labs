#include <iostream>

std::string parse_num(int num) {
    std::string res = "";

    if (num <= 9) {
        res += " ";
    }

    res += std::to_string(num);

    return res;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    for (int i = 1; i <= n - 1; i++) {
        std::cout << "   ";
    }

    for (int i = 1; i <= k; i++) {
        std::cout << parse_num(i);

        if ((i + n - 1) % 7 == 0) {
            std::cout << std::endl;
        } else if (i == k) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }

    return 0;
}