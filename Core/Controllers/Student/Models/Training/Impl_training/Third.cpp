#include "../Training.hpp"

bool Training::active_third(void) {
    draw_active_third();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_DOWN:
        case '\t':
            locale = Locale::Exit;
            draw();
            break;
        case KEY_UP:
            locale = Locale::Second;
            right_answer = 2;
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
