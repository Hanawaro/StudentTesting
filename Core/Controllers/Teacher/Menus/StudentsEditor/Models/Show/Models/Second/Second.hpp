#ifndef Second_hpp
#define Second_hpp

#include <iomanager.hpp>
#include <vector>
#include <ncurses.h>

#include "../../../../../../../../DB/User.hpp"

#undef MAXIMAL_SYMBOLS

#define MAXIMAL_USERS   8
#define MAXIMAL_SYMBOLS 10

class Second {
public:
    void open(std::vector<info_student> users);
private:
    // GUI
    void init(void);
    void draw(void);
    
    bool active_change(void);
    void draw_active_change(void);

    bool active_pages(void);
    void draw_active_pages(void);
    
    bool active_exit(void);
    void draw_active_exit(void);
    
    // sort
    void set_sort_up(void);
    void set_sort_down(void);
    
    // reset
    void reset(void);
    void reset_pages(void);
private:
    enum Locale {
        Change,
        Pages,
        Exit
    };
    
    enum Sort {
        up,
        down
    };
    
    
    WINDOW* m_Window;
    Locale locale = Locale::Exit;
    Sort sort = Sort::up;
    
    bool empty = false;
    bool is_exit = false;
    
    int page = 1;
    int pages = 0;
    
    const std::string text_hello = "Сортировка учеников по первому тестирование";
    const std::string text_up = " По возрастанию ";
    const std::string text_down = " По убыванию ";
    const std::string text_left = " < ";
    const std::string text_active_left = "<< ";
    const std::string text_pages = " Страница ";
    const std::string text_active_right = " >>";
    const std::string text_right = "  > ";
    const std::string text_exit = " Назад ";
    
    std::string text_users[MAXIMAL_USERS];
    
    std::vector<info_student> all_users;
    std::vector<info_student> sort_up_users;
    std::vector<info_student> sort_down_users;
};

#endif
