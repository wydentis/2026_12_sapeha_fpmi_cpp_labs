#include <iostream>
#include <map>
#include <string>

int main() {
    std::string a, b;

    if (!(std::cin >> a >> b)) {
        std::cerr << "bad input\n";
        return 1;
    }

    if (a.size() != b.size()) {
        std::cerr << "cannot be anagrams\n";
        return 0;
    }

    std::map<char, int> seen;

    for (int i = 0; i < a.size(); i++) {
        seen[a[i]]++;
        seen[b[i]]--;
    }

    for (std::pair<char, int> ch : seen) {
        if (ch.second != 0) {
            std::cout << "not annagrams\n";
            return 0;
        }
    }

    std::cout << "anagrams\n";
    return 0;
}