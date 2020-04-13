#include "Core.hpp"

void Core::Start(void) {
    bool loop = false;
    do {
        User user = authorization.authorization();
        if (user.status == Status::Teacher) {
            loop = teacher.open(user);
        } else if (user.status == Status::Student) {
            loop = student.open(user);
        } else {
            loop = false;
        }
    } while (loop);
}
