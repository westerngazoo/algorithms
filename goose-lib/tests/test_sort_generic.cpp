#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <utility>
#include <array>

import goose.algorithm;

namespace {
struct Person {
    std::string name;
    int age;
};

struct AgeLess {
    bool operator()(Person const& a, Person const& b) const noexcept { return a.age < b.age; }
};

struct ReverseIntLess {
    bool operator()(int a, int b) const noexcept { return a > b; } // reverses order (descending)
};
}

TEST(SortGenericTest, SortsCustomStructByAge) {
    std::vector<Person> people = {{"Ann", 32}, {"Bob", 25}, {"Cara", 25}, {"Dan", 41}};
    goose::algorithm::bubble_sort(people.begin(), people.end(), AgeLess{});
    ASSERT_EQ(people.size(), 4u);
    EXPECT_EQ(people[0].age, 25);
    EXPECT_EQ(people[1].age, 25);
    EXPECT_EQ(people[2].age, 32);
    EXPECT_EQ(people[3].age, 41);
    // stability check: Bob then Cara (relative order preserved for equal ages)
    EXPECT_EQ(people[0].name, "Bob");
    EXPECT_EQ(people[1].name, "Cara");
}

TEST(SortGenericTest, SortsArrayDescendingWithCustomComparator) {
    std::array<int,6> arr{1, 4, 3, 9, 2, 2};
    goose::algorithm::bubble_sort(arr.begin(), arr.end(), ReverseIntLess{});
    EXPECT_EQ((std::vector<int>{arr.begin(), arr.end()}), (std::vector<int>{9,4,3,2,2,1}));
}

TEST(SortGenericTest, HandlesSingleElementRange) {
    std::vector<int> one{42};
    goose::algorithm::bubble_sort(one.begin(), one.end());
    EXPECT_EQ(one.front(), 42);
}

TEST(SortGenericTest, HandlesIteratorSubrange) {
    std::vector<int> data{9,8,7,6,5,4};
    // Sort middle subrange [1,5)
    goose::algorithm::bubble_sort(data.begin()+1, data.begin()+5);
    EXPECT_EQ((std::vector<int>{data.begin(), data.end()}), (std::vector<int>{9,5,6,7,8,4}));
}
