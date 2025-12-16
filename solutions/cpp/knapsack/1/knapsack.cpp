#include "knapsack.h"
#include <iostream>
#include <algorithm>

// 0/1 Knapsack problem solved using dynamic programming

namespace knapsack {

// TODO: add your solution here
int maximum_value(int max_weight, std::vector<Item> items){
    //sort the vector on value
    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b){
        return a.value > b.value;
    });

    // int count = 0;
    // int weight_used = 0;

    int count = solve_knapsack(max_weight, 0, items);

    return count;
        
}


    int solve_knapsack(int capacity, size_t i, const std::vector<Item>& items){
        // base case
        if (capacity ==0 || i == items.size()){
            return 0;
        }

        // item too heavy
        if (items[i].weight > capacity){
            return solve_knapsack(capacity, i+1, items);
        }

        // item fits
        //work out whether theres more value from just our item or our item plus previous items (considering capacity)
        // dont take the item

        //timeline: you don't put the item in the bag
        int value_without = solve_knapsack(capacity, i+1, items);

        //timeline: you put the item in the bag
        int value_with = items[i].value + solve_knapsack(capacity-items[i].weight, i+1, items);
        return std::max(value_with, value_without);
        
        
    }
}  // namespace knapsack





// struct Item {
//     int weight;
//     int value;
// };