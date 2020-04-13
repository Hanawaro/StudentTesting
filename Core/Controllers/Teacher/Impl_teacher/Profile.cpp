#include "../Teacher.hpp"

bool TeacherMenu::active_profile(void) {
    draw_active_profile();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case '\t':
        case KEY_DOWN:
            draw();
            locale = Locale::StudentsEditor;
            break;
        case '\n':
            // Open profile modul
            menu_profile.open(&m_User);
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
