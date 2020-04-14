#include "../Add.hpp"

bool Add::check_login(void) {
    if (m_db_user.get_login(real_login))
        return false;
    return true;
}

void Add::add_user(void) {
    int status = 404;
    do {
        status = rand() % 1488;
    } while (status == 404);
    m_db_user.add_user(real_login, status, real_name, real_second_name, real_password);
}
