#include <iostream>

int get_sum(int num) {
    int sum = 0;    

    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int main() {
    int num;
    std::cin >> num;

    if (get_sum(num / 1000) == get_sum(num % 1000)) {
        std::cout << "happy number";
    } else {
        std::cout << "not happy";
    }

    return 0;
}