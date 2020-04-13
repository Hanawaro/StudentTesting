#include "Show.hpp"

void Show::open(void) {
    init();
    while ((locale != Locale::Exit) || (!isExit)) {
        switch (locale) {
            case Locale::StudentsMenu:
                if ( active_students() )
                    continue;
                break;
            case Locale::FirstMenu:
                if ( active_first() )
                    continue;
                break;
            case Locale::SecondMenu:
                if ( active_second() )
                    continue;
                break;
            case Locale::ThirdMenu:
                if ( active_third() )
                    continue;
                break;
            case Locale::TotalMenu:
                if ( active_total() )
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

void Show::init(void) {
    reset();
    
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

void Show::reset(void) {
    load_users();
    
    m_Window = nullptr;
    locale = Locale::StudentsMenu;
    
    isExit = false;
}
