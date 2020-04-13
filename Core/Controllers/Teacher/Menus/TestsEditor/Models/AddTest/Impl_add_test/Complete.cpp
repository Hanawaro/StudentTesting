#include "../AddTest.hpp"

bool AddTest::active_complete(void) {
    draw_active_complete();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            locale = Locale::check_bar;
            draw();
            break;
        case KEY_LEFT:
        case '\t':
            locale = Locale::back_button;
            draw();
            break;
        case KEY_DOWN:
            locale = Locale::exit;
            draw();
            break;
        case '\n':
            isMessage = true;
            if (!real_question.size()) {
                locale = Locale::text_bar;
                global_locale = GlobalLocale::question;
                message = error_question;
            } else if (!real_first_answer.size()) {
                locale = Locale::text_bar;
                global_locale = GlobalLocale::first_answer;
                message = error_first_answer;
            } else if (!real_second_answer.size()) {
                locale = Locale::text_bar;
                global_locale = GlobalLocale::second_answer;
                message = error_second_answer;
            } else if (!real_third_answer.size()) {
                locale = Locale::text_bar;
                global_locale = GlobalLocale::third_answer;
                message = error_third_answer;
            } else if (is_check_bar == GlobalLocale::question) {
                locale = Locale::text_bar;
                global_locale = GlobalLocale::first_answer;
                message = error_true_answer;
            } else {
                add_new_test();
                real_question       = "";
                real_first_answer   = "";
                real_second_answer  = "";
                real_third_answer   = "";
                global_locale = GlobalLocale::question;
                locale = Locale::exit;
                message = sucsess_write;
            }
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
