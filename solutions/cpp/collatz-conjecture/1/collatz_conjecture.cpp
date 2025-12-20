#include "collatz_conjecture.h"

namespace collatz_conjecture {

int steps(int num){
    if (num == 0){
        throw std::domain_error("zero doesnt count");
    } else if (num < 0){
        throw std::domain_error("negative numbers dont count");
    } else{
        return simulation(num, 0);
    }
}

int simulation(int num, int count){
    if(num ==1){
        return count;
    } else if (num %2 == 0){ //even
        return simulation(num/2, count+1);
    } else {
        return simulation((num*3)+1, count+1);
    }
    }
}  // namespace collatz_conjecture
