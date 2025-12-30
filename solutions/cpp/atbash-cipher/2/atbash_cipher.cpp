#include "atbash_cipher.h"
#include <map>
#include <cctype>
namespace atbash_cipher {
    
    
std::string encode (std::string_view abc){
    std::string zyx = "";
    for (const char& letter : abc){
        if (isalpha(letter) ){
        zyx += char(219 - tolower(letter));
        } else if(isdigit(letter)){
            zyx += letter;
        }
    }


    //outputting with space
    std::string zyx2 ="";
    int a = 0;
    for (size_t i =0; i <zyx.length(); i++){
        if (a ==5){
            a = 1;
            zyx2 += ' ';
            zyx2 += zyx[i];
        }else{
            zyx2 += zyx[i];
            a += 1;
        }
    }
    
    return zyx2;
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
