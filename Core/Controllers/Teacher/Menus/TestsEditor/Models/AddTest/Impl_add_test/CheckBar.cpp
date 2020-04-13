#include "../AddTest.hpp"

bool AddTest::active_check_bar(void) {
    draw_active_check_bar();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            locale = Locale::text_bar;
            draw();
            break;
        case '\t':
        case KEY_DOWN:
            if (global_locale != GlobalLocale::third_answer)
                locale = Locale::next_button;
            else
                locale = Locale::complete;
            draw();
            break;
        case '\n':
            if (is_check_bar == global_locale) {
                is_check_bar = GlobalLocale::question;
            } else {
                is_check_bar = global_locale;
            }
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
