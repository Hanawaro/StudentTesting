#include "../StudentsEditor.hpp"

bool StudentsEditor::active_edit(void) {
    draw_active_edit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::AddMenu;
            break;
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::ShowMenu;
            break;
        case KEY_RIGHT:
            break;
        case KEY_LEFT:
            break;
        case '\n':
            edit.open();
            draw();
            break;
        default:
            break;
    }
 
    return false;
}
