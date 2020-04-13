#include "../StudentsEditor.hpp"

bool StudentsEditor::active_add(void) {
    draw_active_add();
        
    int tmp = wgetch(m_Window);
        
    switch (tmp) {
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::EditMenu;
            break;
        case '\n':
            add.open();
            draw();
            break;
        default:
            break;
    }
        
    return false;
}
