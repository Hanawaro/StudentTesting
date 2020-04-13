#ifndef iomanager_hpp
#define iomanager_hpp

#include <iostream>
#include <string>
#include <vector>

namespace iomanager {
    enum Pairs {
        TEXT,
        SUCSESS,
        WARNING,
        ERROR,
        ACTIVE,
        DISABLE,
        SORT
    };
    size_t strlen(const std::string& str);
}

#endif
