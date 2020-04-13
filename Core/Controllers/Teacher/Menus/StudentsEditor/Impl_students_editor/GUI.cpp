#include "../StudentsEditor.hpp"

void StudentsEditor::draw(void) {
    wclear(m_Window);

    mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
    mvwaddstr(m_Window, LINES/4 + 3, (COLS - (int) iomanager::strlen(text_add))/2, text_add.c_str());
    mvwaddstr(m_Window, LINES/4 + 5, (COLS - (int) iomanager::strlen(text_edit))/2, text_edit.c_str());
    mvwaddstr(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(text_show))/2, text_show.c_str());
    mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());

    refresh();
    wrefresh(m_Window);
}

void StudentsEditor::draw_active_add(void) {
    curs_set(0);
        
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 3, (COLS - (int) iomanager::strlen(text_add))/2, text_add.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void StudentsEditor::draw_active_edit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 5, (COLS - (int) iomanager::strlen(text_edit))/2, text_edit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void StudentsEditor::draw_active_show(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(text_show))/2, text_show.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void StudentsEditor::draw_active_exit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}
