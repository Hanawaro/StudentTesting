#include "../Authorization.hpp"

bool Authorization::check_save(User &user) {
    std::ifstream ifsave("Source/authorization");
    
    char save_tmp_login[255];
    char save_tmp_hash[255];
    
    ifsave.read(save_tmp_login, 255);
    ifsave.read(save_tmp_hash, 255);
    
    std::string save_login = Security::Cipher::get_un_chipher(save_tmp_login).c_str();
    std::string save_password = Security::Cipher::get_un_chipher(save_tmp_hash).c_str();
    
    if (m_db_user.get_login(save_login)) {
        if (m_db_user.compare_password_hash(save_login, save_password)) {
            user.login = save_login;
            user.name = Security::Cipher::get_un_chipher(m_db_user.get_name(user.login)).c_str();
            user.second_name = Security::Cipher::get_un_chipher(m_db_user.get_second_name(user.login)).c_str();
            if (m_db_user.get_status(user.login)) {
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
