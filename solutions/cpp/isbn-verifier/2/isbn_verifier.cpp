#include "isbn_verifier.h"
#include <cctype>
#include <algorithm>
#include <iostream>

namespace isbn_verifier {


bool is_valid(std::string isbn){
    int count = 0;
    int clean_index = 10;
    
    for (auto&& c : isbn){
        if(isdigit(c)){
            count += (c - '0' ) * clean_index;
            clean_index--;
        } else if ( c == 'X' && clean_index == 1){ // X must be last char
            count += 10 * clean_index;
            clean_index--;
        } else if ( c == '-'){ // remove '-'
            continue;
        } else{ //invalid char found
            return false;
        }
    }

    return (clean_index == 0) && (count % 11 == 0);
}
}  // namespace isbn_verifier
