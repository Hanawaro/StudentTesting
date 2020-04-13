#ifndef Hash_hpp
#define Hash_hpp

#include <iostream>
#include <string>

namespace Security { namespace Hash {
    std::string getHash(std::string text);
    std::string getHashWithSult(std::string text);
}; };

#endif
