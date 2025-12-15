#include "binary.h"

namespace binary {

// TODO: add your solution here
int convert(std::string bi){

    int length = bi.size();
    int count = 0;
    int pos = 0;
    
    for (int i = length -1 ; i >= 0; i-- ){
        char c = bi.at(i);
        int digit = c - '0';

        if (c != '0' && c != '1') {
            return 0;
        }
        
        if (digit == 1){
            count += ( 1 << pos);
        }
        pos++;
    }

    return count;
}
}  // namespace binary
