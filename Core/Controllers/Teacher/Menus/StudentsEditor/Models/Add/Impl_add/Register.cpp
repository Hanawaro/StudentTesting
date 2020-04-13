#include "../Add.hpp"

bool Add::active_register(void) {
    draw_active_register();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::Password;
            break;
        case KEY_LEFT:
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::Exit;
            break;
        case '\n':
            if (!real_login.size()) {
                draw();
                wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_empty_login))/2, error_empty_login.c_str());
                wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                locale = Locale::Login;
            } else if (!check_login()) {
                draw();
                wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_login))/2, error_login.c_str());
                wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                locale = Locale::Login;
            } else if (!real_name.size()) {
                draw();
                wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_empty_name))/2, error_empty_name.c_str());
                wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                locale = Locale::Name;
            } else if (!real_second_name.size()) {
                draw();
                wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_empty_second_name))/2, error_empty_second_name.c_str());
                wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                locale = Locale::SecondName;
            } else if (!real_password.size()) {
                draw();
                wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_empty_password))/2, error_empty_password.c_str());
                wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                locale = Locale::Password;
            } else {
                add_user();
                real_login = "";
                reset_login();
                
                real_name = "";
                reset_name();
                
                real_second_name = "";
                reset_second_name();
                
                real_password = "";
                reset_password();
                
                draw();
                wattron(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(sucsess_register))/2, sucsess_register.c_str());
                wattroff(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                locale = Locale::Exit;
            }
            break;
        default:
            break;
    }
    
    return false;
}
