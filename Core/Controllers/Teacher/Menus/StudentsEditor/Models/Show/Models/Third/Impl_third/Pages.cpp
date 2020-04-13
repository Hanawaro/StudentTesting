#include "../Third.hpp"

bool Third::active_pages(void) {
    draw_active_pages();
    
    if (empty) {
        draw();
        locale = Locale::Exit;
        return true;
    }
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_RIGHT:
            if (page < pages) {
                page++;
                draw();
            }
            break;
        case KEY_LEFT:
            if (page > 1) {
                page--;
                draw();
            }
        break;
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::Exit;
            break;
        case KEY_UP:
            draw();
            locale = Locale::Change;
            break;
        default:
            break;
    }

    return false;}
