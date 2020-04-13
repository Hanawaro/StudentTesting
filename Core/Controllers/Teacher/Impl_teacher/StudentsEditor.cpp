#include "../Teacher.hpp"

bool TeacherMenu::active_students_editor(void) {
    draw_active_students_editor();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::Profile;
            break;
        case '\t':
        case KEY_DOWN:
            draw();
            locale = Locale::TestsEditor;
            break;
        case '\n':
            // Open students editor modul
            menu_students.open();
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
