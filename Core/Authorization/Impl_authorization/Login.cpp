#include "../Authorization.hpp"

bool Authorization::active_login(void) {
    
    draw_active_login();

    int tmp = wgetch(m_Window);

    switch (tmp) {
        case KEY_LEFT:
        case KEY_RIGHT:
        case KEY_UP:
            break;
        case '\t':
        case '\n':
        case KEY_DOWN:
            draw();
            locale = Locale::Password;
            break;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            real_login.resize( ((int)real_login.size() - 1 < 0) ? real_login.size() : real_login.size() - 1);
            reset_show_login();
            draw();
            break;
        default:
            if (tmp < EOF || tmp > 127 || real_login.size() >= 255)
                return true;
            real_login += tmp;
            reset_show_login();
            draw();
            break;
    }
    
    return false;
}
