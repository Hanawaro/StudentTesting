#ifndef db_test_second_hpp
#define db_test_second_hpp

#include "../../../Test.hpp"

#include <fstream>
#include <vector>

#include "../../../Security/Hash/Hash.hpp"
#include "../../../Security/Cipher/Cipher.hpp"

class db_test_second final {
public:
    void add_test(Test& test);
    void edit_test(const Test& test);
    void remove_test(const Test& test);
    void load_tests(std::vector<Test>& tests);
private:
    const std::string m_Path = "Source/Tests/secondTest";
};

#endif
