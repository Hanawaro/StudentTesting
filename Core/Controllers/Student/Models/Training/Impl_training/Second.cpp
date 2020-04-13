#include "../Training.hpp"

bool Training::active_second(void) {
    draw_active_second();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_DOWN:
        case '\t':
            locale = Locale::Third;
            right_answer = 3;
            draw();
            break;
        case KEY_UP:
            locale = Locale::First;
            right_answer = 1;
            draw();
            break;
        case '\n':
            if (right_answer == tests[randomize[0]].right) {
                reset_test();
            } else {
                isError = true;
            }
            draw();
            break;
        default:
            break;
    }

    return false;
}
