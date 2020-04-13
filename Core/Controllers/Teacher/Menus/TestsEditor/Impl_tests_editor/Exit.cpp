#include "../TestsEditor.hpp"

bool TestsEditor::active_exit(void) {
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case '\t':
        case KEY_DOWN:
            locale = Locale::Change;
            draw();
            break;
        case KEY_UP:
            locale = Locale::Add;
            draw();
            break;
        case KEY_LEFT:
            if (g_locale - 1 >= 0) {
                g_locale--;
                page = 1;
                reset_pages();
                reset_show();
                draw();
            }
            break;
        case KEY_RIGHT:
            if (g_locale + 1 <= 2) {
                g_locale++;
                page = 1;
                reset_pages();
                reset_show();
                draw();
            }
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
