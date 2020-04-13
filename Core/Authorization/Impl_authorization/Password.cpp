#include "../Authorization.hpp"

bool Authorization::active_password(void) {
    
    draw_active_password();

    int tmp = wgetch(m_Window);

    switch (tmp) {
        case KEY_LEFT:
        case KEY_RIGHT:
            break;
        case KEY_UP:
            draw();
            locale = Locale::Login;
            break;
        case '\t':
        case '\n':
        case KEY_DOWN:
            draw();
            locale = Locale::Save;
            break;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            real_password.resize( ((int)real_password.size() - 1 < 0) ? real_password.size() : real_password.size() - 1);
            reset_show_password();
            draw();
            break;
        default:
            if (tmp < EOF || tmp > 127 || real_password.size() >= 255)
                return true;
            real_password += tmp;
            reset_show_password();
            draw();
            break;
    }
    
    return false;
}
