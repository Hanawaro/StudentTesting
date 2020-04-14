#include "../../EditMenu.hpp"

bool EditMenu::active_name(void) {
    draw_active_name();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            deep = false;
            new_real_name = m_User->name;
            reset_name();
            draw();
            account_locale = AccountLocale::Login;
            break;
        case KEY_DOWN:
        case '\t':
            deep = false;
            new_real_name = m_User->name;
            reset_name();
            draw();
            account_locale = AccountLocale::SecondName;
            break;
        case KEY_RIGHT:
            deep = false;
            new_real_name = m_User->name;
            reset_name();
            change_locale = ChangeLocale::Marks;
            mark_locale = MarkLocale::First;
            draw();
            break;
        case '\n':
            if (deep) {
                if (m_User->name == new_real_name) {
                    deep = false;
                    draw();
                    draw_active_name();
                } else if (!new_real_name.size()) {
                    deep = true;
                    wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                    mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_empty_name))/2, error_empty_name.c_str());
                    wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                    draw_active_name();
                } else {
                    deep = false;
                    
                    // db second name
                    m_db_user.set_name(m_User->login, new_real_name);
                    m_User->name = new_real_name;
                    reset_name();

                    wcolor_set(m_Window, iomanager::TEXT, NULL);
                    draw();
                    
                    draw_active_name();
                }
            } else {
                deep = true;
                
                wcolor_set(m_Window, iomanager::DISABLE, NULL);
                draw();
                wcolor_set(m_Window, iomanager::TEXT, NULL);
                
                reset_name();
            }
            break;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            if (deep) {
                new_real_name.resize( ((int)new_real_name.size() - 1 < 0) ? new_real_name.size() : new_real_name.size() - 1);
                
                reset_name();
                draw_active_name();
            }
            break;
        default:
            if (deep) {
                if (tmp < EOF|| tmp > 127 || new_real_name.size() >= 255)
                    return true;
                
                new_real_name += tmp;
                reset_name();
                draw_active_name();
                break;
            }
            break;
    }
    
    return false;
}
