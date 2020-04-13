#include "../TestsEditor.hpp"

bool TestsEditor::active_edit(void) {
    draw_active_edit();
    
    int tmp = wgetch(m_Window);
    int index = (page - 1) * MAXIMAL_TESTS + (int) show_locale;
    
    switch (tmp) {
        case '\t':
        case KEY_DOWN:
            deep = false;
            locale = Locale::Exit;
            draw();
            break;
        case KEY_UP:
            deep = false;
            locale = Locale::Add;
            draw();
            break;
        case KEY_LEFT:
            locale = Locale::Remove;
            draw();
            break;
        case KEY_RIGHT:
            break;
        case '\n':
            deep = false;
            edit_test.open(all_tests[g_locale][index]);
            set_tests();
            draw();
            break;
        default:
            break;
    }

    return false;
}
