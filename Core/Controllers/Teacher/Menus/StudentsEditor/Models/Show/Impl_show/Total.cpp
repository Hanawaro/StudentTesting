#include "../Show.hpp"

bool Show::active_total(void) {
    draw_active_total();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::ThirdMenu;
            break;
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::Exit;
            break;
        case '\n':
            // Load total modul
            total_menu.open(users);
            draw();
            break;
        default:
            break;
    }

    return false;
}
