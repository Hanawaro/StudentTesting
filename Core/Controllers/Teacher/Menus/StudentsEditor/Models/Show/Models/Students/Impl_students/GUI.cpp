#include "../Students.hpp"

static std::string getMark(Mark mark) {
    switch (mark) {
        case Mark::Empty:
            return std::string("N");
        case Mark::Two:
            return std::to_string(2);
        case Mark::Three:
            return std::to_string(3);
        case Mark::Four:
            return std::to_string(4);
        case Mark::Five:
            return std::to_string(5);
    }
}

void Students::draw(void) {
    wclear(m_Window);
    
    mvwaddstr(m_Window, LINES/4 - 2, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
    
    if (sort == Sort::up && !empty) wattron(m_Window, A_UNDERLINE);
    mvwaddstr(m_Window, LINES/4 + 1, COLS/2 - 3 - (int) iomanager::strlen(text_up), text_up.c_str());
    if (sort == Sort::up && !empty) wattroff(m_Window, A_UNDERLINE);
    if (sort == Sort::down && !empty) wattron(m_Window, A_UNDERLINE);
    mvwaddstr(m_Window, LINES/4 + 1, COLS/2 + 3, text_down.c_str());
    if (sort == Sort::down && !empty) wattroff(m_Window, A_UNDERLINE);
    
    if (sort == Sort::up && !empty) {
        
        int index = (page - 1) * MAXIMAL_USERS;
        int limit = (index + MAXIMAL_USERS) < sort_up_users.size() ? index + MAXIMAL_USERS : (int) sort_up_users.size();
        
        for (int i = index; i < limit; i++) {
            wattron(m_Window, COLOR_PAIR(iomanager::SORT));
            mvwaddstr(m_Window, LINES/4 + 3 + i%MAXIMAL_USERS, COLS/2 - MAXIMAL_SYMBOLS*2 - 2, sort_up_users[i].user.second_name.c_str());
            waddch(m_Window, ' ');
            mvwaddstr(m_Window, LINES/4 + 3 + i%MAXIMAL_USERS, COLS/2 - MAXIMAL_SYMBOLS - 1, sort_up_users[i].user.first_name.c_str());
            waddstr(m_Window, "  ");
            wattroff(m_Window, COLOR_PAIR(iomanager::SORT));
            mvwaddstr(m_Window, LINES/4 + 3 + i%MAXIMAL_USERS, COLS/2 + 1, (getMark(sort_up_users[i].student.first) + "   ").c_str());
            waddstr(m_Window, (getMark(sort_up_users[i].student.second) + "   ").c_str());
            waddstr(m_Window, (getMark(sort_up_users[i].student.third) + "   :   ").c_str());
            waddstr(m_Window, getMark(sort_up_users[i].student.total).c_str());
        }
    } else if (sort == Sort::down && !empty) {
        
        int index = (page - 1) * MAXIMAL_USERS;
        int limit = (index + MAXIMAL_USERS) < sort_down_users.size() ? index + MAXIMAL_USERS : (int) sort_down_users.size();
        
        
        for (int i = index; i < limit; i++) {
            wattron(m_Window, COLOR_PAIR(iomanager::SORT));
            mvwaddstr(m_Window, LINES/4 + 3 + i%MAXIMAL_USERS, COLS/2 - MAXIMAL_SYMBOLS*2 - 2, sort_down_users[i].user.second_name.c_str());
            waddch(m_Window, ' ');
            mvwaddstr(m_Window, LINES/4 + 3 + i%MAXIMAL_USERS, COLS/2 - MAXIMAL_SYMBOLS - 1, sort_down_users[i].user.first_name.c_str());
            waddstr(m_Window, "  ");
            wattroff(m_Window, COLOR_PAIR(iomanager::SORT));
            mvwaddstr(m_Window, LINES/4 + 3 + i%MAXIMAL_USERS, COLS/2 + 1, (getMark(sort_down_users[i].student.first) + "   ").c_str());
            waddstr(m_Window, (getMark(sort_down_users[i].student.second) + "   ").c_str());
            waddstr(m_Window, (getMark(sort_down_users[i].student.third) + "   :   ").c_str());
            waddstr(m_Window, getMark(sort_down_users[i].student.total).c_str());
        }
    }
    
    if (page <= 1) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
    mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_left + text_right + text_pages + std::to_string(page)))/2, text_left.c_str());
    if (page <= 1) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
    if (empty) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
    waddstr(m_Window, text_pages.c_str());
    waddstr(m_Window, std::to_string(page).c_str());
    if (empty) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
    if (page >= pages) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
    waddstr(m_Window, text_right.c_str());
    if (page <= pages) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
    
    mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    
    refresh();
    wrefresh(m_Window);
}

void Students::draw_active_change(void) {
    if (sort == Sort::up && !empty) wattron(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
    mvwaddstr(m_Window, LINES/4 + 1, COLS/2 - 3 - (int) iomanager::strlen(text_up), text_up.c_str());
    if (sort == Sort::up && !empty) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
    if (sort == Sort::down && !empty) wattron(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
    mvwaddstr(m_Window, LINES/4 + 1, COLS/2 + 3, text_down.c_str());
    if (sort == Sort::down && !empty) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
}

void Students::draw_active_pages(void) {
    if (page <= 1) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE)); else
        wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
    mvwaddstr(m_Window, LINES/4 + 13, (COLS - 1 - (int) iomanager::strlen(text_active_left + text_active_right + text_pages + std::to_string(page)))/2, text_active_left.c_str());
    if (page <= 1) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));  else
           wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
    wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
    waddstr(m_Window, text_pages.c_str());
    waddstr(m_Window, std::to_string(page).c_str());
    waddch(m_Window, ' ');
    wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
    if (page >= pages) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE)); else
           wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
    waddstr(m_Window, text_active_right.c_str());
    if (page <= pages) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));  else
           wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
}

void Students::draw_active_exit(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}
