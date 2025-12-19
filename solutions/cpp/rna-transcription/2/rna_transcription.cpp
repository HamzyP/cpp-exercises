#include "rna_transcription.h"
#include <map>
namespace rna_transcription {
char to_rna(char nucle){
    switch (nucle) {
        case 'G' :return 'C';
        case 'C' :return 'G';
        case 'T' :return 'A';
        case 'A' :return 'U';
        default: return nucle;
    }
}
    
    
std::string to_rna(std::string seq){
    for (char& nucle : seq){
        nucle = to_rna(nucle);
    }
    return seq;
}
}  // namespace rna_transcription
