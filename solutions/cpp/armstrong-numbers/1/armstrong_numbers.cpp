#include "armstrong_numbers.h"
#include <cmath>
#include <string>

namespace armstrong_numbers {


bool is_armstrong_number(int num){
    int count = 0;
    int length = std::to_string(num).length();
    std::string str_num = std::to_string(num);
    
    for(int i=0; i < length; i++){
        count += pow(int(str_num[i] - '0'), length);
    }

    return count == num;
}
}  // namespace armstrong_numbers
