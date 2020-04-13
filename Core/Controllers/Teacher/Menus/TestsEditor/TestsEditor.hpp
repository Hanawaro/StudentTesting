#include <iomanager.hpp>
#include <ncurses.h>
#include <vector>

#include "Models/AddTest/AddTest.hpp"
#include "Models/EditTest/EditTest.hpp"
#include "../../../../DB/DB.hpp"

#undef MAXIMAL_SYMBOLS

#define MAXIMAL_TESTS   6
#define MAXIMAL_SYMBOLS 60

extern int g_locale;

class TestsEditor {
public:
    void open(void);
private:
    // GUI
    void init(void);
    void draw(void);
    
    bool active_change(void);
    void draw_active_change(void);
    
    bool active_show(void);
    void draw_active_show(void);
    
    bool active_pages(void);
    void draw_active_pages(void);
    
    bool active_add(void);
    void draw_active_add(void);
    
    bool active_remove(void);
    void draw_active_remove(void);
    
    bool active_edit(void);
    void draw_active_edit(void);
    
    bool active_exit(void);
    void draw_active_exit(void);
    
    // db work
    void set_tests(void);
    
    // reset
    void reset(void);
    void reset_show(void);
    void reset_pages(void);
private:
    enum Locale {
        Change,
        Show,
        Pages,
        Remove,
        Edit,
        Add,
        Exit
    };
    
    enum ShowLocale {
        First,
        Second,
        Third,
        Fourth,
        Fifth,
        Sixth
    };
    
    WINDOW* m_Window = nullptr;
    Locale locale = Locale::Show;
    ShowLocale show_locale = ShowLocale::First;
    
    db_test_first   m_db_test_first;
    db_test_second  m_db_test_second;
    db_test_third   m_db_test_third;
    
    AddTest add_test;
    EditTest edit_test;
    
    bool empty[3] = { false, false, false };
    bool isExit = false;
    bool deep = false;
    
    int page = 1;
    int pages = 0;
    
    const std::string text_hello        = "Редактирование тестов";
    const std::string text_first        = " Первый ";
    const std::string text_second       = " Второй ";
    const std::string text_third        = " Третий ";
    const std::string text_left         = " < ";
    const std::string text_active_left  = "<< ";
    const std::string text_pages        = " Страница ";
    const std::string text_active_right = " >>";
    const std::string text_right        = "  > ";
    const std::string text_add          = " Добавить ";
    const std::string text_remove       = " Удалить ";
    const std::string text_edit         = " Редактировать ";
    const std::string text_exit         = " Назад ";
    
    std::string text_tests[MAXIMAL_TESTS];
    
    std::vector<Test> all_tests[3];
};
