#ifndef Hash_hpp
#define Hash_hpp

#include <iostream>
#include <string>

namespace Security { namespace Hash {
    std::string get_hash(const std::string text);
    std::string get_hash_with_sult(const std::string text);
}; };

#endif
