#include "../Teacher.hpp"

bool TeacherMenu::active_unsave_exit(void) {
    draw_active_unsave_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::TestsEditor;
            break;
        case '\t':
        case KEY_DOWN:
            draw();
            locale = Locale::Exit;
            break;
        case '\n':
            is_exit = true;
            is_auth = false;
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
