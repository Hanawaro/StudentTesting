#ifndef Testing_hpp
#define Testing_hpp

#include <iomanager.hpp>
#include <ncurses.h>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "../../../../DB/User.hpp"
#include "../../../../DB/DB.hpp"

#define TEXT_SIZE   70

extern int g_show_locale;

class Testing {
public:
    void start(const User& user);
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
    void minus_life(void);
    void set_new_result(void);
    
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
    
    User m_User;
    class Student m_Student;
    
    db_user m_db_user;
    db_student m_db_student;
    
    bool isExit = false;
    bool empty = false;
    bool once = false;
    bool isAll = false;

    size_t right_answer = 1;
    size_t right_answers = 0;
    size_t amount_of_tests = 0;
    int counter = 0;
    
    std::vector<Test> tests;
    std::vector<size_t> randomize;
    
    db_test_first  m_db_test_first;
    db_test_second m_db_test_second;
    db_test_third  m_db_test_third;
    
    const std::string text_first_hello  = "Первый тест";
    const std::string text_second_hello = "Второй тест";
    const std::string text_third_hello  = "Третий тест";
    const std::string text_total_hello  = "Итоговый тест";
    
    const std::string text_exit       = " Завершить тест досрочно ";
    const std::string text_result_exit = " Выйти в главное меню ";
    const std::string text_empty_exit = " Выйти без сохранения результата ";
    
    std::string show_question     = "";
    std::string show_first_answer = "";
    std::string show_second_anser = "";
    std::string show_third_anser  = "";
    
    const std::string result_mark = "Ваша оценка: ";
    const std::string result_left = "Правильно ";
    const std::string result_between = " из ";
    
    const std::string error_empty = "Пока что вопросы не добавлены";
};

#endif
