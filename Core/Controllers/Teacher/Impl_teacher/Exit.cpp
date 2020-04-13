#include "../Teacher.hpp"

bool TeacherMenu::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::UnsaveExit;
            break;
        case '\t':
            draw();
            locale = Locale::Profile;
            break;
        case '\n':
            isExit = true;
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
