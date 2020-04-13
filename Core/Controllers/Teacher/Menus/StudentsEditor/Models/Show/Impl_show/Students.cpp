#include "../Show.hpp"

bool Show::active_students(void) {
    draw_active_students();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::FirstMenu;
            break;
        case '\n':
            // Load students modul
            students_menu.open(users);
            draw();
            break;
        default:
            break;
    }

    return false;
}
