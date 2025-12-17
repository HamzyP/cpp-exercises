#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {

// TODO: add your solution here
 std::map<char, int> count(std::string abc){
     std::map<char, int> ref = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
     
     for (char letter : abc){
         if (ref.count(letter)){
             ref[letter] += 1;
         } else {
             throw std::invalid_argument ("invalid character");
         }
     }

     return ref;
 }
}  // namespace nucleotide_count
