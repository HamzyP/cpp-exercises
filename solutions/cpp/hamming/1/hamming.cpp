#include "hamming.h"
#include <stdexcept>

namespace hamming {

// TODO: add your solution here
int compute(std::string a, std::string b){
    int count = 0;
    int c = a.size();

    //can only calculate the hamming space in strings of the same length..
    if (a.size() != b.size()){
        throw std::domain_error("strings must be the same length");
    }

    //loop though all the numbers 
    // if they dont match 
    //increment count
    for (int i = 0; i < c; i++ ){
        if (a[i] != b[i]){
            count +=1;
        }
    }

    return count;
}
}  // namespace hamming
