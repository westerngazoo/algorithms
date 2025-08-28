#include <gtest/gtest.h>
#include <vector>

import goose.algorithm;

TEST(SortTest, BubbleSortsAnUnsortedVector) {
    std::vector<int> values = {5, 1, 4, 2, 8};
    std::vector<int> expected = {1, 2, 4, 5, 8};
    goose::algorithm::bubble_sort(values);
    EXPECT_EQ(values, expected);
}

TEST(SortTest, HandlesAlreadySortedVector) {
    std::vector<int> values = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    goose::algorithm::bubble_sort(values);
    EXPECT_EQ(values, expected);
}

TEST(SortTest, HandlesEmptyVector) {
    std::vector<int> values = {};
    std::vector<int> expected = {};
    goose::algorithm::bubble_sort(values);
    EXPECT_EQ(values, expected);
}