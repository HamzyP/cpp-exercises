#include "nth_prime.h"
#include <stdexcept>

namespace nth_prime {

int nth(int num){
    if(num == 0){
        throw std::domain_error("error");    }

    int curr = 0;
    int candidate =1;
    // not made it to our prime number yet..
    while (curr != num){
        bool is_prime = true;
        candidate += 1;
        for (int i =2 ; i*i <= candidate; i++){
                if (candidate % i ==0 ){
                    is_prime = false;
                }
            }

        if(is_prime){
            curr += 1;
            is_prime = true;
        }
        
    }

    return candidate;
    
}
}  // namespace nth_prime
