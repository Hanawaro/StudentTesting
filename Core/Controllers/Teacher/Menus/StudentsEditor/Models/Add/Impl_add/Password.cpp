#include "../Add.hpp"

bool Add::active_password(void) {
    draw_active_password();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::SecondName;
            break;
        case KEY_DOWN:
        case '\n':
        case '\t':
            draw();
            locale = Locale::Register;
            break;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            real_password.resize( ((int)real_password.size() - 1 < 0) ? real_password.size() : real_password.size() - 1);
            reset_password();
            draw();
            break;
        default:
            if (tmp < EOF || tmp > 127 || real_password.size() >= 255)
                return true;
            real_password += tmp;
            reset_password();
            draw();
            break;
    }
    
    return false;
}
