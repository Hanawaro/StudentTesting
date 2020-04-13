#include "../AddTest.hpp"

bool AddTest::active_next_button(void) {
    draw_active_next_button();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            if (global_locale == GlobalLocale::question)
                locale = Locale::text_bar;
            else
                locale = Locale::check_bar;
            draw();
            break;
        case KEY_LEFT:
            if (global_locale != GlobalLocale::question) {
                locale = Locale::back_button;
                draw();
            }
            break;
        case '\t':
        case KEY_DOWN:
            locale = Locale::exit;
            draw();
            break;
        case '\n':
            // read
            isMessage = false;
            switch (global_locale) {
                case GlobalLocale::question:
                    global_locale = GlobalLocale::first_answer;
                    locale = next_button;
                    index = (int) real_first_answer.size();
                    break;
                case GlobalLocale::first_answer:
                    global_locale = GlobalLocale::second_answer;
                    locale = next_button;
                    index = (int) real_second_answer.size();
                    break;
                case GlobalLocale::second_answer:
                    global_locale = GlobalLocale::third_answer;
                    locale = complete;
                    index = (int) real_third_answer.size();
                    break;
                case GlobalLocale::third_answer:
                    break;
            }
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
