#ifndef db_user_hpp
#define db_user_hpp

#include "../../../User.hpp"
#include "../student/db_student.hpp"

#include <fstream>
#include <vector>

#include "../../../Security/Hash/Hash.hpp"
#include "../../../Security/Cipher/Cipher.hpp"

class db_user final {
public:
    bool getLogin(const std::string& key) const;
    bool getStatus(const std::string& key) const;
    std::string getName(const std::string& key) const;
    std::string getSecondName(const std::string& key) const;
    std::string getPasswordHash(const std::string& key) const;
    
    bool comparePasswordHash(const std::string& key, const std::string& hash) const;
    
    void setLogin(const std::string& key, const std::string& login) const;
    void setName(const std::string& key, const std::string& name) const;
    void setSecondName(const std::string& key, const std::string& secondName) const;
    void setPassword(const std::string& key, const std::string& password) const;
    
    void addUser(const std::string& login, uint32_t status, const std::string& name, const std::string& secondName, const std::string& password) const;
    void removeUser(const std::string& key);
    
    User load_user(int index) const;
    User load_user(const std::string& key) const;
    void load_users(std::vector<User>& users);
    void load_users(std::vector<info_student>& users);
private:
    db_student m_db_student;
    
    const std::string m_Path = "Source/Users/user";
};

#endif
