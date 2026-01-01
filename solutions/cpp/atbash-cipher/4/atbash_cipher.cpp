#include "atbash_cipher.h"
#include <map>
#include <cctype>
namespace atbash_cipher {
const int sum_of_ax = 219;
    
std::string encode (std::string_view abc){
    std::string zyx = "";
    zyx.reserve(abc.length() * 1.2);
    int a = 0;
    for (unsigned char letter : abc){
        if(a==5 && (isalpha(letter) || isdigit(letter)) ){
            zyx += ' ';
            a = 0; 
        }
        
        if (isalpha(letter)){
        zyx += char(sum_of_ax - tolower(letter));
            a += 1;
        } else if(isdigit(letter)){
            zyx += letter;
            a+=1;
        }
    }
    return zyx;
}


std::string decode (std::string_view zyx){
    std::string abc = "";
    abc.reserve(zyx.length());
    for (unsigned char letter : zyx){
        if (isalpha(letter) ){
            abc += sum_of_ax - tolower(letter);
        } else if(isdigit(letter)){
            abc += letter;
        }
    }

    return abc;
}
}  // namespace atbash_cipher
