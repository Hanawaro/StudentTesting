#include "../Edit.hpp"

bool Edit::active_exit(void) {

    if (!users.size()) {
        clear_data();
        wcolor_set(m_Window, iomanager::DISABLE, NULL);
        draw();
        wcolor_set(m_Window, iomanager::TEXT, NULL);
    }
    
    draw_active_exit();
    
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
        case KEY_UP:
            if (!users.size())
                return true;
            draw();
            locale = Locale::RemoveMenu;
            break;
        case '\t':
            if (!users.size())
                return true;
            draw();
            locale = Locale::Login;
            break;
        case '\n':
            is_exit = true;
            break;
        default:
            break;
    }

    return false;
}
