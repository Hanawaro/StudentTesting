#include "../Student.hpp"

bool StudentMenu::active_unsave_exit(void) {
    draw_active_unsave_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case '\t':
        case KEY_DOWN:
            locale = Locale::Exit;
            draw();
            break;
        case KEY_UP:
            if (change_locale != ChangeLocale::Info) {
                locale = Locale::Show;
                show_locale = ShowLocale::Total;
                g_show_locale = 4;
            } else {
                locale = Locale::Change;
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
        case '\n':
            is_exit = true;
            is_auth = false;
            draw();
            break;
        default:
            break;
    }

    return false;
}
