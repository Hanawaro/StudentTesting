#include <ncurses.h>

#include "Core/Core.hpp"

#include "CrossPlatform.hpp"
#include "InitUsers.hpp"

int main(int argc, const char **argv) {
    cp_setlocale();
    
    // Reset users db
    InitUsers::init();
    
    // init ncurses
    initscr();
    
    if (COLS < 80 || LINES < 24) {
        std::cout << "Расширьте окно консоли, для корректной работы приложения" << std::endl;
        return 0;
    }
    
    start_color();
    
    // init default colors
    init_color(COLOR_WHITE, 999, 999, 999);
    init_color(COLOR_RED, 999, 0, 0);
    init_color(COLOR_YELLOW, 999, 500, 0);
    init_color(COLOR_GREEN, 0, 700, 0);
    init_color(COLOR_CYAN, 900, 900, 900);
    init_color(COLOR_BLUE, 999, 300, 200);
    
    // default colors' scene
    assume_default_colors(COLOR_BLACK, COLOR_WHITE);
    
    // init default colors
    init_pair(iomanager::TEXT, COLOR_BLACK, COLOR_WHITE);
    init_pair(iomanager::SUCSESS, COLOR_GREEN, COLOR_WHITE);
    init_pair(iomanager::WARNING, COLOR_YELLOW, COLOR_WHITE);
    init_pair(iomanager::ERROR, COLOR_RED, COLOR_WHITE);
    init_pair(iomanager::SORT, COLOR_BLUE, COLOR_WHITE);
    
    init_pair(iomanager::DISABLE, COLOR_CYAN, COLOR_WHITE);
    init_pair(iomanager::ACTIVE, COLOR_WHITE, COLOR_GREEN);
    
    // start application
    Core core;
    core.start();

    // exit from ncurses mode
    endwin();
}
