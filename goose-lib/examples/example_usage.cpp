#include <iostream>

// Import our module! No more #include for our own library code.
import goose.algorithm;

int main() {
    std::cout << "The factorial of 6 is: " << goose::algorithm::factorial(6) << std::endl;
    return 0;
}