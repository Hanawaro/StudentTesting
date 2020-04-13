#include "../EditTest.hpp"

bool EditTest::active_back_button(void) {
    draw_active_back_button();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            locale = Locale::check_bar;
            draw();
            break;
        case KEY_RIGHT:
            if (global_locale != GlobalLocale::third_answer) {
                locale = Locale::next_button;
                draw();
            }
            break;
        case '\t':
        case KEY_DOWN:
            locale = Locale::exit;
            draw();
            break;
        case '\n':
            isMessage = false;
            // read
            switch (global_locale) {
                case GlobalLocale::question:
                    break;
                case GlobalLocale::first_answer:
                    global_locale = GlobalLocale::question;
                    locale = next_button;
                    index = (int) real_question.size();
                    break;
                case GlobalLocale::second_answer:
                    global_locale = GlobalLocale::first_answer;
                    locale = back_button;
                    index = (int) real_second_answer.size();
                    break;
                case GlobalLocale::third_answer:
                    global_locale = GlobalLocale::second_answer;
                    locale = back_button;
                    index = (int) real_second_answer.size();
                    break;
            }
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
