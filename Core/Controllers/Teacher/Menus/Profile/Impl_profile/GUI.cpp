#include "../Profile.hpp"

void Profile::draw(void) {
    wclear(m_Window);
    
    // hello message
    mvwaddstr(m_Window, LINES/4 - 2, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
    
    // status message
    if (!deep) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
    mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_status))/2, text_status.c_str());
    if (!deep) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
    
    // login
    mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - (int) iomanager::strlen(text_login) - LEFT, text_login.c_str());
    wattron(m_Window, A_UNDERLINE);
    for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_login.size())/2.); i++)
        waddch(m_Window, ' ');
    waddstr(m_Window, show_login.c_str());
    for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_login.size())/2.); i++)
        waddch(m_Window, ' ');
    wattroff(m_Window, A_UNDERLINE);
    
    // name
    mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - (int) iomanager::strlen(text_name) - LEFT, text_name.c_str());
    wattron(m_Window, A_UNDERLINE);
    for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_name.size())/2.); i++)
        waddch(m_Window, ' ');
    waddstr(m_Window, show_name.c_str());
    for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_name.size())/2.); i++)
        waddch(m_Window, ' ');
    wattroff(m_Window, A_UNDERLINE);

    // second name
    mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - (int) iomanager::strlen(text_second_name) - LEFT, text_second_name.c_str());
    wattron(m_Window, A_UNDERLINE);
    for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_second_name.size())/2.); i++)
        waddch(m_Window, ' ');
    waddstr(m_Window, show_second_name.c_str());
    for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_second_name.size())/2.); i++)
        waddch(m_Window, ' ');
    wattroff(m_Window, A_UNDERLINE);
    
    // password
    mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - (int) iomanager::strlen(text_password) - LEFT, text_password.c_str());
    wattron(m_Window, A_UNDERLINE);
    for (int i = 0; i < floor((MAXIMAL_SYMBOLS - pseudo_password.size())/2.); i++)
        waddch(m_Window, ' ');
    waddstr(m_Window, pseudo_password.c_str());
    for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - pseudo_password.size())/2.); i++)
        waddch(m_Window, ' ');
    wattroff(m_Window, A_UNDERLINE);
    
    // exit button
    mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    
    refresh();
    wrefresh(m_Window);
}

void Profile::draw_active_login(void) {
    for (int i = 0; i < COLS; i++)
        mvwaddch(m_Window, LINES/4 + 3, i, ' ');
    
    if (deep) {
        curs_set(1);
        
        wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
        mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - (int) iomanager::strlen(text_login) - LEFT, text_login.c_str());
        waddstr(m_Window, show_new_login.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
    } else {
        curs_set(0);
        
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - (int) iomanager::strlen(text_login) - LEFT, text_login.c_str());
        for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_login.size())/2.); i++)
            waddch(m_Window, ' ');
        waddstr(m_Window, show_login.c_str());
        for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_login.size())/2.); i++)
            waddch(m_Window, ' ');
        waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void Profile::draw_active_name(void) {
    for (int i = 0; i < COLS; i++)
        mvwaddch(m_Window, LINES/4 + 5, i, ' ');
    
    if (deep) {
        curs_set(1);
        
        wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
        mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - (int) iomanager::strlen(text_name) - LEFT, text_name.c_str());
        waddstr(m_Window, show_new_name.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
    } else {
        curs_set(0);
        
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - (int) iomanager::strlen(text_name) - LEFT, text_name.c_str());
        for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_name.size())/2.); i++)
            waddch(m_Window, ' ');
        waddstr(m_Window, show_name.c_str());
        for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_name.size())/2.); i++)
            waddch(m_Window, ' ');
        waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void Profile::draw_active_second_name(void) {
    for (int i = 0; i < COLS; i++)
        mvwaddch(m_Window, LINES/4 + 7, i, ' ');
    
    if (deep) {
        curs_set(1);
        
        wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
        mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - (int) iomanager::strlen(text_second_name) - LEFT, text_second_name.c_str());
        waddstr(m_Window, show_new_second_name.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
    } else {
        curs_set(0);
        
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - (int) iomanager::strlen(text_second_name) - LEFT, text_second_name.c_str());
        for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_second_name.size())/2.); i++)
            waddch(m_Window, ' ');
        waddstr(m_Window, show_second_name.c_str());
        for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_second_name.size())/2.); i++)
            waddch(m_Window, ' ');
        waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void Profile::draw_active_password(void) {
    for (int i = 0; i < COLS; i++)
        mvwaddch(m_Window, LINES/4 + 9, i, ' ');
    
    if (deep) {
        curs_set(1);
        
        if (deepPassword) {
            wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
            mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - (int) iomanager::strlen(text_new_password) - LEFT, text_new_password.c_str());
            waddstr(m_Window, show_new_pass.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
        } else {
            wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
            mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - (int) iomanager::strlen(text_old_password) - LEFT, text_old_password.c_str());
            waddstr(m_Window, show_old_pass.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
        }
    } else {
        curs_set(0);
        
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - (int) iomanager::strlen(text_password) - LEFT, text_password.c_str());
        for (int i = 0; i < floor((MAXIMAL_SYMBOLS - pseudo_password.size())/2.); i++)
            waddch(m_Window, ' ');
        waddstr(m_Window, pseudo_password.c_str());
        for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - pseudo_password.size())/2.); i++)
            waddch(m_Window, ' ');
        waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void Profile::draw_active_exit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwprintw(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}
