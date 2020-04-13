#include "../Teacher.hpp"

void TeacherMenu::draw(void) {
    wclear(m_Window);
    
    mvwprintw(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
    mvwprintw(m_Window, LINES/4 + 3, (COLS - (int) iomanager::strlen(text_profile))/2, text_profile.c_str());
    mvwprintw(m_Window, LINES/4 + 5, (COLS - (int) iomanager::strlen(text_students_editor))/2, text_students_editor.c_str());
    mvwprintw(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(text_tests_editor))/2, text_tests_editor.c_str());
    mvwprintw(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(text_unsave_exit))/2, text_unsave_exit.c_str());
    mvwprintw(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    
    refresh();
    wrefresh(m_Window);
}

void TeacherMenu::draw_active_profile(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwprintw(m_Window, LINES/4 + 3, (COLS - (int) iomanager::strlen(text_profile))/2, text_profile.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void TeacherMenu::draw_active_students_editor(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwprintw(m_Window, LINES/4 + 5, (COLS - (int) iomanager::strlen(text_students_editor))/2, text_students_editor.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void TeacherMenu::draw_active_tests_editor(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwprintw(m_Window, LINES/4 + 7, (COLS - (int) iomanager::strlen(text_tests_editor))/2, text_tests_editor.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void TeacherMenu::draw_active_unsave_exit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwprintw(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(text_unsave_exit))/2, text_unsave_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void TeacherMenu::draw_active_exit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwprintw(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

