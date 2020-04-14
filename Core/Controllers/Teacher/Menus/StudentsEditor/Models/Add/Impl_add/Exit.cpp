#include "../Add.hpp"

bool Add::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::Password;
            break;
        case KEY_RIGHT:
            draw();
            locale = Locale::Register;
            break;
        case '\t':
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
