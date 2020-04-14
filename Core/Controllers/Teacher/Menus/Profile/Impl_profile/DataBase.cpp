#include "../Profile.hpp"

bool Profile::check_login(void) {
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

bool Profile::check_password(void) {
    clear_error();
    
    if (!real_old_pass.size() && deep) {
        wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
        mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_empty_old_password))/2, error_empty_old_password.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
        return false;
    } else if (!m_db_user.compare_password_hash(m_User->login, Security::Hash::get_hash_with_sult(real_old_pass)) && deep) {
        wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
        mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_passwords))/2, error_passwords.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
        return false;
    } else if (!real_new_pass.size() && deep && deepPassword) {
        wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
        mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_empty_new_password))/2, error_empty_new_password.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
        return false;
    }
    
    return true;
}
