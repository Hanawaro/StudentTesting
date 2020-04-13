#include "../TestsEditor.hpp"

bool TestsEditor::active_pages(void) {
    draw_active_pages();
    
    int tmp = wgetch(m_Window);
    int index = (page - 1) * MAXIMAL_TESTS;
    int limit = (index + MAXIMAL_TESTS) < all_tests[g_locale].size() ? index + MAXIMAL_TESTS : (int) all_tests[g_locale].size();

    switch (tmp) {
        case KEY_RIGHT:
            if (page < pages) {
                page++;
                reset_show();
                draw();
            }
            break;
        case KEY_LEFT:
            if (page > 1) {
                page--;
                reset_show();
                draw();
            }
        break;
        case KEY_DOWN:
        case '\t':
            locale = Locale::Add;
            draw();
            break;
        case KEY_UP:
            if (!empty[g_locale]) {
                locale = Locale::Show;
                show_locale = (ShowLocale) ((limit - 1)%MAXIMAL_TESTS);
            } else {
                locale = Locale::Change;
            }
            draw();
            break;
        default:
            break;
    }

    return false;
}
