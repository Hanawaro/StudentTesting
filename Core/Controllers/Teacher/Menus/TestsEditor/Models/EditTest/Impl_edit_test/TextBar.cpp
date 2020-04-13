#include "../EditTest.hpp"

bool EditTest::active_text_bar(void) {
    draw_active_text_bar();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case '\t':
        case KEY_DOWN:
            if (global_locale == GlobalLocale::question)
                locale = Locale::next_button;
            else
                locale = Locale::check_bar;
            break;
        case '\n':
            // read
            if (global_locale == GlobalLocale::question)
                locale = Locale::next_button;
            else
                locale = Locale::check_bar;
            break;
        case KEY_LEFT:
            switch (global_locale) {
                case GlobalLocale::question:
                    if (index - 1 >= 0)
                        index--;
                    draw_real_some(real_question);
                    break;
                case GlobalLocale::first_answer:
                    if (index - 1 >= 0)
                        index--;
                    draw_real_some(real_first_answer);
                    break;
                case GlobalLocale::second_answer:
                    if (index - 1 >= 0)
                        index--;
                    draw_real_some(real_second_answer);
                    break;
                case GlobalLocale::third_answer:
                    if (index - 1 >= 0)
                        index--;
                    draw_real_some(real_third_answer);
                    break;
            }
            break;
        case KEY_RIGHT:
            switch (global_locale) {
                case GlobalLocale::question:
                    if (index < real_question.size())
                        index++;
                    draw_real_some(real_question);
                    break;
                case GlobalLocale::first_answer:
                    if (index < real_first_answer.size())
                        index++;
                    draw_real_some(real_first_answer);
                    break;
                case GlobalLocale::second_answer:
                    if (index < real_second_answer.size())
                        index++;
                    draw_real_some(real_second_answer);
                    break;
                case GlobalLocale::third_answer:
                    if (index < real_third_answer.size())
                        index++;
                    draw_real_some(real_third_answer);
                    break;
            }
            
            break;;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            if (isMessage && message != error_true_answer) {
                isMessage = false;
                draw();
            }
            if (index - 1 >= 0)
                index--;
            switch (global_locale) {
                case GlobalLocale::question:
                    if (real_question.size()) {
                        real_question.erase(index, 1);
                    }
                    draw_real_some(real_question);
                    break;
                case GlobalLocale::first_answer:
                    if (real_first_answer.size()) {
                        real_first_answer.erase(index, 1);
                    }
                    draw_real_some(real_first_answer);
                    break;
                case GlobalLocale::second_answer:
                    if (real_second_answer.size()) {
                        real_second_answer.erase(index, 1);
                    }
                    draw_real_some(real_second_answer);
                    break;
                case GlobalLocale::third_answer:
                    if (real_third_answer.size()) {
                        real_third_answer.erase(index, 1);
                    }
                    draw_real_some(real_third_answer);
                    break;
                }
            break;
        default:
            if (isMessage && message != error_true_answer) {
                isMessage = false;
                draw();
            }
            if (tmp < EOF || tmp > 127 || real_question.size() >= 255 || real_first_answer.size() >= 127 || real_second_answer.size() >= 127 || real_third_answer.size() >= 127)
                return true;
            index++;
            switch (global_locale) {
                case GlobalLocale::question:
                    real_question.insert(index - 1, 1, (char) tmp);
                    draw_real_some(real_question);
                    break;
                case GlobalLocale::first_answer:
                    real_first_answer.insert(index - 1, 1, (char) tmp);
                    draw_real_some(real_first_answer);
                    break;
                case GlobalLocale::second_answer:
                    real_second_answer.insert(index - 1, 1, (char) tmp);
                    draw_real_some(real_second_answer);
                    break;
                case GlobalLocale::third_answer:
                    real_third_answer.insert(index - 1, 1, (char) tmp);
                    draw_real_some(real_third_answer);
                    break;
            }
            break;
    }
    
    return false;
}
