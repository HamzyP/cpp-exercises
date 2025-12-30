#include "atbash_cipher.h"
#include <map>
#include <cctype>
namespace atbash_cipher {
    
const std::map<char, char> lookup_table = {
    { 'a', 'z' }, { 'b', 'y' }, { 'c', 'x' }, { 'd', 'w' },
    { 'e', 'v' }, { 'f', 'u' }, { 'g', 't' }, { 'h', 's' },
    { 'i', 'r' }, { 'j', 'q' }, { 'k', 'p' }, { 'l', 'o' },
    { 'm', 'n' }, { 'n', 'm' }, { 'o', 'l' }, { 'p', 'k' },
    { 'q', 'j' }, { 'r', 'i' }, { 's', 'h' }, { 't', 'g' },
    { 'u', 'f' }, { 'v', 'e' }, { 'w', 'd' }, { 'x', 'c' },
    { 'y', 'b' }, { 'z', 'a' }
};

    
// TODO: add your solution here
std::string encode (std::string_view abc){
    std::string zyx = "";
    for (const char& letter : abc){
        if (isalpha(letter) ){
        zyx += lookup_table.at(tolower(letter));
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
            abc += lookup_table.at(tolower(letter));
        } else if(isdigit(letter)){
            abc += letter;
        }
    }

    return abc;
}
}  // namespace atbash_cipher
