#include "hexadecimal.h"


// Implemented horners method instead of using pow

namespace hexadecimal {

constexpr bool is_valid_letter(char letter){
    return letter >= 'a' && letter <= 'f';
}
    
int convert(std::string_view hex){
    
    int count = 0;
    for (const char& letter : hex){
        // if it is a hex letter (a-f)
        if(is_valid_letter(letter)){
            int val = letter - 'a' + 10;
            count = (count << 4) + val;
        } else {
            if (isalpha(letter)){ // must be a non valid hex letter
                return 0;
            }
            // Handle digits (0-9)
            int val = int(letter - '0'); // turns the char into an int
            count = (count << 4) + val; 
        }
    }

    return count;
}
}  // namespace hexadecimal
