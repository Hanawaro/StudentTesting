#include "../AddTest.hpp"

bool AddTest::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            if (global_locale == GlobalLocale::third_answer)
                locale = Locale::complete;
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
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
