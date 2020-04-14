#include "../../EditMenu.hpp"

bool EditMenu::active_total(void) {
    draw_active_total();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            deep = false;
            // load from db
            mark_total = m_Marks.total;
            reset_total();
            draw();
            mark_locale = MarkLocale::Third;
            break;
        case KEY_DOWN:
        case '\t':
            deep = false;
            // load from db
            mark_total = m_Marks.total;
            reset_total();
            draw();
            mark_locale = MarkLocale::Exit;
            break;
        case KEY_RIGHT:
            if (deep) {
                switch (mark_total) {
                    case Mark::Empty:
                        mark_total = Mark::Two;
                        break;
                    case Mark::Two:
                        mark_total = Mark::Three;
                        break;
                    case Mark::Three:
                        mark_total = Mark::Four;
                        break;
                    case Mark::Four:
                        mark_total = Mark::Five;
                        break;
                    case Mark::Five:
                        break;
                };
            }
            break;
        case KEY_LEFT:
            if (!deep) {
                // load from db
                mark_total = m_Marks.total;
                reset_total();
                change_locale = ChangeLocale::Account;
                account_locale = AccountLocale::Login;
                draw();
            } else {
                switch (mark_total) {
                    case Mark::Empty:
                        break;
                    case Mark::Two:
                        mark_total = Mark::Empty;
                        break;
                    case Mark::Three:
                        mark_total = Mark::Two;
                        break;
                    case Mark::Four:
                        mark_total = Mark::Three;
                        break;
                    case Mark::Five:
                        mark_total = Mark::Four;
                        break;
                };
            }
            break;
        case '\n':
            if (deep) {
                deep = false;
                m_Marks.total = mark_total;
                m_db_student.set_total(m_User->login, m_Marks.total, m_Marks.amount_of_total);
                reset_total();
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
