#include "../Student.hpp"

void StudentMenu::draw(void) {
    wclear(m_Window);
    
    // hello
    mvwaddstr(m_Window, LINES/4 - 3, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
    
    switch (change_locale) {
        case ChangeLocale::Training:
            // change
            wattron(m_Window, A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2 - (int) iomanager::strlen(text_training) - 4, text_training.c_str());
            wattroff(m_Window, A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2, text_testing.c_str());
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_testing))/2 + 4, text_info.c_str());
            
            // show
            mvwaddstr(m_Window, LINES/4 + 3, (COLS - (int) iomanager::strlen(text_first_test))/2, text_first_test.c_str());
            mvwaddstr(m_Window, LINES/4 + 5, (COLS - (int) iomanager::strlen(text_second_test))/2, text_second_test.c_str());
            mvwaddstr(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(text_third_test))/2, text_third_test.c_str());
            mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(text_total_test_training))/2, text_total_test_training.c_str());
            
            break;
        case ChangeLocale::Testing:
            // change
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2 - (int) iomanager::strlen(text_training) - 4, text_training.c_str());
            wattron(m_Window, A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2, text_testing.c_str());
            wattroff(m_Window, A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_testing))/2 + 4, text_info.c_str());
            
            // SHOW
            
            // first
            mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - 3 - (int) iomanager::strlen(text_first_test), text_first_test.c_str());
            waddstr(m_Window, text_middle.c_str());
            switch (m_Student.amount_of_first) {
                case 0:
                    if (show_locale != ShowLocale::First || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                    waddstr(m_Window, "Нет попыток");
                    if (show_locale != ShowLocale::First || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                    break;
                case 1:
                    if (show_locale != ShowLocale::First || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_first) + std::string(" попытка")).c_str());
                    if (show_locale != ShowLocale::First || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    break;
                default:
                    if (show_locale != ShowLocale::First || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_first) + std::string(" попытки")).c_str());
                    if (show_locale != ShowLocale::First || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    break;
            }
            
            // second
            mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - 3 - (int) iomanager::strlen(text_second_test), text_second_test.c_str());
            waddstr(m_Window, text_middle.c_str());
            switch (m_Student.amount_of_second) {
                case 0:
                    if (show_locale != ShowLocale::Second || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                    waddstr(m_Window, "Нет попыток");
                    if (show_locale != ShowLocale::Second || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                    break;
                case 1:
                    if (show_locale != ShowLocale::Second || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_second) + std::string(" попытка")).c_str());
                    if (show_locale != ShowLocale::Second || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    break;
                default:
                    if (show_locale != ShowLocale::Second || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_second) + std::string(" попытки")).c_str());
                    if (show_locale != ShowLocale::Second || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    break;
            }
            
            // third
            mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - 3 - (int) iomanager::strlen(text_third_test), text_third_test.c_str());
            waddstr(m_Window, text_middle.c_str());
            switch (m_Student.amount_of_third) {
                case 0:
                    if (show_locale != ShowLocale::Third || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                    waddstr(m_Window, "Нет попыток");
                    if (show_locale != ShowLocale::Third || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                    break;
                case 1:
                    if (show_locale != ShowLocale::Third || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_third) + std::string(" попытка")).c_str());
                    if (show_locale != ShowLocale::Third || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    break;
                default:
                    if (show_locale != ShowLocale::Third || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_third) + std::string(" попытки")).c_str());
                    if (show_locale != ShowLocale::Third || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    break;
            }
            
            // total
            mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - 3 - (int) iomanager::strlen(text_total_test_testing), text_total_test_testing.c_str());
            waddstr(m_Window, text_middle.c_str());
            switch (m_Student.amount_of_total) {
                case 0:
                    if (show_locale != ShowLocale::Total || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
                    waddstr(m_Window, "Нет попыток");
                    if (show_locale != ShowLocale::Total || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
                    break;
                case 1:
                    if (show_locale != ShowLocale::Total || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_total) + std::string(" попытка")).c_str());
                    if (show_locale != ShowLocale::Total || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    break;
                default:
                    if (show_locale != ShowLocale::Total || locale != Locale::Show) wattron(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_total) + std::string(" попытки")).c_str());
                    if (show_locale != ShowLocale::Total || locale != Locale::Show) wattroff(m_Window, COLOR_PAIR(iomanager::SUCSESS));
                    break;
            }
            
            
            break;
        case ChangeLocale::Info:
            // change
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2 - (int) iomanager::strlen(text_training) - 4, text_training.c_str());
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2, text_testing.c_str());
            wattron(m_Window, A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_testing))/2 + 4, text_info.c_str());
            wattroff(m_Window, A_UNDERLINE);
            
            int left = 0;
            
            mvwaddstr(m_Window, LINES/4 + 3 ,COLS/2 - (int) iomanager::strlen(text_login) - left, text_login.c_str());
            waddstr(m_Window, show_login.c_str());
            
            mvwaddstr(m_Window, LINES/4 + 4 ,COLS/2 - (int) iomanager::strlen(text_name) - left, text_name.c_str());
            waddstr(m_Window, show_name.c_str());
            
            mvwaddstr(m_Window, LINES/4 + 5 ,COLS/2 - (int) iomanager::strlen(text_second_name) - left, text_second_name.c_str());
            waddstr(m_Window, show_second_name.c_str());
            
            mvwaddstr(m_Window, LINES/4 + 6 ,COLS/2 - (int) iomanager::strlen(text_first_mark) - left, text_first_mark.c_str());
            waddstr(m_Window, show_first_mark.c_str());
            
            mvwaddstr(m_Window, LINES/4 + 7 ,COLS/2 - (int) iomanager::strlen(text_second_mark) - left, text_second_mark.c_str());
            waddstr(m_Window, show_second_mark.c_str());
            
            mvwaddstr(m_Window, LINES/4 + 8 ,COLS/2 - (int) iomanager::strlen(text_third_mark) - left, text_third_mark.c_str());
            waddstr(m_Window, show_third_mark.c_str());
            
            mvwaddstr(m_Window, LINES/4 + 9 ,COLS/2 - (int) iomanager::strlen(text_total_mark) - left, text_total_mark.c_str());
            waddstr(m_Window, show_total_mark.c_str());
            
            break;
    }
    
    // unsave exit
    mvwaddstr(m_Window, LINES/4 + 12, (COLS - (int) iomanager::strlen(text_unsave_exit))/2, text_unsave_exit.c_str());
    
    // exit
    mvwaddstr(m_Window, LINES/4 + 14, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    
    wrefresh(m_Window);
}

