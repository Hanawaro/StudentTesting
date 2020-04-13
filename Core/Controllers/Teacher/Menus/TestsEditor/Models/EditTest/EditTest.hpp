#ifndef EditTest_hpp
#define EditTest_hpp

#include <iomanager.hpp>
#include <ncurses.h>
#include "../../../../../../DB/DB.hpp"

extern int g_locale;

class EditTest {
public:
    void open(Test& test);
private:
    // GUI
    void init(void);
    void draw(void);
    
    bool active_text_bar(void);
    void draw_active_text_bar(void);
    
    bool active_check_bar(void);
    void draw_active_check_bar(void);
    
    bool active_next_button(void);
    void draw_active_next_button(void);
    
    bool active_back_button(void);
    void draw_active_back_button(void);
    
    bool active_exit(void);
    void draw_active_exit(void);
    
    void draw_real_some(const std::string& some);
    // db work
    void edit_test(void);
    
    // reset
    void reset(void);
private:
    enum Locale {
        text_bar,
        check_bar,
        next_button,
        back_button,
        exit
    };
    
    enum GlobalLocale {
        question,
        first_answer,
        second_answer,
        third_answer
    };
    
    WINDOW* m_Window = nullptr;
    WINDOW* m_TextBar = nullptr;
    
    Locale locale = Locale::text_bar;
    GlobalLocale global_locale = GlobalLocale::question;
    GlobalLocale is_check_bar = GlobalLocale::question;
    
    db_test_first   m_db_test_first;
    db_test_second  m_db_test_second;
    db_test_third   m_db_test_third;
    
    Test m_Test;
    
    bool isExit = false;
    bool isMessage = false;
    
    int index = 0;
    
    std::string real_question       = "";
    std::string real_first_answer   = "";
    std::string real_second_answer  = "";
    std::string real_third_answer   = "";
    std::string message             = "";
    
    const std::string text_hello_question       = "Вопрос";
    const std::string text_hello_first_answer   = "Первый вариант ответа";
    const std::string text_hello_second_answer  = "Второй вариант ответа";
    const std::string text_hello_third_answer   = "Третий вариант ответа";
    
    const std::string text_next                 = " Дальше ";
    const std::string text_back                 = " Назад ";
    const std::string text_active_check_bar     = " [*] Привильный ответ ";
    const std::string text_disable_check_bar    = " [ ] Привильный ответ ";
    const std::string text_exit                 = " Сохранить и выйти ";

    const std::string error_question        = "Вопрос не может быть пустым";
    const std::string error_first_answer    = "Первый вариант ответа не может быть пустым";
    const std::string error_second_answer   = "Второй вариант ответа не может быть пустым";
    const std::string error_third_answer    = "Третий вариант ответа не может быть пустым";
    const std::string error_true_answer     = "Выберите правильный вариант ответа";
};

#endif
