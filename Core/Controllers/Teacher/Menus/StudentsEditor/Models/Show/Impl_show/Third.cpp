#include "../Show.hpp"

bool Show::active_third(void) {
    draw_active_third();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::SecondMenu;
            break;
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::TotalMenu;
            break;
        case '\n':
            // Load third modul
            third_menu.open(users);
            draw();
            break;
        default:
            break;
    }

    return false;
}
