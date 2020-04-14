#include "../Authorization.hpp"

bool Authorization::active_exit(void) {
    
    draw_active_exit();
    
    int tmp = wgetch(m_Window);
    
    switch (tmp) {
        case '\n':
            is_exit = true;
            break;
        case KEY_UP:
        case KEY_RIGHT:
            wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
            mvwaddstr(m_Window, LINES/4 + 11, (COLS - (int) iomanager::strlen(text_exit))/2 - 5, text_exit.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
            locale = Locale::Enter;
            break;
        case '\t':
            draw();
            locale = Locale::Login;
            break;
        default:
            break;
    }
    
    return false;
}
