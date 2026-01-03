#include "atbash_cipher.h"
#include <cctype>
namespace atbash_cipher {
constexpr int sum_of_ax = 219; // 'a' + 'z' = 219
    
std::string encode (std::string_view abc){
    std::string zyx = "";
    zyx.reserve(abc.length() + (abc.length() / 5));
    int count = 0;
    for (unsigned char letter : abc){
        if(count == 5 && (isalpha(letter) || isdigit(letter)) ){
            zyx += ' ';
            count = 0; 
        }
        
        if (isalpha(letter)){
        zyx += static_cast<char>(sum_of_ax - tolower(letter));
            count += 1;
        } else if(isdigit(letter)){
            zyx += letter;
            count += 1;
        }
    }
    return zyx;
}

std::string decode (std::string_view zyx){
    std::string abc = "";
    abc.reserve(zyx.length());
    for (unsigned char letter : zyx){
        if (isalpha(letter) ){
            abc += static_cast<char>(sum_of_ax - tolower(letter));
        } else if(isdigit(letter)){
            abc += letter;
        }
    }

    return abc;
}
}  // namespace atbash_cipher
