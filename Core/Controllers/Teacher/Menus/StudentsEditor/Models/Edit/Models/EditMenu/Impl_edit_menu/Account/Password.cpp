#include "../../EditMenu.hpp"

bool EditMenu::active_password(void) {
    draw_active_password();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            deep = false;
            clear_password();
            draw();
            account_locale = AccountLocale::SecondName;
            break;
        case KEY_DOWN:
        case '\t':
            deep = false;
            clear_password();
            draw();
            account_locale = AccountLocale::Exit;
            break;
        case KEY_RIGHT:
            deep = false;
            clear_password();
            change_locale = ChangeLocale::Marks;
            mark_locale = MarkLocale::First;
            draw();
            break;
        case '\n':
            if (deep) {
                if (real_password.size()) {
                    // db password
                    m_db_user.set_password(m_User->login, real_password);
                    
                    deep = false;
                    
                    clear_password();

                    wcolor_set(m_Window, iomanager::TEXT, NULL);
                    draw();
                    
                    draw_active_password();
                } else {
                    deep = true;
                    wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                    mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_empty_password))/2, error_empty_password.c_str());
                    wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                    draw_active_password();
                }
            } else {
                deep = true;
                
                wcolor_set(m_Window, iomanager::DISABLE, NULL);
                draw();
                wcolor_set(m_Window, iomanager::TEXT, NULL);
                
                draw_active_password();
            }
            break;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            clear_error();
            
            if (deep) {
                real_password.resize( ((int)real_password.size() - 1 < 0) ? real_password.size() : real_password.size() - 1);
                reset_password();
                draw_active_password();
            }
            break;
        default:
            clear_error();
            
            if (deep) {
                if (tmp < EOF || tmp > 127 || real_password.size() >= 255)
                    return true;
                
                real_password += tmp;
                reset_password();
                draw_active_password();
            }
            break;
    }
    
    return false;
}
