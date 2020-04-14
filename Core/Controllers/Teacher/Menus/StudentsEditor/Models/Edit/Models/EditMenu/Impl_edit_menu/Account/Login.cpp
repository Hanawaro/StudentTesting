#include "../../EditMenu.hpp"

bool EditMenu::active_login(void) {
    draw_active_login();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            deep = false;
            new_real_login = m_User->login;
            reset_login();
            draw();
            account_locale = AccountLocale::Change;
            break;
        case KEY_DOWN:
        case '\t':
            deep = false;
            new_real_login = m_User->login;
            reset_login();
            draw();
            account_locale = AccountLocale::Name;
            break;
        case KEY_RIGHT:
            deep = false;
            new_real_login = m_User->login;
            reset_login();
            change_locale = ChangeLocale::Marks;
            mark_locale = MarkLocale::First;
            draw();
            break;
        case '\n':
            if (deep) {
                if (m_User->login == new_real_login) {
                    deep = false;

                    wcolor_set(m_Window, iomanager::TEXT, NULL);
                    draw();
                    
                    draw_active_login();
                } if (check_login()) {
                    deep = false;
                    
                    m_db_user.set_login(m_User->login, new_real_login);
            
                    m_User->login = new_real_login;
                    
                    reset_login();
                    
                    wcolor_set(m_Window, iomanager::TEXT, NULL);
                    draw();
                    
                    draw_active_login();
                } else {
                    deep = true;
                }
            } else {
                deep = true;
                
                wcolor_set(m_Window, iomanager::DISABLE, NULL);
                draw();
                wcolor_set(m_Window, iomanager::TEXT, NULL);
                
                draw_active_login();
            }
            break;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            clear_error();
            
            if (deep) {
                new_real_login.resize( ((int)new_real_login.size() - 1 < 0) ? new_real_login.size() : new_real_login.size() - 1);
                reset_login();
                draw_active_login();
            }
            break;
        default:
            clear_error();
            
            if (deep) {
                if (tmp < EOF || tmp > 127 || new_real_login.size() >= 255)
                    return true;
                
                new_real_login += tmp;
                reset_login();
                draw_active_login();
            }
            break;
    }
    
    return false;
}
