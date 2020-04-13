#include "../Add.hpp"

bool Add::active_second_name(void) {
    draw_active_second_name();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::Name;
            break;
        case KEY_DOWN:
        case '\n':
        case '\t':
            draw();
            locale = Locale::Password;
            break;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            real_second_name.resize( ((int)real_second_name.size() - 1 < 0) ? real_second_name.size() : real_second_name.size() - 1);
            reset_second_name();
            draw();
            break;
        default:
            if (tmp < EOF || tmp > 127 || real_second_name.size() >= 255)
                return true;
            real_second_name += tmp;
            reset_second_name();
            draw();
            break;
    }
    
    return false;
}
