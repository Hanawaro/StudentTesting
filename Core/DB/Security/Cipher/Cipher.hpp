#ifndef Cipher_hpp
#define Cipher_hpp

#include <iostream>
#include <string>

namespace Security { namespace Cipher {
    const std::string key = "GodSay1488";
    std::string getChipher(std::string text);
    std::string getUnChipher(std::string text);
}; };

#endif
