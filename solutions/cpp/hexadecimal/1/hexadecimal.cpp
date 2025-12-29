#include "hexadecimal.h"
#include <map>
#include <cmath>
#include <iostream>
namespace hexadecimal {

// TODO: add your solution here
int convert(std::string hex){
    
    std::map<char , int> ref = {{'a',  10}, {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15}};
    int count = 0;
    int pos =0;
    for (auto&& letter: hex){
        if(ref.count(letter)){
            int a = ref[letter];
            std::cout << hex.length();
            count += a * pow(16, hex.length() - pos -1);
            pos += 1;
        } else {
            if (isalpha(letter)){
                return 0;
            }
            count += int(letter - '0') * pow(16, hex.length() - pos - 1);
            pos += 1;
        }
    }

    return count;
}
}  // namespace hexadecimal
