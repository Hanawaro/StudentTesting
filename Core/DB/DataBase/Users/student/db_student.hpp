#ifndef db_student_hpp
#define db_student_hpp

#include "../../../User.hpp"

#include <fstream>

#include "../../../Security/Hash/Hash.hpp"
#include "../../../Security/Cipher/Cipher.hpp"

class db_student {
public:
    void setLogin(const std::string& key, const std::string& login) const;
    void setFirst(const std::string& key, Mark first, int32_t amount) const;
    void setSecond(const std::string& key, Mark second, int32_t amount) const;
    void setThird(const std::string& key, Mark third, int32_t amount) const;
    void setTotal(const std::string& key, Mark total, int32_t amount) const;
        
    void addStudent(const std::string& key, Mark first, int32_t amount_of_first, Mark second, int32_t amount_of_second, Mark third, int32_t amount_of_third, Mark total, int32_t amount_of_total) const;
    void removeStudent(const std::string& key);
    
    class Student load_student(const std::string& key) const;
private:
    const std::string m_Path = "Source/Users/student";
};

#endif
