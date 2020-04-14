#ifndef Student_hpp
#define Student_hpp

#include <iomanager.hpp>
#include <ncurses.h>

#include "../../DB/User.hpp"
#include "../../DB/DB.hpp"

#include "Models/Training/Training.hpp"
#include "Models/Testing/Testing.hpp"

#undef MAXIMAL_SYMBOLS

#define MAXIMAL_SYMBOLS 23

extern int g_show_locale;

class StudentMenu {
public:
    bool open(User user);
private:
    // GUI
    void init(void);
    void draw(void);
    
    bool active_change(void);
    void draw_active_change(void);
    
    bool active_show(void);
    void draw_active_show(void);
    
    bool active_unsave_exit(void);
    void draw_active_unsave_exit(void);
    
    bool active_exit(void);
    void draw_active_exit(void);
    
    // db work
    void load_student(void);
    
    // reset
    void reset(void);
    void reset_login(void);
    void reset_name(void);
    void reset_second_name(void);
    void reset_marks(void);
private:
    enum Locale {
        Change,
        Show,
        UnsaveExit,
        Exit
    };
    
    enum ChangeLocale {
        Training,
        Testing,
        Info
    };
    
    enum ShowLocale {
        First,
        Second,
        Third,
        Total
    };
    
    WINDOW* m_Window;
    Locale locale = Locale::Change;
    ShowLocale show_locale = ShowLocale::First;
    ChangeLocale change_locale = ChangeLocale::Training;
    
    User m_User;
    class Student m_Student;
    
    class Training training;
    class Testing testing;
    
    db_student m_db_student;
    
    bool is_auth = true;
    bool is_exit = false;
    
    const std::string text_hello        = "Добро пожаловать!";
    const std::string text_training     = " Тренинг ";
    const std::string text_testing      = " Тестирование ";
    const std::string text_info         = " Информация ";
    const std::string text_unsave_exit  = " Выйти из системы ";
    const std::string text_exit         = " Выйти ";
    
    const std::string text_first_test   = " Первый тест ";
    const std::string text_second_test  = " Второй тест ";
    const std::string text_third_test   = " Третий тест ";
    const std::string text_total_test_training   = " Зачёт ";
    const std::string text_total_test_testing   = "    Зачёт    ";
    
    std::string text_login              = " Логин:  ";
    std::string text_name               = " Имя:  ";
    std::string text_second_name        = " Фамилия:  ";
    
    const std::string text_first_mark   = " Первый тест:  ";
    const std::string text_second_mark  = " Второй тест:  ";
    const std::string text_third_mark   = " Третий тест:  ";
    const std::string text_total_mark   = " Зачёт:  ";
    
    const std::string text_middle = "  :   ";
    
    std::string show_login       = "";
    std::string show_name        = "";
    std::string show_second_name = "";
    std::string show_first_mark  = "";
    std::string show_second_mark = "";
    std::string show_third_mark  = "";
    std::string show_total_mark  = "";
};

#endif
