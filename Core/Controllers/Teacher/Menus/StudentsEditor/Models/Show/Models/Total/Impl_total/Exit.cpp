#include "../Total.hpp"

bool Total::active_exit(void) {
    if (empty) {
        wcolor_set(m_Window, iomanager::DISABLE, NULL);
        draw();
        wcolor_set(m_Window, iomanager::TEXT, NULL);
    }
    
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case '\t':
            if (!empty) {
                locale = Locale::Change;
                draw();
            }
            break;
        case KEY_UP:
            if (!empty) {
                locale = Locale::Pages;
                draw();
            }
            break;
        case KEY_LEFT:
            if (sort == Sort::down && !empty) {
                sort = Sort::up;
                page = 1;
                draw();
            }
            break;
        case KEY_RIGHT:
            if (sort == Sort::up && !empty) {
                sort = Sort::down;
                page = 1;
                draw();
            }
            break;
        case '\n':
            is_exit = true;
            break;
        default:
            break;
    }

    return false;
}
