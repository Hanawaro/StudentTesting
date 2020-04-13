#include "../Edit.hpp"

void Edit::draw(void) {
    wclear(m_Window);
    
    mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
    
    if (!deep && users.size()) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
    mvwaddstr(m_Window, LINES/4 + 2, (COLS - (int) iomanager::strlen(show_login))/2, show_login.c_str());
    if (!deep && users.size()) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
    
    if (!users.size()) wcolor_set(m_Window, iomanager::TEXT, NULL);
    mvwaddstr(m_Window, LINES/4 + 4, (COLS - (int) (text_left.size() + text_right.size() + iomanager::strlen(show_name + show_second_name) + 1))/2, text_left.c_str());
    waddstr(m_Window, show_name.c_str());
    waddch(m_Window, ' ');
    waddstr(m_Window, show_second_name.c_str());
    waddstr(m_Window, text_right.c_str());
    if (!users.size()) wcolor_set(m_Window, iomanager::DISABLE, NULL);
    
    mvwaddstr(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(text_edit))/2, text_edit.c_str());
    
    mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(text_remove))/2, text_remove.c_str());
    
    mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    
    refresh();
    wrefresh(m_Window);
}

void Edit::draw_active_login(void) {
    if (deep) {
        curs_set(1);
        
        wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
        mvwaddstr(m_Window, LINES/4 + 2, (COLS - (int) iomanager::strlen(show_login))/2, show_login.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
    } else {
        curs_set(0);
        
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddch(m_Window, LINES/4 + 2, (COLS - (int) iomanager::strlen(show_login))/2 - 1, ' ');
        waddstr(m_Window, show_login.c_str());
        waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void Edit::draw_active_change(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 4, (COLS - (int) (text_left.size() + text_right.size() + iomanager::strlen(show_name + show_second_name) + 1))/2, text_left.c_str());
    waddstr(m_Window, show_second_name.c_str());
    waddch(m_Window, ' ');
    waddstr(m_Window, show_name.c_str());
    waddstr(m_Window, text_right.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void Edit::draw_active_edit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(text_edit))/2, text_edit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void Edit::draw_active_remove(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(text_remove))/2, text_remove.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void Edit::draw_active_exit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}
