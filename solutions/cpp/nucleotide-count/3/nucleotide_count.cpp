#include "nucleotide_count.h"
#include <stdexcept>
#include <unordered_map>

namespace nucleotide_count {

// TODO: add your solution here
 std::map<char, int> count(std::string_view abc){
     std::unordered_map<char, int> ref = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
     
     for (const char& letter : abc){
         if (auto it = ref.find(letter) ; it != ref.end()){ //.end() means it reached the end without finding letter
             it -> second +=1; //second refers to the value in the key:value pair
         } else {
             // did not find the letter
             throw std::invalid_argument ("invalid character");
         }
     }

     // Trick: Convert unordered_map to map (the type the test needs)
        return {ref.begin(), ref.end()};
 }
}  // namespace nucleotide_count


// better to use unordered map here but it does not pass the tests...
//auto it = ref.find(letter); //auto here means `std::map<char, int>::iterator