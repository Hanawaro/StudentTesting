#include "../Teacher.hpp"

bool TeacherMenu::active_tests_editor(void) {
    draw_active_tests_editor();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::StudentsEditor;
            break;
        case '\t':
        case KEY_DOWN:
            draw();
            locale = Locale::UnsaveExit;
            break;
        case '\n':
            // Open tests editor modul
            menu_tests_editor.open();
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
