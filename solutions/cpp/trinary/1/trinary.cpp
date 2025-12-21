#include "trinary.h"
#include <cmath>

namespace trinary {

int to_decimal(std::string num){
    int accu = 0;
    int len = num.size();
    for (size_t i = 0; i < num.size(); i++ ){
        if (num[i]>'2' || num[i]< '0'){
            return 0;
        }
        
        int our_num = num.at(i) - '0';
        int multi = pow(3, len -i -1);
        accu += our_num * multi;
    }
    return accu;
}
    
}  // namespace trinary
