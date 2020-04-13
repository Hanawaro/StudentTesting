#include "../StudentsEditor.hpp"

bool StudentsEditor::active_show(void) {
    draw_active_show();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_UP:
            draw();
            locale = Locale::EditMenu;
            break;
        case KEY_DOWN:
        case '\t':
            draw();
            locale = Locale::Exit;
            break;
        case '\n':
            show.open();
            draw();
            break;
        default:
            break;
    }
    
    return false;
}
