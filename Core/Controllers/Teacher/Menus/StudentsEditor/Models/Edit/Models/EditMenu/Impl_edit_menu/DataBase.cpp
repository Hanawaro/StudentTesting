#include "../EditMenu.hpp"

bool EditMenu::check_login(void) {
    clear_error();
    
    if (!new_real_login.size() && deep) {
        wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
        mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_empty_login))/2, error_empty_login.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
        return false;
    } else if (m_db_user.get_login(new_real_login) && deep) {
        wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
        mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_login))/2, error_login.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
        return false;
    }
    return true;
}

class Student EditMenu::getMarks(void) {
    return m_db_student.load_student(m_User->login);
}
