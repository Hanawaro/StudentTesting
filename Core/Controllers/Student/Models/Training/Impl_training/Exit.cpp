#include "../Training.hpp"

bool Training::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_DOWN:
            break;
        case '\t':
            if (!empty) {
                locale = Locale::First;
                right_answer = 1;
                draw();
            }
            break;
        case KEY_UP:
            if (!empty) {
                locale = Locale::Third;
                right_answer = 3;
                draw();
            }
            break;
        case '\n':
            isExit = true;
            draw();
            break;
        default:
            break;
    }

    return false;
}
