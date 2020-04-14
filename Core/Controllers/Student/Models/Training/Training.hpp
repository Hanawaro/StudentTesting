#ifndef Training_hpp
#define Training_hpp

#include <iomanager.hpp>
#include <ncurses.h>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "../../../../DB/DB.hpp"

#define TEXT_SIZE   70

extern int g_show_locale;

class Training {
public:
    void start(void);
private:
    // GUI
    void init(void);
    void draw(void);
    void draw_some(const std::string& some, int line);
    
    bool active_first(void);
    void draw_active_first(void);
    
    bool active_second(void);
    void draw_active_second(void);
    
    bool active_third(void);
    void draw_active_third(void);
    
    bool active_exit(void);
    void draw_active_exit(void);
    
    // db work
    void load_tests(void);
    
    // reset
    void reset(void);
    void reset_test(void);
    void reset_answers(Test& test);
private:
    enum Locale {
        First,
        Second,
        Third,
        Exit
    };
    
    WINDOW* m_Window = nullptr;
    Locale locale = Locale::First;
    
    bool is_exit = false;
    bool isError = false;
    bool empty = false;
    bool once = false;

    size_t right_answer = 1;
    
    std::vector<Test> tests;
    std::vector<size_t> randomize;
    
    db_test_first  m_db_test_first;
    db_test_second m_db_test_second;
    db_test_third  m_db_test_third;
    
    const std::string text_first_hello  = "Тренинг по первому тесту";
    const std::string text_second_hello = "Тренинг по второму тесту";
    const std::string text_third_hello  = "Тренинг по третьему тесту";
    const std::string text_total_hello  = "Тренинг по итоговому тесту";    
    const std::string text_exit = " Выход ";
    
    std::string show_question     = "";
    std::string show_first_answer = "";
    std::string show_second_anser = "";
    std::string show_third_anser  = "";
    
    const std::string error   = "Неправильный вариант ответа";
    const std::string error_empty = "Пока что вопросы не добавлены";
};

#endif
