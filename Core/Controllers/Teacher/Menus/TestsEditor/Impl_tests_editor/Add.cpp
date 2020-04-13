#include "../TestsEditor.hpp"

bool TestsEditor::active_add(void) {
    draw_active_add();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case '\t':
        case KEY_DOWN:
            locale = Locale::Exit;
            draw();
            break;
        case KEY_UP:
            locale = Locale::Pages;
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
            add_test.open();
            set_tests();
            draw();
            break;
        default:
            break;
    }

    return false;
}
