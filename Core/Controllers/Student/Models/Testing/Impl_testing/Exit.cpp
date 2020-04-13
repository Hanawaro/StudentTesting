#include "../Testing.hpp"

bool Testing::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_DOWN:
            break;
        case '\t':
            if (!empty && !isAll) {
                locale = Locale::First;
                right_answer = 1;
                draw();
            }
            break;
        case KEY_UP:
            if (!empty && !isAll) {
                locale = Locale::Third;
                right_answer = 3;
                draw();
            }
            break;
        case '\n':
            // result
            if (!isAll && !empty) {
                isAll = true;
            } else if (empty) {
                isExit = true;
            } else {
                set_new_result();
                isExit = true;
            }
            draw();
            break;
        default:
            break;
    }

    return false;}
