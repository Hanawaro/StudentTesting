#include "../Authorization.hpp"

bool Authorization::active_enter(void) {
    
    draw_active_enter();

    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case '\n':
            if (!real_login.size()) {
                isAuth = false;

                for (size_t i = 0; i < show_password.size(); i++)
                    show_password[i] = ' ';
                
                draw();

                wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(empty_login)) / 2, empty_login.c_str());
                wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));

                real_password = "";
                show_password = "";
                
                locale = Locale::Login;
            } else if (!show_password.size()) {
                isAuth = false;

                draw();
                
                wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(empty_password)) / 2, empty_password.c_str());
                wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));

                locale = Locale::Password;
            } else {
                // search in DB
                if (search_user()) {
                    isAuth = true;
                } else {
                    isAuth = false;

                    for (size_t i = 0; i < show_password.size(); i++)
                        show_password[i] = ' ';
                    
                    draw();

                    wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                    mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(not_found)) / 2, not_found.c_str());
                    wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                    
                    real_password = "";
                    show_password = "";

                    locale = Locale::Login;
                }
            }
            break;
        case '\t':
        case KEY_DOWN:
        case KEY_LEFT:
            draw();
            locale = Locale::Exit;
            break;
        case KEY_UP:
            draw();
            locale = Locale::Save;
            break;
        default:
            break;
    }
    
    return false;
}
