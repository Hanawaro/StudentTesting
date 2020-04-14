#include "../Edit.hpp"

bool Edit::active_remove(void) {
    draw_active_remove();
    
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
        case KEY_UP:
            draw();
            locale = Locale::EditMenu;
            break;
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::Exit;
            break;
        case '\n':
            m_db_user.remove_user(users[user_index].login);
            
            users.erase(users.begin() + user_index);
            
            if (user_index > users.size() - 1)
                user_index = 0;
            
            if (users.size()) {
                real_login = users[user_index].login;
                reset_login();
                real_name = users[user_index].name;
                reset_change();
                draw();
            } else {
                locale = Locale::Exit;
            }
            break;
        default:
            break;
    }
    
    return false;
}
