#include "../Profile.hpp"

bool Profile::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::Password;
            break;
        case '\t':
            draw();
            locale = Locale::Login;
            break;
        case '\n':
            isExit = true;
            break;
        default:
            break;
    }
    
    return false;
}
