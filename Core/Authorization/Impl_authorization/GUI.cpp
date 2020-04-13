#include "../Authorization.hpp"

void Authorization::draw(void) {
    wclear(m_Window);
    
    curs_set(0);
    
    mvwaddstr(m_Window, LINES / 4, (COLS - (int)iomanager::strlen(text_hello))/2, text_hello.c_str());
    mvwaddstr(m_Window, LINES / 4 + 3, COLS/2.5 - (int)iomanager::strlen(text_login), text_login.c_str());
    waddstr(m_Window, show_login.c_str());
    mvwaddstr(m_Window, LINES / 4 + 5, COLS/2.5 - (int)iomanager::strlen(text_password), text_password.c_str());
    waddstr(m_Window, show_password.c_str());
    mvwaddstr(m_Window, LINES / 4 + 7, (COLS - (int) iomanager::strlen(text_save)) / 2, text_save.c_str());
    for (int i = 0; i < COLS; i++) mvwaddch(m_Window, LINES/4 + 9, i, ' ');
    mvwaddstr(m_Window, LINES / 4 + 11, (COLS - (int) iomanager::strlen(text_enter))/2  + 5, text_enter.c_str());
    mvwaddstr(m_Window, LINES / 4 + 11, (COLS - (int) iomanager::strlen(text_exit))/2  - 5, text_exit.c_str());
    
    refresh();
    wrefresh(m_Window);
}

void Authorization::draw_active_login(void) {
    curs_set(1);
    
    wmove(m_Window, LINES/4 + 3, COLS/2.5 + (int) show_login.size() + 1);
}

void Authorization::draw_active_password(void) {
    curs_set(1);
    
    wmove(m_Window, LINES/4 + 5, COLS/2.5 + (int) show_password.size() + 1);
}

void Authorization::draw_active_save(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(text_save))/2, text_save.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void Authorization::draw_active_enter(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(text_enter))/2  + 5, text_enter.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void Authorization::draw_active_exit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(text_exit))/2 - 5, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}


