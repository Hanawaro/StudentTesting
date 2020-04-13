#include "../Student.hpp"

bool StudentMenu::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case '\t':
            locale = Locale::Change;
            draw();
            break;
        case KEY_UP:
            locale = Locale::UnsaveExit;
            draw();
            break;
        case KEY_LEFT:
            switch (change_locale) {
                case ChangeLocale::Training:
                    break;
                case ChangeLocale::Testing:
                    change_locale = ChangeLocale::Training;
                    break;
                case ChangeLocale::Info:
                    change_locale = ChangeLocale::Testing;
                    break;
            }
            draw();
            break;
        case KEY_RIGHT:
            switch (change_locale) {
                case ChangeLocale::Training:
                    change_locale = ChangeLocale::Testing;
                    break;
                case ChangeLocale::Testing:
                    change_locale = ChangeLocale::Info;
                    break;
                case ChangeLocale::Info:
                    break;
            }
            draw();
            break;
        case '\n':
            isExit = true;
            draw();
            break;
        default:
            break;
    }

    return false;
}
