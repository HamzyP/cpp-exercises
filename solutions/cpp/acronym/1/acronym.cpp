#include "acronym.h"
#include <cctype>

namespace acronym {


std::string acronym(std::string abc){
    std::string res = abc.substr(0,1);


    for (size_t i = 0; i < abc.size(); i++){
        if (isalpha(abc[i]) && (abc[i-1] == ' ' or abc[i-1] == '-' or abc[i-1] == '_')){
            res += toupper(abc[i]);
        }
    }

    return res;
    }
}  // namespace acronym
