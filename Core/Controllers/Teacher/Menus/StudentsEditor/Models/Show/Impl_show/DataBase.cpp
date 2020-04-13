#include "../Show.hpp"

void Show::load_users(void) {
    users.clear();
    m_db_user.load_users(users);
}
