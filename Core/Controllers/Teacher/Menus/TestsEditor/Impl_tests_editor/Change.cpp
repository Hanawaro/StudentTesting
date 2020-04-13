#include "../TestsEditor.hpp"

bool TestsEditor::active_change(void) {
    draw_active_change();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case KEY_DOWN:
        case '\t':
            if (!empty[g_locale]) {
                locale = Locale::Show;
                show_locale = ShowLocale::First;
            } else {
                locale = Locale::Pages;
            }
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
        default:
            break;
    }

    return false;
}
