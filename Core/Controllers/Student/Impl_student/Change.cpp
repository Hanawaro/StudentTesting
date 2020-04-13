#include "../Student.hpp"

bool StudentMenu::active_change(void) {
    draw_active_change();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_DOWN:
        case '\t':
            show_locale = ShowLocale::First;
            if (change_locale == ChangeLocale::Info) {
                locale = Locale::UnsaveExit;
            } else {
                locale = Locale::Show;
                g_show_locale = 1;
                show_locale = ShowLocale::First;
            }
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
        default:
            break;
    }

    return false;}
