#include "../Authorization.hpp"

bool Authorization::active_save(void) {
    
    draw_active_save();
    
    int tmp = wgetch(m_Window);
    switch (tmp) {
        case KEY_LEFT:
        case KEY_RIGHT:
        case '\n':
            isSave = !isSave;
            if (isSave)
                text_save[2] = '*';
            else
                text_save[2] = ' ';
            break;
        case KEY_UP:
            draw();
            locale = Locale::Password;
            break;
        case '\t':
        case KEY_DOWN:
            draw();
            locale = Locale::Enter;
            break;
        default:
            break;
    }
    
    return false;
}
