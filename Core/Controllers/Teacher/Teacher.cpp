#include "Teacher.hpp"

bool TeacherMenu::open(User user) {
    m_User = user;
    
    init();
    
    while ((locale != Locale::Exit && locale != Locale::UnsaveExit) || (!isExit)) {
        switch (locale) {
            case Locale::Profile:
                if ( active_profile() )
                    continue;
                break;
            case Locale::TestsEditor:
                if ( active_tests_editor() )
                    continue;
                break;
            case Locale::StudentsEditor:
                if ( active_students_editor() )
                    continue;
                break;
            case Locale::UnsaveExit:
                if ( active_unsave_exit() )
                    continue;
                break;
            case Locale::Exit:
                if ( active_exit() )
                    continue;
                break;
        }
    }
    
    delwin(m_Window);
    
    if (!isAuth) {
        std::ofstream authorization("Source/authorization");
        authorization.close();
        return true;
    }
    
    return false;
}

void TeacherMenu::init(void) {
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

void TeacherMenu::reset(void) {
    m_Window = nullptr;
    locale = Locale::Profile;

    isAuth = true;
    isExit = false;
}
