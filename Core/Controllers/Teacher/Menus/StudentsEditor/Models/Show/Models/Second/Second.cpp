#include "Second.hpp"

void Second::open(std::vector<info_student> users) {
    all_users = users;
    init();
    while ((locale != Locale::Exit) || (!isExit)) {
        switch (locale) {
            case Locale::Change:
                if ( active_change() && !empty)
                    continue;
                break;
            case Locale::Pages:
                if ( active_pages() && !empty )
                    continue;
                break;
            case Locale::Exit:
                if ( active_exit() )
                    continue;
                break;
        }
    }
    
    delwin(m_Window);
}

void Second::init(void) {
    reset();
    reset_pages();
    
    // set defaults
    noecho();
    raw();
    curs_set(0);

    // make window
    m_Window = newwin(LINES, COLS, 0, 0);

    // set window
    wborder(m_Window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    keypad(m_Window, true);

    // draw
    color_set(iomanager::TEXT, NULL);
    
    draw();
}

void Second::reset(void) {
    m_Window = nullptr;
    locale = Locale::Exit;
    sort = Sort::up;
    
    empty = false;
    isExit = false;
    
    page = 1;
    pages = 0;
}

void Second::reset_pages(void) {
    set_sort_up();
    if (!empty) {
        set_sort_down();
        if ((int) sort_up_users.size()%MAXIMAL_USERS == 0)
            pages = (int) sort_up_users.size() / MAXIMAL_USERS;
        else
            pages = (int) sort_up_users.size() / MAXIMAL_USERS + 1;    }
}
