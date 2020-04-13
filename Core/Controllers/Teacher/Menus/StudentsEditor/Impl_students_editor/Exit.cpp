#include "../StudentsEditor.hpp"

bool StudentsEditor::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::ShowMenu;
            break;
        case '\t':
            draw();
            locale = Locale::AddMenu;
            break;
        case '\n':
            isExit = true;
            break;
        default:
            break;
    }

    return false;
}
