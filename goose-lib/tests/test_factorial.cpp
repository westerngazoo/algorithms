#include <gtest/gtest.h>

// Import our module to test its functions.
import goose.algorithm;

// Test case for the factorial function.
TEST(FactorialTest, HandlesZero) {
    EXPECT_EQ(goose::algorithm::factorial(0), 1);
}

TEST(FactorialTest, HandlesPositiveNumbers) {
    EXPECT_EQ(goose::algorithm::factorial(1), 1);
    EXPECT_EQ(goose::algorithm::factorial(5), 120);
    EXPECT_EQ(goose::algorithm::factorial(10), 3628800);
}
