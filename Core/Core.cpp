#include "Core.hpp"

void Core::start(void) {
    bool loop = false;
    do {
        User user = m_authorization.authorization();
        if (user.status == Status::Teacher) {
            loop = m_teacher.open(user);
        } else if (user.status == Status::Student) {
            loop = m_student.open(user);
        } else {
            loop = false;
        }
    } while (loop);
}
