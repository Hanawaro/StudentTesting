#include "../Profile.hpp"

bool Profile::active_password(void) {
    draw_active_password();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            deep = false;
            clear_password();
            draw();
            locale = Locale::SecondName;
            break;
        case KEY_DOWN:
        case '\t':
            deep = false;
            clear_password();
            draw();
            locale = Locale::Exit;
            break;
        case KEY_RIGHT:
        case KEY_LEFT:
            return true;
        case '\n':
            if (deepPassword) {
                if (check_password()) {
                    // db password
                    m_db_user.set_password(m_User->login, real_new_pass);
                    set_save_password();
                    
                    deep = false;
                    deepPassword = false;
                    
                    clear_password();

                    wcolor_set(m_Window, iomanager::TEXT, NULL);
                    draw();
                    
                    draw_active_password();
                } else {
                    deep = true;
                    deepPassword = true;
                }
            } else if (deep) {
                if (check_password()) {
                    deepPassword = true;

                    wcolor_set(m_Window, iomanager::DISABLE, NULL);
                    draw();
                    wcolor_set(m_Window, iomanager::TEXT, NULL);
                    
                    draw_active_password();
                } else {
                    deep = true;
                    deepPassword = false;
                }
            } else {
                deep = true;
                
                wcolor_set(m_Window, iomanager::DISABLE, NULL);
                draw();
                wcolor_set(m_Window, iomanager::TEXT, NULL);
                
                draw_active_password();
            }
            break;
        case KEY_BACKSPACE:
        case KEY_DC:
        case 127:
            clear_error();
            
            if (deepPassword) {
                real_new_pass.resize( ((int)real_new_pass.size() - 1 < 0) ? real_new_pass.size() : real_new_pass.size() - 1);
                reset_new_password();
                draw_active_password();
            } else if (deep) {
                real_old_pass.resize( ((int)real_old_pass.size() - 1 < 0) ? real_old_pass.size() : real_old_pass.size() - 1);
                reset_old_password();
                draw_active_password();
            }
            break;
        default:
            clear_error();
            
            if (deepPassword) {
                if (tmp < EOF || tmp > 127 || real_new_pass.size() >= 255)
                    return true;
                
                real_new_pass += tmp;
                reset_new_password();
                draw_active_password();
            } else if (deep) {
                if (tmp < EOF || tmp > 127 || real_old_pass.size() >= 255)
                    return true;
                
                real_old_pass += tmp;
                reset_old_password();
                draw_active_password();
            }
            break;
    }
    
    return false;
}
