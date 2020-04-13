#include "../TestsEditor.hpp"

void TestsEditor::draw(void) {
    wclear(m_Window);
    
    int index = 0, limit = 0;
    
    // hello
    mvwaddstr(m_Window, LINES/4 - 2, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
    
    if (deep) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
    
    switch (g_locale) {
        case 0:
            // change
            wattron(m_Window, A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2 - (int) iomanager::strlen(text_first) - 4, text_first.c_str());
            wattroff(m_Window, A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2, text_second.c_str());
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_second))/2 + 4, text_third.c_str());
            
            // show
            index = (page - 1) * MAXIMAL_TESTS;
            limit = (index + MAXIMAL_TESTS) < all_tests[0].size() ? index + MAXIMAL_TESTS : (int) all_tests[0].size();
            break;
        case 1:
            // change
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2 - (int) iomanager::strlen(text_first) - 4, text_first.c_str());
            wattron(m_Window, A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2, text_second.c_str());
            wattroff(m_Window, A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_second))/2 + 4, text_third.c_str());

            // show
            index = (page - 1) * MAXIMAL_TESTS;
            limit = (index + MAXIMAL_TESTS) < all_tests[1].size() ? index + MAXIMAL_TESTS : (int) all_tests[1].size();
            break;
        case 2:
            // change
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2 - (int) iomanager::strlen(text_first) - 4, text_first.c_str());
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2, text_second.c_str());
            wattron(m_Window, A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_second))/2 + 4, text_third.c_str());
            wattroff(m_Window, A_UNDERLINE);
            
            // show
            index = (page - 1) * MAXIMAL_TESTS;
            limit = (index + MAXIMAL_TESTS) < all_tests[2].size() ? index + MAXIMAL_TESTS : (int) all_tests[2].size();
            
            break;
    }
    
    if (deep) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
    
    // show draw
    if (!empty[g_locale])
        for (size_t i = index; i < limit; i++) {
            if (deep && i == (int) show_locale)
                wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
            else if (deep)
                wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
            mvwaddstr(m_Window, LINES/4 + 2 + i%MAXIMAL_TESTS, (COLS - (int) iomanager::strlen(text_tests[i%MAXIMAL_TESTS]))/2, text_tests[i%MAXIMAL_TESTS].c_str());
            if (deep && i == (int) show_locale)
                wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
            else if (deep)
                wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
        }
    
    if (deep) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
    
    // pages
    if (page <= 1 && !deep) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
    mvwaddstr(m_Window, LINES/4 + 9, (COLS - (int) iomanager::strlen(text_left + text_right + text_pages + std::to_string(page)))/2, text_left.c_str());
    if (page <= 1 && !deep) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
    waddstr(m_Window, text_pages.c_str());
    waddstr(m_Window, std::to_string(page).c_str());
    if (page >= pages && !deep) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
    waddstr(m_Window, text_right.c_str());
    if (page >= pages && !deep) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
    
    // add
    mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(text_add))/2, text_add.c_str());
    
    // remove and edit
    if (deep)
        wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
    else
        wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
    
    if (empty[g_locale] && !deep) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
    mvwaddstr(m_Window, LINES/4 + 13, COLS/2 - 4 - (int) iomanager::strlen(text_remove), text_remove.c_str());
    mvwaddstr(m_Window, LINES/4 + 13, COLS/2 + 2, text_edit.c_str());
    if (empty[g_locale] && !deep) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
    
    if (deep)
        wattron(m_Window, COLOR_PAIR(iomanager::DISABLE));
    else
        wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
    
    // exit
    mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    
    if (deep) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));
    
    wrefresh(m_Window);
}

void TestsEditor::draw_active_change(void) {
    switch (g_locale) {
        case 0:
            wattron(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2 - (int) iomanager::strlen(text_first) - 4, text_first.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2, text_second.c_str());
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_second))/2 + 4, text_third.c_str());
            break;
        case 1:
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2 - (int) iomanager::strlen(text_first) - 4, text_first.c_str());
            wattron(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2, text_second.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_second))/2 + 4, text_third.c_str());
            break;
        case 2:
            
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2 - (int) iomanager::strlen(text_first) - 4, text_first.c_str());
            mvwaddstr(m_Window, LINES/4, (COLS - (int) iomanager::strlen(text_second))/2, text_second.c_str());
            wattron(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4, (COLS + (int) iomanager::strlen(text_second))/2 + 4, text_third.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            break;
    }
}

void TestsEditor::draw_active_show(void) {
    switch (show_locale) {
        case ShowLocale::First:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddch(m_Window, LINES/4 + 2, (COLS - (int) iomanager::strlen(text_tests[0]))/2 - 1, ' ');
            waddstr(m_Window, text_tests[0].c_str());
            waddch(m_Window, ' ');
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        case ShowLocale::Second:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddch(m_Window, LINES/4 + 2 + 1, (COLS - (int) iomanager::strlen(text_tests[1]))/2 - 1, ' ');
            waddstr(m_Window, text_tests[1].c_str());
            waddch(m_Window, ' ');
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        case ShowLocale::Third:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddch(m_Window, LINES/4 + 2 + 2, (COLS - (int) iomanager::strlen(text_tests[2]))/2 - 1, ' ');
            waddstr(m_Window, text_tests[2].c_str());
            waddch(m_Window, ' ');
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        case ShowLocale::Fourth:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddch(m_Window, LINES/4 + 2 + 3, (COLS - (int) iomanager::strlen(text_tests[3]))/2 - 1, ' ');
            waddstr(m_Window, text_tests[3].c_str());
            waddch(m_Window, ' ');
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        case ShowLocale::Fifth:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddch(m_Window, LINES/4 + 2 + 4, (COLS - (int) iomanager::strlen(text_tests[4]))/2 - 1, ' ');
            waddstr(m_Window, text_tests[4].c_str());
            waddch(m_Window, ' ');
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
        case ShowLocale::Sixth:
            wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            mvwaddch(m_Window, LINES/4 + 2 + 5, (COLS - (int) iomanager::strlen(text_tests[5]))/2 - 1, ' ');
            waddstr(m_Window, text_tests[5].c_str());
            waddch(m_Window, ' ');
            wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
            break;
    }
}

void TestsEditor::draw_active_pages(void) {
    if (page <= 1) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE)); else
        wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
    mvwaddstr(m_Window, LINES/4 + 9, (COLS - 1 - (int) iomanager::strlen(text_active_left + text_active_right + text_pages + std::to_string(page)))/2, text_active_left.c_str());
    if (page <= 1) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));  else
           wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
    wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
    waddstr(m_Window, text_pages.c_str());
    waddstr(m_Window, std::to_string(page).c_str());
    waddch(m_Window, ' ');
    wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
    if (page >= pages) wattron(m_Window, COLOR_PAIR(iomanager::DISABLE)); else
           wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
    waddstr(m_Window, text_active_right.c_str());
    if (page >= pages) wattroff(m_Window, COLOR_PAIR(iomanager::DISABLE));  else
           wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
}

void TestsEditor::draw_active_add(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(text_add))/2, text_add.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void TestsEditor::draw_active_remove(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 13, COLS/2 - 4 - (int) iomanager::strlen(text_remove), text_remove.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void TestsEditor::draw_active_edit(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 13, COLS/2 + 2, text_edit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void TestsEditor::draw_active_exit(void) {
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 15, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}
