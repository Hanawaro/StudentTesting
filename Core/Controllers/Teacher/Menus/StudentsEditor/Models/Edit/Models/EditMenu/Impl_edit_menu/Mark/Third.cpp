#include "../../EditMenu.hpp"

bool EditMenu::active_third(void) {
    draw_active_third();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            deep = false;
            // load from db
            mark_third = m_Marks.third;
            reset_third();
            draw();
            mark_locale = MarkLocale::Second;
            break;
        case KEY_DOWN:
        case '\t':
            deep = false;
            // load from db
            mark_third = m_Marks.third;
            reset_third();
            draw();
            mark_locale = MarkLocale::Total;
            break;
        case KEY_RIGHT:
            if (deep) {
                switch (mark_third) {
                    case Mark::Empty:
                        mark_third = Mark::Two;
                        break;
                    case Mark::Two:
                        mark_third = Mark::Three;
                        break;
                    case Mark::Three:
                        mark_third = Mark::Four;
                        break;
                    case Mark::Four:
                        mark_third = Mark::Five;
                        break;
                    case Mark::Five:
                        break;
                };
            }
            break;
        case KEY_LEFT:
            if (!deep) {
                // load from db
                mark_third = m_Marks.third;
                reset_third();
                change_locale = ChangeLocale::Account;
                account_locale = AccountLocale::Login;
                draw();
            } else {
                switch (mark_third) {
                    case Mark::Empty:
                        break;
                    case Mark::Two:
                        mark_third = Mark::Empty;
                        break;
                    case Mark::Three:
                        mark_third = Mark::Two;
                        break;
                    case Mark::Four:
                        mark_third = Mark::Three;
                        break;
                    case Mark::Five:
                        mark_third = Mark::Four;
                        break;
                };
            }
            break;
        case '\n':
            if (deep) {
                deep = false;
                m_Marks.third = mark_third;
                m_db_student.set_third(m_User->login, m_Marks.third, m_Marks.amount_of_third);
                reset_third();
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
