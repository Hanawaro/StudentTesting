#include "../Training.hpp"

void Training::draw(void) {
    wclear(m_Window);
    
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
    
    if (!empty) {
        draw_some(show_question, LINES/4 - 1);
        draw_some(show_first_answer, LINES/4 + 4);
        draw_some(show_second_anser, LINES/4 + 7);
        draw_some(show_third_anser, LINES/4 + 10);
    } else {
        wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
        mvwaddstr(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(error_empty))/2, error_empty.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
    }
    
    if (isError) {
        isError = false;
        wattron(m_Window, COLOR_PAIR(iomanager::ERROR));
        mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(error))/2, error.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::ERROR));
    }
    
    mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    
    wrefresh(m_Window);
}

void Training::draw_some(const std::string &some, int line) {
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

void Training::draw_active_first(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    draw_some(show_first_answer, LINES/4 + 4);
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void Training::draw_active_second(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    draw_some(show_second_anser, LINES/4 + 7);
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));

}

void Training::draw_active_third(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    draw_some(show_third_anser, LINES/4 + 10);
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));

}

void Training::draw_active_exit(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));

}
