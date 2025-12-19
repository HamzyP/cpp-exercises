#include "rna_transcription.h"
#include <map>
namespace rna_transcription {

std::string to_rna(std::string abc){
    std::map<char, char> ref = {{'G', 'C'},
            {'C', 'G'},
    {'T' , 'A'},
    {'A' , 'U'}};

    // int count = 0;
    for (char& letter : abc){
        if (ref.count(letter)){
            letter = ref[letter];
        }
    }

    return abc;
}

char to_rna(char abc){
    std::map<char, char> ref = {{'G', 'C'},
            {'C', 'G'},
    {'T' , 'A'},
    {'A' , 'U'}};

    // int count = 0;

    abc = ref[abc];

    return abc;
}
}  // namespace rna_transcription
