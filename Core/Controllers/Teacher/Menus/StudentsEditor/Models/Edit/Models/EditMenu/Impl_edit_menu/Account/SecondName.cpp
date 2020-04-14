#include "../../EditMenu.hpp"

bool EditMenu::active_second_name(void) {
    draw_active_second_name();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            deep = false;
            new_real_second_name = m_User->second_name;
            reset_second_name();
            draw();
            account_locale = AccountLocale::Name;
            break;
        case KEY_DOWN:
        case '\t':
            deep = false;
            new_real_second_name = m_User->second_name;
            reset_second_name();
            draw();
            account_locale = AccountLocale::Password;
            break;
        case KEY_RIGHT:
            deep = false;
            new_real_second_name = m_User->second_name;
            reset_second_name();
            change_locale = ChangeLocale::Marks;
            mark_locale = MarkLocale::First;
            draw();
            break;
        case KEY_LEFT:
            if (change_locale == ChangeLocale::Marks) {
                deep = false;
                new_real_second_name = m_User->second_name;
                reset_second_name();
                change_locale = ChangeLocale::Account;
                account_locale = AccountLocale::Login;
            }
            break;
        case '\n':
            if (deep) {
                if (m_User->second_name == new_real_second_name) {
                    deep = false;
                    draw();
                    draw_active_second_name();
                } else if (!new_real_second_name.size()) {
                    deep = true;
                    wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                    mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_empty_second_name))/2, error_empty_second_name.c_str());
                    wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                    draw_active_second_name();
                } else {
                    deep = false;
                    
                    // db second name
                    m_db_user.set_second_name(m_User->login, new_real_second_name);
                    m_User->second_name = new_real_second_name;
                    reset_second_name();

                    wcolor_set(m_Window, iomanager::TEXT, NULL);
                    draw();
                    
                    draw_active_second_name();
                }
            } else {
                deep = true;
                
                wcolor_set(m_Window, iomanager::DISABLE, NULL);
                draw();
                wcolor_set(m_Window, iomanager::TEXT, NULL);
                
                reset_second_name();
            }
            break;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            if (deep) {
                new_real_second_name.resize( ((int)new_real_second_name.size() - 1 < 0) ? new_real_second_name.size() : new_real_second_name.size() - 1);
                
                reset_second_name();
                draw_active_second_name();
            }
            break;
        default:
            if (deep) {
                if (tmp < EOF|| tmp > 127 || new_real_second_name.size() >= 255)
                    return true;
                
                new_real_second_name += tmp;
                reset_second_name();
                draw_active_second_name();
                break;
            }
            break;
    }
    
    return false;

}
