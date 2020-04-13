#include "../AddTest.hpp"

void AddTest::draw(void) {
    wclear(m_Window);
    wclear(m_TextBar);
    
    switch (global_locale) {
        case GlobalLocale::question:
            // hello
            mvwaddstr(m_Window, LINES/4 - 2, (COLS - (int) iomanager::strlen(text_hello_question))/2, text_hello_question.c_str());
            // text bar
            draw_real_some(real_question);
            // next
            mvwaddstr(m_Window, LINES/4 + 12, COLS/2 + 3, text_next.c_str());
            // back
            wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
            mvwaddstr(m_Window, LINES/4 + 12, COLS/2 - 4 - (int) iomanager::strlen(text_back), text_back.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
            // exit
            mvwaddstr(m_Window, LINES/4 + 14, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
            break;
        case GlobalLocale::first_answer:
            mvwaddstr(m_Window, LINES/4 - 2, (COLS - (int) iomanager::strlen(text_hello_first_answer))/2, text_hello_first_answer.c_str());
            // text bar
            draw_real_some(real_first_answer);
            // check bar
            if (global_locale == is_check_bar)
                mvwaddstr(m_Window, LINES/4 + 10, (COLS - (int) iomanager::strlen(text_active_check_bar))/2, text_active_check_bar.c_str());
            else
                mvwaddstr(m_Window, LINES/4 + 10, (COLS - (int) iomanager::strlen(text_disable_check_bar))/2, text_disable_check_bar.c_str());
            // next
            mvwaddstr(m_Window, LINES/4 + 12, COLS/2 + 3, text_next.c_str());
            // back
            mvwaddstr(m_Window, LINES/4 + 12, COLS/2 - 4 - (int) iomanager::strlen(text_back), text_back.c_str());
            // exit
            mvwaddstr(m_Window, LINES/4 + 14, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
            break;
        case GlobalLocale::second_answer:
            mvwaddstr(m_Window, LINES/4 - 2, (COLS - (int) iomanager::strlen(text_hello_second_answer))/2, text_hello_second_answer.c_str());
            // text bar
            draw_real_some(real_second_answer);
            // check bar
            if (global_locale == is_check_bar)
                mvwaddstr(m_Window, LINES/4 + 10, (COLS - (int) iomanager::strlen(text_active_check_bar))/2, text_active_check_bar.c_str());
            else
                mvwaddstr(m_Window, LINES/4 + 10, (COLS - (int) iomanager::strlen(text_disable_check_bar))/2, text_disable_check_bar.c_str());
            // next
            mvwaddstr(m_Window, LINES/4 + 12, COLS/2 + 3, text_next.c_str());
            // back
            mvwaddstr(m_Window, LINES/4 + 12, COLS/2 - 4 - (int) iomanager::strlen(text_back), text_back.c_str());
            // exit
            mvwaddstr(m_Window, LINES/4 + 14, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
            break;
        case GlobalLocale::third_answer:
            mvwaddstr(m_Window, LINES/4 - 2, (COLS - (int) iomanager::strlen(text_hello_third_answer))/2, text_hello_third_answer.c_str());
            // text bar
            draw_real_some(real_third_answer);
            // check bar
            if (global_locale == is_check_bar)
                mvwaddstr(m_Window, LINES/4 + 10, (COLS - (int) iomanager::strlen(text_active_check_bar))/2, text_active_check_bar.c_str());
            else
                mvwaddstr(m_Window, LINES/4 + 10, (COLS - (int) iomanager::strlen(text_disable_check_bar))/2, text_disable_check_bar.c_str());
            // next
            mvwaddstr(m_Window, LINES/4 + 12, COLS/2 + 3, text_complete.c_str());
            // back
            mvwaddstr(m_Window, LINES/4 + 12, COLS/2 - 4 - (int) iomanager::strlen(text_back), text_back.c_str());
            // exit
            mvwaddstr(m_Window, LINES/4 + 14, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
            break;
    }
    
    if (isMessage) {
        if (message == sucsess_write) {
            wattron(m_Window, COLOR_PAIR(iomanager::SUCSESS));
            mvwaddstr(m_Window, LINES/4 + 8, (COLS - (int) iomanager::strlen(message))/2, message.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::SUCSESS));
        } else {
            wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
            mvwaddstr(m_Window, LINES/4 + 8, (COLS - (int) iomanager::strlen(message))/2, message.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
        }
    }
    
    box(m_TextBar, ' ', ' ');
    
    wrefresh(m_Window);
    wrefresh(m_TextBar);
}

void AddTest::draw_real_some(const std::string& some) {
    wclear(m_TextBar);
    int row = 1;
    int column = 2;
    for (size_t i = 0; i < some.size(); i++) {
        if (column > 70 - 4) {
            column = 2;
            row++;
        }
        mvwaddch(m_TextBar, row, column, some[i]);
        column++;
    }
    row = 1;
    column = 2;
    for (int i = 0; i < index; i++) {
        if (column + 1 > 70 - 4) {
            column = 2;
            row++;
            continue;
        }
        column++;
    }
    wmove(m_TextBar, row, column);
    wmove(m_Window, row + LINES/4 + 1, column + (COLS - 70) / 2);
    
    box(m_TextBar, ' ', ' ');
    wrefresh(m_TextBar);
}

void AddTest::draw_active_text_bar(void) {
    curs_set(1);
}

void AddTest::draw_active_check_bar(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    if (global_locale == is_check_bar)
        mvwaddstr(m_Window, LINES/4 + 10, (COLS - (int) iomanager::strlen(text_active_check_bar))/2, text_active_check_bar.c_str());
    else
        mvwaddstr(m_Window, LINES/4 + 10, (COLS - (int) iomanager::strlen(text_disable_check_bar))/2, text_disable_check_bar.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void AddTest::draw_active_next_button(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 12, COLS/2 + 3, text_next.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void AddTest::draw_active_back_button(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 12, COLS/2 - 4 - (int) iomanager::strlen(text_back), text_back.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void AddTest::draw_active_complete(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 12, COLS/2 + 3, text_complete.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void AddTest::draw_active_exit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 14, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}
