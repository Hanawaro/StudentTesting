#include "../../EditMenu.hpp"

bool EditMenu::active_second(void) {
    draw_active_second();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            deep = false;
            // load from db
            mark_second = m_Marks.second;
            reset_second();
            draw();
            mark_locale = MarkLocale::First;
            break;
        case KEY_DOWN:
        case '\t':
            deep = false;
            // load from db
            mark_second = m_Marks.second;
            reset_second();
            draw();
            mark_locale = MarkLocale::Third;
            break;
        case KEY_RIGHT:
            if (deep) {
                switch (mark_second) {
                    case Mark::Empty:
                        mark_second = Mark::Two;
                        break;
                    case Mark::Two:
                        mark_second = Mark::Three;
                        break;
                    case Mark::Three:
                        mark_second = Mark::Four;
                        break;
                    case Mark::Four:
                        mark_second = Mark::Five;
                        break;
                    case Mark::Five:
                        break;
                };
            }
            break;
        case KEY_LEFT:
            if (!deep) {
                // load from db
                mark_second = m_Marks.second;
                reset_second();
                change_locale = ChangeLocale::Account;
                account_locale = AccountLocale::Login;
                draw();
            } else {
                switch (mark_second) {
                    case Mark::Empty:
                        break;
                    case Mark::Two:
                        mark_second = Mark::Empty;
                        break;
                    case Mark::Three:
                        mark_second = Mark::Two;
                        break;
                    case Mark::Four:
                        mark_second = Mark::Three;
                        break;
                    case Mark::Five:
                        mark_second = Mark::Four;
                        break;
                };
            }
            break;
        case '\n':
            if (deep) {
                deep = false;
                m_Marks.second = mark_second;
                m_db_student.set_second(m_User->login, m_Marks.second, m_Marks.amount_of_second);
                reset_second();
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
