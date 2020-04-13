#include "../../EditMenu.hpp"

bool EditMenu::active_first(void) {
    draw_active_first();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            deep = false;
            // load from db
            mark_first = m_Marks.first;
            reset_first();
            draw();
            mark_locale = MarkLocale::Change;
            break;
        case KEY_DOWN:
        case '\t':
            deep = false;
            // load from db
            mark_first = m_Marks.first;
            reset_first();
            draw();
            mark_locale = MarkLocale::Second;
            break;
        case KEY_RIGHT:
            if (deep) {
                switch (mark_first) {
                    case Mark::Empty:
                        mark_first = Mark::Two;
                        break;
                    case Mark::Two:
                        mark_first = Mark::Three;
                        break;
                    case Mark::Three:
                        mark_first = Mark::Four;
                        break;
                    case Mark::Four:
                        mark_first = Mark::Five;
                        break;
                    case Mark::Five:
                        break;
                };
            }
            break;
        case KEY_LEFT:
            if (!deep) {
                // load from db
                mark_first = m_Marks.first;
                reset_first();
                change_locale = ChangeLocale::Account;
                account_locale = AccountLocale::Login;
                draw();
            } else {
                switch (mark_first) {
                    case Mark::Empty:
                        break;
                    case Mark::Two:
                        mark_first = Mark::Empty;
                        break;
                    case Mark::Three:
                        mark_first = Mark::Two;
                        break;
                    case Mark::Four:
                        mark_first = Mark::Three;
                        break;
                    case Mark::Five:
                        mark_first = Mark::Four;
                        break;
                };
            }
            break;
        case '\n':
            if (deep) {
                deep = false;
                m_Marks.first = mark_first;
                m_db_student.setFirst(m_User->login, m_Marks.first, m_Marks.amount_of_first);
                reset_first();
                draw();
            } else {
                deep = true;
                
                wcolor_set(m_Window, iomanager::DISABLE, NULL);
                draw();
                wcolor_set(m_Window, iomanager::TEXT, NULL);
            }
            break;
        default:
            break;
    }
    
    return false;
}
