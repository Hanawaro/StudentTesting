#include "../Show.hpp"

bool Show::active_first(void) {
    draw_active_first();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::StudentsMenu;
            break;
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::SecondMenu;
            break;
        case '\n':
            // Load first modul
            first_menu.open(users);
            draw();
            break;
        default:
            break;
    }

    return false;
}
