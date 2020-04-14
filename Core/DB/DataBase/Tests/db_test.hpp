#ifndef db_test_hpp
#define db_test_hpp

#include "../../Test.hpp"

#include <fstream>
#include <vector>

#include "../../Security/Hash/Hash.hpp"
#include "../../Security/Cipher/Cipher.hpp"

class db_test {
public:
    void add_test(Test& test);
    void edit_test(const Test& test);
    void remove_test(const Test& test);
    void load_tests(std::vector<Test>& tests);
protected:
    std::string m_path;
};

#endif
