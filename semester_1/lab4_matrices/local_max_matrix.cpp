#include <iostream>
#include <random>

int main() {
    int n, m;
    if (!(std::cin >> n >> m) || n <= 0 || m <= 0) {
        std::cerr << "bad input\n";
        return 1;
    }

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    std::cout << "mode: 1 - user, 2 - random\n";
    char mode;
    if (!(std::cin >> mode)) {
        std::cerr << "bad input\n";
        return 1;
    }

    if (mode == '1') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int input;
                if (!(std::cin >> input)) {
                    std::cerr << "bad input\n";
                    return 0;
                }
                matrix[i][j] = input;
            }
        }
    } else if (mode == '2') {
        int a, b;
        if (!(std::cin >> a >> b)) {
            std::cerr << "bad input\n";
            return 1;
        }

        if (a > b) {
            std::swap(a, b);
        }

        std::mt19937 gen(std::random_device{}());

        std::uniform_int_distribution<int> dist(a, b);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = dist(gen);
            }
        }
    } else {
        std::cerr << "invalid mode\n";
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (matrix[i][j] > matrix[i - 1][j] &&
                matrix[i][j] > matrix[i][j - 1] &&
                matrix[i][j] > matrix[i + 1][j] &&
                matrix[i][j] > matrix[i][j + 1]) {
                std::cout << "i: " << i << " j: " << j
                          << " value: " << matrix[i][j] << std::endl;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}