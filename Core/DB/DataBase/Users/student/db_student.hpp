#ifndef db_student_hpp
#define db_student_hpp

#include <fstream>

#include "../../../User.hpp"
#include "../../../Security/Hash/Hash.hpp"
#include "../../../Security/Cipher/Cipher.hpp"

class db_student {
public:
    void set_login(const std::string& key, const std::string& login) const;
    void set_first(const std::string& key, Mark first, int32_t amount) const;
    void set_second(const std::string& key, Mark second, int32_t amount) const;
    void set_third(const std::string& key, Mark third, int32_t amount) const;
    void set_total(const std::string& key, Mark total, int32_t amount) const;
        
    void add_student(const std::string& key, Mark first, int32_t amount_of_first, Mark second, int32_t amount_of_second, Mark third, int32_t amount_of_third, Mark total, int32_t amount_of_total) const;
    void remove_student(const std::string& key);
    
    class Student load_student(const std::string& key) const;
private:
    const std::string m_path = "Source/Users/student";
};

#endif
