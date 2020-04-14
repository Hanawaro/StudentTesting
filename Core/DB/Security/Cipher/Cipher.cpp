#include "Cipher.hpp"

std::string Security::Cipher::get_chipher(const std::string text) {
    std::string result(255, '\0');
    
    for (int i = 0; i < text.size() && i + 1 < 255; i++)
        if (text[i] + 3 > 127) {
            result[i] = text[i] + 3 - 127;
            result[i + 1] = '\0' + 3;
        }
        else {
            result[i] = text[i] + 3;
            result[i + 1] = '\0' + 3;
        }
    
    return result;
}

std::string Security::Cipher::get_un_chipher(const std::string text) {
    std::string result(255, '\0');
    
    for (int i = 0; i < text.size() && i + 1 < 255; i++)
    if (text[i] - 3 < -128)
        result[i] = text[i] - 3 + 127;
    else
        result[i] = text[i] - 3;
    
    return result;
}
