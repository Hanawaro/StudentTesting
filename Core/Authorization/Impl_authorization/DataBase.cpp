#include "../Authorization.hpp"

bool Authorization::search_user(void) {
    if (!find_login())
        return false;
    if (!compare_password_hash())
        return false;
    return true;
}

bool Authorization::find_login(void) {
    if (m_db_user.getLogin(real_login))
        return true;
    return false;
}

bool Authorization::compare_password_hash(void) {
    std::string locale_hash = Security::Hash::getHashWithSult(real_password);
    return m_db_user.comparePasswordHash(real_login, locale_hash);}
