#include "../Add.hpp"

bool Add::active_login(void) {
    draw_active_login();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_DOWN:
        case '\n':
        case '\t':
            draw();
            locale = Locale::Name;
            break;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            real_login.resize( ((int)real_login.size() - 1 < 0) ? real_login.size() : real_login.size() - 1);
            reset_login();
            draw();
            break;
        default:
            if (tmp < EOF || tmp > 127 || real_login.size() >= 255)
                return true;
            real_login += tmp;
            reset_login();
            draw();
            break;
    }
    
    return false;
}
