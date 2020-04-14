#include "../Edit.hpp"

bool Edit::active_login(void) {
    draw_active_login();
    
    if (!users.size()) {
        locale = Locale::Exit;
        return true;
    }
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_RIGHT:
            if (users.size()) {
                if (user_index + 1 < users.size()) {
                    user_index++;
                } else {
                    user_index = 0;
                }
                real_login = users[user_index].login;
                reset_login();
                real_name = users[user_index].name;
                reset_change();
                draw();
            }
            break;
        case KEY_LEFT:
            if (users.size()) {
                if (user_index - 1 >= 0) {
                    user_index--;
                } else {
                    user_index = (int) users.size() - 1;
                }
                real_login = users[user_index].login;
                reset_login();
                real_name = users[user_index].name;
                reset_change();
                draw();
            }
            break;
        case KEY_DOWN:
        case '\t':
            locale = Locale::ChangeBar;
            real_login = users[user_index].login;
            reset_login();
            deep = false;
            draw();
            break;
        case '\n':
            if (deep) {
                bool flag = false;
                size_t i;
                for (i = 0; i < users.size(); i++)
                    if (users[i].login == real_login) {
                        flag = true;
                        break;
                    }
                if (flag) {
                    deep = false;
                    
                    user_index = (int) i;
                    real_login = users[user_index].login;
                    reset_login();
                    real_name = users[user_index].name;
                    reset_change();
                    draw();
                    locale = Locale::ChangeBar;
                } else if (!real_login.size()) {
                    deep = true;
                    
                    wcolor_set(m_Window, iomanager::DISABLE, NULL);
                    draw();
                    wcolor_set(m_Window, iomanager::TEXT, NULL);
                    
                    wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                    mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_empty_login))/2, error_empty_login.c_str());
                    wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                } else {
                    deep = true;
                    
                    wcolor_set(m_Window, iomanager::DISABLE, NULL);
                    draw();
                    wcolor_set(m_Window, iomanager::TEXT, NULL);
                    
                    wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                    mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(error_login))/2, error_login.c_str());
                    wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
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
            if (deep) {
                real_login.resize( ((int)real_login.size() - 1 < 0) ? real_login.size() : real_login.size() - 1);
                reset_login();
                
                wcolor_set(m_Window, iomanager::DISABLE, NULL);
                draw();
                wcolor_set(m_Window, iomanager::TEXT, NULL);
                
                draw_active_login();
            }
            break;
        default:
            if (deep) {
                if (tmp < EOF|| tmp > 127 || real_login.size() >= 255)
                    return true;
                
                real_login += tmp;
                reset_login();
                
                wcolor_set(m_Window, iomanager::DISABLE, NULL);
                draw();
                wcolor_set(m_Window, iomanager::TEXT, NULL);
                
                draw_active_login();
            }
            break;
    }

    return false;
}
