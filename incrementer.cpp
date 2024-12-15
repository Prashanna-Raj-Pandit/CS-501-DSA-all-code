#include <iostream>
#include <vector>

int main() {
    // Initialize vector with an initializer list (requires C++11 or later)
    std::vector<int> numbers = {1, 2, 3, 4};

    std::cout << "Using ++it:\n";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " "; // Output: 1 2 3 4
    }

    std::cout << "\nUsing it++:\n";
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << " "; // Output: 1 2 3 4
    }

    return 0;
}
