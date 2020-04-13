#include "iomanager.hpp"

size_t iomanager::strlen(const std::string& str) {
    size_t size = 0;
    bool status = false;
    if (str[0] < EOF)
        status = true;
    for (int i = 0; str[i]; i++) {
        if (status) {
            status = false;
            continue;
        }
        if (str[i] < EOF)
            status = true;
        size++;
    }
    return size;
}

