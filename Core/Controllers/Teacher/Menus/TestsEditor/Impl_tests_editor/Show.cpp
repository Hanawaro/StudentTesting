#include "../TestsEditor.hpp"

bool TestsEditor::active_show(void) {
    draw_active_show();
    
    int tmp = wgetch(m_Window);
    int index = (page - 1) * MAXIMAL_TESTS;
    int limit = (index + MAXIMAL_TESTS) < all_tests[g_locale].size() ? index + MAXIMAL_TESTS : (int) all_tests[g_locale].size();
    
    switch (tmp) {
        case KEY_RIGHT:
            if (page < pages) {
                page++;
                index = (page - 1) * MAXIMAL_TESTS;
                limit = (index + MAXIMAL_TESTS) < all_tests[g_locale].size() ? index + MAXIMAL_TESTS : (int) all_tests[g_locale].size();
                limit = limit%MAXIMAL_TESTS == 0 ? 6 : limit%MAXIMAL_TESTS;
                if ((int) show_locale + 1 > limit)
                    show_locale = (ShowLocale) (limit - 1);
                reset_show();
                draw();
            }
            break;
        case KEY_LEFT:
            if (page > 1) {
                page--;
                index = (page - 1) * MAXIMAL_TESTS;
                limit = (index + MAXIMAL_TESTS) < all_tests[g_locale].size() ? index + MAXIMAL_TESTS : (int) all_tests[g_locale].size();
                reset_show();
                draw();
            }
        break;
        case KEY_DOWN:
        case '\t':
            switch (show_locale) {
                case ShowLocale::First:
                    if (index + 1 < all_tests[g_locale].size())
                        show_locale = ShowLocale::Second;
                    else
                        locale = Pages;
                    break;
                case ShowLocale::Second:
                    if (index + 2 < all_tests[g_locale].size())
                        show_locale = ShowLocale::Third;
                    else
                        locale = Pages;
                    break;
                case ShowLocale::Third:
                    if (index + 3 < all_tests[g_locale].size())
                        show_locale = ShowLocale::Fourth;
                    else
                        locale = Pages;
                    break;
                case ShowLocale::Fourth:
                    if (index + 4 < all_tests[g_locale].size())
                        show_locale = ShowLocale::Fifth;
                    else
                        locale = Pages;
                    break;
                case ShowLocale::Fifth:
                    if (index + 5 < all_tests[g_locale].size())
                        show_locale = ShowLocale::Sixth;
                    else
                        locale = Pages;
                    break;
                case ShowLocale::Sixth:
                    locale = Locale::Pages;
                    break;
            }
            draw();
            break;
        case KEY_UP:
            switch (show_locale) {
                case ShowLocale::First:
                    locale = Locale::Change;
                    break;
                case ShowLocale::Second:
                    show_locale = ShowLocale::First;
                    break;
                case ShowLocale::Third:
                    show_locale = ShowLocale::Second;
                    break;
                case ShowLocale::Fourth:
                    show_locale = ShowLocale::Third;
                    break;
                case ShowLocale::Fifth:
                    show_locale = ShowLocale::Fourth;
                    break;
                case ShowLocale::Sixth:
                    show_locale = ShowLocale::Fifth;
                    break;
            }
            draw();
            break;
        case '\n':
            deep = true;
            locale = Locale::Edit;
            draw();
            break;
        default:
            break;
    }

    return false;
}
