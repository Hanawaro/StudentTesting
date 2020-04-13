#include "../Student.hpp"

bool StudentMenu::active_show(void) {
    draw_active_show();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_LEFT:
            switch (change_locale) {
                case ChangeLocale::Training:
                    break;
                case ChangeLocale::Testing:
                    change_locale = ChangeLocale::Training;
                    break;
                case ChangeLocale::Info:
                    change_locale = ChangeLocale::Info;
                    locale = Locale::Change;
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
                    locale = Locale::Change;
                    break;
                case ChangeLocale::Info:
                    break;
            }
            draw();
            break;
        case KEY_DOWN:
        case '\t':
            switch (show_locale) {
                case ShowLocale::First:
                    show_locale = ShowLocale::Second;
                    g_show_locale = 2;
                    break;
                case ShowLocale::Second:
                    show_locale = ShowLocale::Third;
                    g_show_locale = 3;
                    break;
                case ShowLocale::Third:
                    show_locale = ShowLocale::Total;
                    g_show_locale = 4;
                    break;
                case ShowLocale::Total:
                    locale = Locale::UnsaveExit;
                    break;
            }
            draw();
            break;
        case KEY_UP:
            switch (show_locale) {
                case ShowLocale::First:
                    locale = Locale::Change;
                    break;
                case ShowLocale::Second:
                    show_locale = ShowLocale::First;
                    g_show_locale = 1;
                    break;
                case ShowLocale::Third:
                    show_locale = ShowLocale::Second;
                    g_show_locale = 2;
                    break;
                case ShowLocale::Total:
                    show_locale = ShowLocale::Third;
                    g_show_locale = 3;
                    break;
            }
            draw();
            break;
        case '\n':
            // load
            if (change_locale == ChangeLocale::Training) {
                training.start();
            } else if (change_locale == ChangeLocale::Testing) {
                switch (show_locale) {
                    case ShowLocale::First:
                        if (m_Student.amount_of_first == 0)
                            return true;
                        break;
                    case ShowLocale::Second:
                        if (m_Student.amount_of_second == 0)
                            return true;
                        break;
                    case ShowLocale::Third:
                        if (m_Student.amount_of_third == 0)
                            return true;
                        break;
                    case ShowLocale::Total:
                        if (m_Student.amount_of_total == 0)
                            return true;
                        break;
                }
                testing.start(m_User);
                load_student();
                reset_marks();
            }
            draw();
            break;
        default:
            break;
    }

    return false;
}
