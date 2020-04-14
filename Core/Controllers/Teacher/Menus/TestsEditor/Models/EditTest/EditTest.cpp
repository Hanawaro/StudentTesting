#include "EditTest.hpp"

void EditTest::open(Test& test) {
    m_Test = test;
    
    init();
    
    while ((locale != Locale::exit) || (!is_exit)) {
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
            case Locale::exit:
                if ( active_exit() )
                    continue;
                break;
        }
    }

    delwin(m_TextBar);
    delwin(m_Window);
}

void EditTest::init(void) {
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

void EditTest::reset(void) {
    m_Window = nullptr;
    m_TextBar = nullptr;
    
    locale = Locale::text_bar;
    global_locale = GlobalLocale::question;
    
    is_exit = false;
    isMessage = false;
    
    switch (m_Test.right) {
        case 1:
            is_check_bar = GlobalLocale::first_answer;
            break;
        case 2:
            is_check_bar = GlobalLocale::second_answer;
            break;
        case 3:
            is_check_bar = GlobalLocale::third_answer;
            break;
    }
    
    real_question       = m_Test.question;
    real_first_answer   = m_Test.answer[0];
    real_second_answer  = m_Test.answer[1];
    real_third_answer   = m_Test.answer[2];
    
    index = (int) real_question.size();
}
