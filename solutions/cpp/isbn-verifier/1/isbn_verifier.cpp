#include "isbn_verifier.h"
#include <cctype>
#include <algorithm>
#include <iostream>

namespace isbn_verifier {


bool is_valid(std::string isbn){
    std::string clean_isbn = "";
    int len = isbn.length();
    
    for (int i = 0; i < len; i++){
        auto&& c = isbn.at(i);
        if(isdigit(c)){
            clean_isbn += c;
        } else if ( c == 'X' && i == len-1){ // X must be last char
            clean_isbn += c;
        } else if ( c == '-'){ // remove '-'
            continue;
        } else{ //invalid char found
            return false;
        }
    }

    
    std::cout << clean_isbn;
    len = clean_isbn.length();
    if (len != 10){
        return false;
    }


    int count = 0;

    
    for (int i = 0; i < len; i++){
        auto&& c = clean_isbn.at(i);
        if (isdigit(c)){
            count += (c - '0' ) * (len - i);
            } else if (c == 'X'){
            count += 10 * (len - i);
            }
    }
    std::cout << count % 11 << std::endl;
    return count % 11 == 0;
}
}  // namespace isbn_verifier
