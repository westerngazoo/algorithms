#include <iostream>
#include <vector>

import goose.algorithm;

// Helper function to print a vector
void print_vector(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> my_numbers = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original vector: ";
    print_vector(my_numbers);

    goose::algorithm::bubble_sort(my_numbers);

    std::cout << "Sorted vector:   ";
    print_vector(my_numbers);

    return 0;
}