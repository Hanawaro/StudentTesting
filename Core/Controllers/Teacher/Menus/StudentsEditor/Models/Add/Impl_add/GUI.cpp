#include "../Add.hpp"

void Add::draw(void) {
    wclear(m_Window);
    
    mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
    mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - LEFT - (int) iomanager::strlen(text_login), text_login.c_str());
    waddstr(m_Window, show_login.c_str());
    mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - LEFT - (int) iomanager::strlen(text_name), text_name.c_str());
    waddstr(m_Window, show_name.c_str());
    mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - LEFT - (int) iomanager::strlen(text_second_name), text_second_name.c_str());
    waddstr(m_Window, show_second_name.c_str());
    mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - LEFT - (int) iomanager::strlen(text_password), text_password.c_str());
    waddstr(m_Window, show_password.c_str());
    mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_register))/2 + 8, text_register.c_str());
    mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_exit))/2 - 8, text_exit.c_str());
    
    refresh();
    wrefresh(m_Window);
}

void Add::draw_active_login(void) {
    curs_set(1);
    
    wmove(m_Window, LINES/4 + 3, COLS/2 - LEFT + (int) iomanager::strlen(show_login));
}

void Add::draw_active_name(void) {
    curs_set(1);
    
    wmove(m_Window, LINES/4 + 5, COLS/2 - LEFT + (int) iomanager::strlen(show_name));
}

void Add::draw_active_second_name(void) {
    curs_set(1);
    
    wmove(m_Window, LINES/4 + 7, COLS/2 - LEFT + (int) iomanager::strlen(show_second_name));
}

void Add::draw_active_password(void) {
    curs_set(1);
    
    wmove(m_Window, LINES/4 + 9, COLS/2 - LEFT + (int) iomanager::strlen(show_password));
}

void Add::draw_active_register(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_register))/2 + 8, text_register.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void Add::draw_active_exit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_exit))/2 - 8, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}
