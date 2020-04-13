#include "../Add.hpp"

bool Add::active_name(void) {
    draw_active_name();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::Login;
            break;
        case KEY_DOWN:
        case '\n':
        case '\t':
            draw();
            locale = Locale::SecondName;
            break;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            real_name.resize( ((int)real_name.size() - 1 < 0) ? real_name.size() : real_name.size() - 1);
            reset_name();
            draw();
            break;
        default:
            if (tmp < EOF || tmp > 127 || real_name.size() >= 255)
                return true;
            real_name += tmp;
            reset_name();
            draw();
            break;
    }
    
    return false;
}
