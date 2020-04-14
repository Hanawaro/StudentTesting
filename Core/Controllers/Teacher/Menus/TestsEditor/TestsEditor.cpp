#include "TestsEditor.hpp"

int g_locale = 0;

void TestsEditor::open(void) {
    init();
    
    while ((locale != Locale::Exit) || (!is_exit)) {
        switch (locale) {
            case Locale::Change:
                if ( active_change() )
                    continue;
                break;
            case Locale::Show:
                if ( active_show() && !empty[g_locale])
                    continue;
                break;
            case Locale::Pages:
                if ( active_pages() && !empty[g_locale] )
                    continue;
                break;
            case Locale::Add:
                if ( active_add() )
                    continue;
                break;
            case Locale::Remove:
                if ( active_remove() && !empty[g_locale] )
                    continue;
                break;
            case Locale::Edit:
                if ( active_edit() && !empty[g_locale] )
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


void TestsEditor::init(void) {
    reset();
    set_tests();
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

void TestsEditor::reset(void) {
    m_Window = nullptr;
    locale = Locale::Show;
    show_locale = ShowLocale::First;
    
    for (size_t i = 0; i < 3; i++) empty[i] = false;
    is_exit = false;
    deep = false;
    
    page = 1;
    pages = 0;
}

void TestsEditor::reset_show(void) {
    if (!empty[g_locale]) {
        int index = (page - 1) * MAXIMAL_TESTS;
        int limit = (index + MAXIMAL_TESTS) < all_tests[g_locale].size() ? index + MAXIMAL_TESTS : (int) all_tests[g_locale].size();
        for (int i = index; i < limit; i++) {
            text_tests[i%MAXIMAL_TESTS].clear();
            if (all_tests[g_locale][i].question.size() > 60) {
                for (size_t j = 0; j < 60 - 1; j++)
                    text_tests[i%MAXIMAL_TESTS] += all_tests[g_locale][i].question[j];
                text_tests[i%MAXIMAL_TESTS] += '.';
            } else {
                text_tests[i%MAXIMAL_TESTS] = all_tests[g_locale][i].question;
            }
        }
    }
}

void TestsEditor::reset_pages(void) {
    if (!empty[g_locale]) {
        if (all_tests[g_locale].size()%MAXIMAL_TESTS == 0)
            pages = (int) all_tests[g_locale].size() / MAXIMAL_TESTS;
        else
            pages = (int) all_tests[g_locale].size() / MAXIMAL_TESTS + 1;
    } else {
        pages = 1;
        page = 1;
        locale = Locale::Change;
    }
}
