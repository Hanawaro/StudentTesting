#include "../EditMenu.hpp"

bool EditMenu::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            switch (change_locale) {
                case ChangeLocale::Account:
                    account_locale = AccountLocale::Password;
                    break;
                case ChangeLocale::Marks:
                    mark_locale = MarkLocale::Total;
                    break;
            }
            break;
        case KEY_RIGHT:
            if (change_locale == ChangeLocale::Account) {
                change_locale = ChangeLocale::Marks;
                mark_locale = MarkLocale::First;
                draw();
            }
            break;
        case KEY_LEFT:
            if (change_locale == ChangeLocale::Marks) {
                change_locale = ChangeLocale::Account;
                account_locale = AccountLocale::Login;
                draw();
            }
            break;
        case '\t':
            draw();
            switch (change_locale) {
                case ChangeLocale::Account:
                    account_locale = AccountLocale::Change;
                    break;
                case ChangeLocale::Marks:
                    mark_locale = MarkLocale::Change;
                    break;
            }
            break;
        case '\n':
            is_exit = true;
            break;
        default:
            break;
    }
    
    return false;
}
