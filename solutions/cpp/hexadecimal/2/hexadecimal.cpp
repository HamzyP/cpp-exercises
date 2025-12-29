#include "hexadecimal.h"
#include <map>
#include <cmath>

namespace hexadecimal {

// TODO: add your solution here
int convert(std::string_view hex){
    
    const std::map<char , int> ref = {{'a',  10}, {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15}};
    int count = 0;
    int pos = 0;
    for (const char& letter : hex){
        if(ref.count(letter)){
            int a = ref.at(letter);
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
