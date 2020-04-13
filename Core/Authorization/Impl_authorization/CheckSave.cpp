#include "../Authorization.hpp"

bool Authorization::check_save(User &user) {
    std::ifstream ifsave("Source/authorization");
    
    char save_tmp_login[255];
    char save_tmp_hash[255];
    
    ifsave.read(save_tmp_login, 255);
    ifsave.read(save_tmp_hash, 255);
    
    std::string save_login = Security::Cipher::getUnChipher(save_tmp_login).c_str();
    std::string save_password = Security::Cipher::getUnChipher(save_tmp_hash).c_str();
    
    if (m_db_user.getLogin(save_login)) {
        if (m_db_user.comparePasswordHash(save_login, save_password)) {
            user.login = save_login;
            user.first_name = Security::Cipher::getUnChipher(m_db_user.getName(user.login)).c_str();
            user.second_name = Security::Cipher::getUnChipher(m_db_user.getSecondName(user.login)).c_str();
            if (m_db_user.getStatus(user.login)) {
                user.status = Status::Teacher;
            } else {
                user.status = Status::Student;
            }
            ifsave.close();
            return true;
        }
    }
    
    ifsave.close();
    
    return false;
}
