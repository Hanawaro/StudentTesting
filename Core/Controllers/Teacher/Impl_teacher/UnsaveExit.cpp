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
            isExit = true;
            isAuth = false;
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
