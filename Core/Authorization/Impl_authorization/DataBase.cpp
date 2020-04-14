#include "../Authorization.hpp"

bool Authorization::search_user(void) {
    if (!find_login())
        return false;
    if (!compare_password_hash())
        return false;
    return true;
}

bool Authorization::find_login(void) {
    if (m_db_user.get_login(real_login))
        return true;
    return false;
}

bool Authorization::compare_password_hash(void) {
    std::string locale_hash = Security::Hash::get_hash_with_sult(real_password);
    return m_db_user.compare_password_hash(real_login, locale_hash);}
