#include <iostream>

int main() {
    std::string num;
    std::cin >> num;

    if (num[0] == num[3] && num[1] == num[2]) {
        std::cout << "palindrom";
    } else {
        std::cout << "not palindrom";
    }

    return 0;
}