#include "../Students.hpp"

bool Students::active_change(void) {
    draw_active_change();
        
    if (empty) {
        draw();
        locale = Locale::Exit;
        return true;
    }
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_DOWN:
        case '\t':
            locale = Locale::Pages;
            draw();
            break;
        case KEY_LEFT:
            if (sort == Sort::down) {
                sort = Sort::up;
                page = 1;
            }
            draw();
            break;
        case KEY_RIGHT:
            if (sort == Sort::up) {
                sort = Sort::down;
                page = 1;
            }
            draw();
            break;
        default:
            break;
    }

    return false;
}
