#include "../Student.hpp"

void StudentMenu::load_student(void) {
    m_Student = m_db_student.load_student(m_User.login);
}
