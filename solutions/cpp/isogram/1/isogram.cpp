#include "isogram.h"
#include <unordered_set>
#include <cctype> //used isaplha, tolower
namespace isogram {


bool is_isogram(std::string str){
    std::unordered_set<char> ust;
    
    for (auto letter : str){
        letter = tolower(letter);
        if (ust.count(letter) && isalpha(letter)){
            return false;
        }else {
            ust.insert(letter);
        }
    }

    return true;
}
}  // namespace isogram
