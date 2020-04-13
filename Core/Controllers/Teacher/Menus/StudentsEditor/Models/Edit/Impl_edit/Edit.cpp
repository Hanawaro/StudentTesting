#include "../Edit.hpp"

bool Edit::active_edit(void) {
    draw_active_edit();
    
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
                real_name = users[user_index].first_name;
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
                real_name = users[user_index].first_name;
                reset_change();
                draw();
            }
            break;
        case KEY_UP:
            draw();
            locale = Locale::ChangeBar;
            break;
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::RemoveMenu;
            break;
        case '\n':
            editMenu.open(&users[user_index]);
            real_login = users[user_index].login;
            reset_login();
            real_name = users[user_index].first_name;
            reset_change();
            draw();
            break;
        default:
            break;
    }
    
    return false;

}
