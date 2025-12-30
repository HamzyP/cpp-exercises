#include "atbash_cipher.h"
#include <map>
#include <cctype>
namespace atbash_cipher {
    
    
std::string encode (std::string_view abc){
    std::string zyx = "";
    int a = 0;
    for (const char& letter : abc){
        if(a==5 && (isalpha(letter) || isdigit(letter)) ){
            zyx += ' ';
            a = 0; 
        }
        
        if (isalpha(letter)){
        zyx += char(219 - tolower(letter));
            a += 1;
        } else if(isdigit(letter)){
            zyx += letter;
            a+=1;
        }
    }
    return zyx;
}


std::string decode (std::string_view zyx){
    //strip the spaces with space
    std::string abc = "";
    for (const char& letter : zyx){
        if (isalpha(letter) ){
            abc += 219 - tolower(letter);
        } else if(isdigit(letter)){
            abc += letter;
        }
    }

    return abc;
}
}  // namespace atbash_cipher
