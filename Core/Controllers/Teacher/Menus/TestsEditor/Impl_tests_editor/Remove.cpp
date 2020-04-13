#include "../TestsEditor.hpp"

bool TestsEditor::active_remove(void) {
    draw_active_remove();
        
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
            break;
        case KEY_RIGHT:
            locale = Locale::Edit;
            draw();
            break;
        case '\n':
            deep = false;
            switch (g_locale) {
                case 0:
                    m_db_test_first.remove_test(all_tests[0][index]);
                    break;
                case 1:
                    m_db_test_second.remove_test(all_tests[1][index]);
                    break;
                case 2:
                    m_db_test_third.remove_test(all_tests[2][index]);
                    break;
            }
            all_tests[g_locale].erase(all_tests[g_locale].begin() + index);
            if (all_tests[g_locale].size()%MAXIMAL_TESTS == 0)
                page--;
            set_tests();
            if (!empty[g_locale]) {
                locale = Locale::Show;
                show_locale = ShowLocale::First;
            } else {
                locale = Locale::Add;
            }
            draw();
            break;
        default:
            break;
    }

    return false;
}
