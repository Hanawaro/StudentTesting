#include "AddTest.hpp"

void AddTest::open(void) {
    init();
    
    while ((locale != Locale::exit) || (!isExit)) {
        switch (locale) {
            case Locale::text_bar:
                if ( active_text_bar() )
                    continue;
                break;
            case Locale::check_bar:
                if ( active_check_bar() )
                    continue;
                break;
            case Locale::next_button:
                if ( active_next_button() )
                    continue;
                break;
            case Locale::back_button:
                if ( active_back_button() )
                    continue;
                break;
            case Locale::complete:
                if ( active_complete() )
                    continue;
                break;
            case Locale::exit:
                if ( active_exit() )
                    continue;
                break;
        }
    }

    delwin(m_TextBar);
    delwin(m_Window);
}

void AddTest::init(void) {
    reset();

    // set defaults
    noecho();
    raw();
    curs_set(0);

    // make window
    m_Window = newwin(LINES, COLS, 0, 0);
    m_TextBar = newwin(6, 70, LINES/4 + 1, (COLS - 70)/2);

    // set window
    wborder(m_Window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    keypad(m_Window, true);
    
    box(m_TextBar, 0, 0);
    keypad(m_TextBar, true);
    
    draw();
}

void AddTest::reset(void) {
    m_Window = nullptr;
    m_TextBar = nullptr;
    
    locale = Locale::text_bar;
    global_locale = GlobalLocale::question;
    is_check_bar = GlobalLocale::question;
    
    isExit = false;
    isMessage = false;
    
    index = 0;
    
    real_question       = "";
    real_first_answer   = "";
    real_second_answer  = "";
    real_third_answer   = "";
    
}
