#include "StudentsEditor.hpp"

void StudentsEditor::open(void) {
    init();
    while ((locale != Locale::Exit) || (!is_exit)) {
        switch (locale) {
            case Locale::AddMenu:
                if ( active_add() )
                    continue;
                break;
            case Locale::EditMenu:
                if ( active_edit() )
                    continue;
                break;
            case Locale::ShowMenu:
                if ( active_show() )
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

void StudentsEditor::init(void) {
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

void StudentsEditor::reset(void) {
    m_Window = nullptr;
    locale = Locale::AddMenu;
    is_exit = false;
}
