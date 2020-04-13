#include "../Show.hpp"

bool Show::active_second(void) {
    draw_active_second();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::FirstMenu;
            break;
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::ThirdMenu;
            break;
        case '\n':
            // Load second modul
            second_menu.open(users);
            draw();
            break;
        default:
            break;
    }

    return false;
}