void StudentMenu::draw_active_change(void) {
    switch (change_locale) {
        case ChangeLocale::Training:
            wattron(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2 - (int) iomanager::strlen(text_training) - 4, text_training.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2, text_testing.c_str());
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_testing))/2 + 4, text_info.c_str());
            break;
        case ChangeLocale::Testing:
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2 - (int) iomanager::strlen(text_training) - 4, text_training.c_str());
            wattron(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2, text_testing.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_testing))/2 + 4, text_info.c_str());
            break;
        case ChangeLocale::Info:
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2 - (int) iomanager::strlen(text_training) - 4, text_training.c_str());
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_testing))/2, text_testing.c_str());
            wattron(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_testing))/2 + 4, text_info.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            break;
    }
}

void StudentMenu::draw_active_show(void) {
    if (change_locale == ChangeLocale::Info) return;
    
    if (change_locale == ChangeLocale::Testing)
    switch (show_locale) {
        case ShowLocale::First:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - 3 - (int) iomanager::strlen(text_first_test), text_first_test.c_str());
            waddstr(m_Window, text_middle.c_str());
            switch (m_Student.amount_of_first) {
                case 0:
                    waddstr(m_Window, "Нет попыток ");
                    break;
                case 1:
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_first) + std::string(" попытка ")).c_str());
                    break;
                default:
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_first) + std::string(" попытки ")).c_str());
                    break;
            }
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        case ShowLocale::Second:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - 3 - (int) iomanager::strlen(text_second_test), text_second_test.c_str());
            waddstr(m_Window, text_middle.c_str());
            switch (m_Student.amount_of_second) {
                case 0:
                    waddstr(m_Window, "Нет попыток ");
                    break;
                case 1:
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_second) + std::string(" попытка ")).c_str());
                    break;
                default:
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_second) + std::string(" попытки ")).c_str());
                    break;
            }
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        case ShowLocale::Third:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - 3 - (int) iomanager::strlen(text_third_test), text_third_test.c_str());
            waddstr(m_Window, text_middle.c_str());
            switch (m_Student.amount_of_third) {
                case 0:
                    waddstr(m_Window, "Нет попыток ");
                    break;
                case 1:
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_third) + std::string(" попытка ")).c_str());
                    break;
                default:
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_third) + std::string(" попытки ")).c_str());
                    break;
            }
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        case ShowLocale::Total:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - 3 - (int) iomanager::strlen(text_total_test_testing), text_total_test_testing.c_str());
            waddstr(m_Window, text_middle.c_str());
            switch (m_Student.amount_of_total) {
                case 0:
                    waddstr(m_Window, "Нет попыток ");
                    break;
                case 1:
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_total) + std::string(" попытка ")).c_str());
                    break;
                default:
                    waddstr(m_Window, (std::to_string(m_Student.amount_of_total) + std::string(" попытки ")).c_str());
                    break;
            }
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
    }
    else {
        switch (show_locale) {
        case ShowLocale::First:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddstr(m_Window, LINES/4 + 3, (COLS - (int) iomanager::strlen(text_first_test))/2, text_first_test.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        case ShowLocale::Second:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddstr(m_Window, LINES/4 + 5, (COLS - (int) iomanager::strlen(text_second_test))/2, text_second_test.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        case ShowLocale::Third:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddstr(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(text_third_test))/2, text_third_test.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        case ShowLocale::Total:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(text_total_test_training))/2, text_total_test_training.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        }
    } 
}

void StudentMenu::draw_active_unsave_exit(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 12, (COLS - (int) iomanager::strlen(text_unsave_exit))/2, text_unsave_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void StudentMenu::draw_active_exit(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 14, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}
