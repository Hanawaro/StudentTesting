#include "Cipher.hpp"

std::string Security::Cipher::getChipher(std::string text) {
    std::string result(255, '\0');
    
    for (int i = 0; i <= text.size(); i++)
        if (text[i] + 3 > 127)
            result[i] = text[i] + 3 - 127;
        else
            result[i] = text[i] + 3;
    
    return result;
}

std::string Security::Cipher::getUnChipher(std::string text) {
    std::string result(255, '\0');
    
    for (int i = 0; i <= text.size(); i++)
    if (text[i] - 3 < -128)
        result[i] = text[i] - 3 + 127;
    else
        result[i] = text[i] - 3;
    
    return result;
}
