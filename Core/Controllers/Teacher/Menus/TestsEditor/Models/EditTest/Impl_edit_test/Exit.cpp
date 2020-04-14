#include "../EditTest.hpp"

bool EditTest::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            if (global_locale == GlobalLocale::third_answer)
                locale = Locale::back_button;
            else
                locale = Locale::next_button;
            draw();
            break;
        case '\t':
            locale = Locale::text_bar;
            draw();
            break;
        case '\n':
            is_exit = true;
            edit_test();
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
