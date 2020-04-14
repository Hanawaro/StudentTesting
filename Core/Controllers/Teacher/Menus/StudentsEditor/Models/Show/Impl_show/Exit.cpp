#include "../Show.hpp"

bool Show::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::TotalMenu;
            break;
        case '\t':
            draw();
            locale = Locale::StudentsMenu;
            break;
        case '\n':
            is_exit = true;
            break;
        default:
            break;
    }

    return false;
}
