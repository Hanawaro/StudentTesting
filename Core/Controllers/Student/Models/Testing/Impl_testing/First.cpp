#include "../Testing.hpp"

bool Testing::active_first(void) {
    draw_active_first();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_DOWN:
        case '\t':
            locale = Locale::Second;
            right_answer = 2;
            draw();
            break;
        case KEY_UP:
            break;
        case '\n':
            if (right_answer == tests[randomize[0]].right) {
                right_answers++;
            }
            reset_test();
            draw();
            break;
        default:
            break;
    }

    return false;
}
