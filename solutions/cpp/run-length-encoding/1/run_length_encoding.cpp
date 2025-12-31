#include "run_length_encoding.h"
#include <cctype>
#include <iostream>
namespace run_length_encoding {

std::string encode(std::string abc){
    if(abc == ""){
        return "";
    }
    int count = 0;
    std::string rle = "";
    char curr = abc.at(0);

    
    for (size_t i = 0; i < abc.length(); i++){
        if (abc.at(i) == curr){
            count += 1;
        } else if (abc.at(i) != curr){
            if (count != 1){
                rle += std::to_string(count);
            }
            rle += curr;
            count = 1;
            curr = abc.at(i);
        }
    }

    if (count != 1){
        rle += std::to_string(count);
    }
    rle += curr;

    return rle;
}


std::string decode(std::string rle){
    if (rle == ""){
        return "";
    }
    
    
    std::string abc = "";
    char curr = rle.at(0);
    std::string multi = "";
    int mul =0;
    for (size_t i = 0; i < rle.length(); i++){
        curr = rle.at(i);
        if(isdigit(curr)){
            multi += curr;
            
        } else if (isalpha(curr) || " "){
            if (multi == ""){
                mul = 1;
            } else {
                mul = std::stoi( multi );
            }
            abc += std::string( mul , curr);
            
            multi = "";
        }
    }

    std::cout << abc;
    return abc;
}
}  // namespace run_length_encoding
