#ifndef Cipher_hpp
#define Cipher_hpp

#include <iostream>
#include <string>

namespace Security { namespace Cipher {
    std::string get_chipher(const std::string text);
    std::string get_un_chipher(const std::string text);
}; };

#endif
