#include "../Testing.hpp"

void Testing::draw(void) {
    wclear(m_Window);
    
//    wmove(m_Window, 0, 0);
//    for (int i = 0; i < tests.size(); i++)
//        wprintw(m_Window, "%d ", randomize[i]);
    
    switch (g_show_locale) {
        case 1:
            mvwaddstr(m_Window, LINES/4 - 3, (COLS - (int) iomanager::strlen(text_first_hello))/2, text_first_hello.c_str());
            break;
        case 2:
            mvwaddstr(m_Window, LINES/4 - 3, (COLS - (int) iomanager::strlen(text_second_hello))/2, text_second_hello.c_str());
            break;
        case 3:
            mvwaddstr(m_Window, LINES/4 - 3, (COLS - (int) iomanager::strlen(text_third_hello))/2, text_third_hello.c_str());
            break;
        case 4:
            mvwaddstr(m_Window, LINES/4 - 3, (COLS - (int) iomanager::strlen(text_total_hello))/2, text_total_hello.c_str());
            break;
    }
    
    if (!empty && !isAll) {
//        mvwprintw(m_Window, 0, COLS - 2, "%d",tests[randomize[0]].right );
        draw_some(show_question, LINES/4 - 1);
        draw_some(show_first_answer, LINES/4 + 4);
        draw_some(show_second_anser, LINES/4 + 7);
        draw_some(show_third_anser, LINES/4 + 10);
        
        mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    } else if (isAll) {
        int mark = 0;
        if (right_answers > amount_of_tests*0.9)
            mark = 5;
        else if (right_answers > amount_of_tests*0.7)
            mark = 4;
        else if (right_answers > amount_of_tests*0.5)
            mark = 3;
        else
            mark = 2;
        
        mvwaddstr(m_Window, LINES/4 + 6, (COLS - (int) iomanager::strlen(result_mark) - 1)/2, (result_mark + std::to_string(mark)).c_str());
        mvwaddstr(m_Window, LINES/4 + 8, (COLS - (int) iomanager::strlen(result_left + std::to_string(right_answers) + result_between + std::to_string(amount_of_tests)))/2, (result_left + std::to_string(right_answers) + result_between + std::to_string(amount_of_tests)).c_str());
        
        mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_result_exit))/2, text_result_exit.c_str());
    } else {
        wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
        mvwaddstr(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(error_empty))/2, error_empty.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
        mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_empty_exit))/2, text_empty_exit.c_str());
    }
    
    wrefresh(m_Window);
}

void Testing::draw_some(const std::string &some, int line) {
    int left = COLS - TEXT_SIZE;
    
    int row = line;
    int column = left;
    for (size_t i = 0; i < some.size(); i++) {
        if (column - left > TEXT_SIZE) {
            column = left;
            row++;
        }
        mvwaddch(m_Window, row, column, some[i]);
        column++;
    }
    for (int i = column; i < TEXT_SIZE; i++)
        mvwaddch(m_Window, row, i, ' ');
}

void Testing::draw_active_first(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    draw_some(show_first_answer, LINES/4 + 4);
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void Testing::draw_active_second(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    draw_some(show_second_anser, LINES/4 + 7);
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));

}

void Testing::draw_active_third(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    draw_some(show_third_anser, LINES/4 + 10);
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));

}

void Testing::draw_active_exit(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    if (!empty && !isAll)
        mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    else if (isAll)
        mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_result_exit))/2, text_result_exit.c_str());
    else
        mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_empty_exit))/2, text_empty_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}
