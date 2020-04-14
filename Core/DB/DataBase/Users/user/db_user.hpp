#ifndef db_user_hpp
#define db_user_hpp

#include <vector>

#include "../student/db_student.hpp"

class db_user final {
public:
    bool get_login(const std::string& key) const;
    bool get_status(const std::string& key) const;
    std::string get_name(const std::string& key) const;
    std::string get_second_name(const std::string& key) const;
    std::string get_password_hash(const std::string& key) const;
    
    bool compare_password_hash(const std::string& key, const std::string& hash) const;
    
    void set_login(const std::string& key, const std::string& login) const;
    void set_name(const std::string& key, const std::string& name) const;
    void set_second_name(const std::string& key, const std::string& secondName) const;
    void set_password(const std::string& key, const std::string& password) const;
    
    void add_user(const std::string& login, uint32_t status, const std::string& name, const std::string& secondName, const std::string& password) const;
    void remove_user(const std::string& key);
    
    User load_user(int index) const;
    User load_user(const std::string& key) const;
    void load_users(std::vector<User>& users);
    void load_users(std::vector<info_student>& users);
private:
    db_student m_db_student;
    
    const std::string m_path = "Source/Users/user";
};

#endif
