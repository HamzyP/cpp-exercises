#include "knapsack.h"
#include <iostream>

// 0/1 Knapsack problem solved using recursion (non-optimal, brute force)

namespace knapsack {
    int maximum_value(int max_weight, std::vector<Item> items){
        return solve_knapsack(max_weight, 0, items);;
    }


    int solve_knapsack(int capacity, size_t i, const std::vector<Item>& items){
        // base case: no capacity or no items
        if (capacity ==0 || i == items.size()){
            return 0;
        }

        // 1. item too heavy
        if (items[i].weight > capacity){
            return solve_knapsack(capacity, i+1, items);
        }

        // 2. item fits

        // 2a. timeline: you don't put the item in the bag
        int value_without = solve_knapsack(capacity, i+1, items);

        // 2b. timeline: you put the item in the bag
        int value_with = items[i].value + solve_knapsack(capacity-items[i].weight, i+1, items);
        return std::max(value_with, value_without);
    }
}  // namespace knapsack





// struct Item {
//     int weight;
//     int value;
// };