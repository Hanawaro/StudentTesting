#ifndef Test_h
#define Test_h

#include <string>

struct Test {
    uint32_t id;
    std::string question;
    std::string answer[3];
    uint32_t right;
};

#endif
