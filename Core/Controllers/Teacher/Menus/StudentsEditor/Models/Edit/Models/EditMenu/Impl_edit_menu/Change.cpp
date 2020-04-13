#include "../EditMenu.hpp"

bool EditMenu::active_change(void) {
    draw_active_change();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_RIGHT:
            if (change_locale == ChangeLocale::Account) {
                change_locale = ChangeLocale::Marks;
                mark_locale = MarkLocale::Change;
            }
            draw();
            break;
        case KEY_LEFT:
            if (change_locale == ChangeLocale::Marks) {
                change_locale = ChangeLocale::Account;
                account_locale = AccountLocale::Change;
            }
            draw();
            break;
        case KEY_DOWN:
        case '\t':
            draw();
            switch (change_locale) {
                case ChangeLocale::Account:
                    account_locale = AccountLocale::Login;
                    break;
                case ChangeLocale::Marks:
                    mark_locale = MarkLocale::First;
                    break;
            }
            break;
        default:
            break;
    }
    
    return false;
}
