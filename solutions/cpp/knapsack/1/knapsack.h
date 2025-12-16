#pragma once
#include <vector>
#include <cstddef> //for the size_t data type

namespace knapsack {

struct Item {
    int weight;
    int value;
};

    int maximum_value(int max_weight, std::vector<Item> items);
    int solve_knapsack(int capacity, size_t i, const std::vector<Item>& items);
}  // namespace knapsack
