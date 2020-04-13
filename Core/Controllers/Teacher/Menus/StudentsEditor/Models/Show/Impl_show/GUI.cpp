#include "../Show.hpp"

void Show::draw(void) {
    wclear(m_Window);
    
    mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
    mvwaddstr(m_Window, LINES/4 + 3, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
    mvwaddstr(m_Window, LINES/4 + 5, (COLS - (int) iomanager::strlen(text_first))/2, text_first.c_str());
    mvwaddstr(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(text_second))/2, text_second.c_str());
    mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(text_third))/2, text_third.c_str());
    mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(text_total))/2, text_total.c_str());
    mvwaddstr(m_Window, LINES/4 + 14, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    
    refresh();
    wrefresh(m_Window);
}

void Show::draw_active_students(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 3, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void Show::draw_active_first(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 5, (COLS - (int) iomanager::strlen(text_first))/2, text_first.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));

}

void Show::draw_active_second(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(text_second))/2, text_second.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));

}

void Show::draw_active_third(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(text_third))/2, text_third.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));

}

void Show::draw_active_total(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(text_total))/2, text_total.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));

}

void Show::draw_active_exit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 14, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));

}
