#ifndef EditMenu_hpp
#define EditMenu_hpp

#include <iomanager.hpp>
#include <ncurses.h>
#include <cmath>

#include "../../../../../../../../DB/User.hpp"
#include "../../../../../../../../DB/DB.hpp"

#define MAXIMAL_SYMBOLS   23
#define LEFT 7

namespace AccountLocale { enum AccountLocale {
    Change,
    Login,
    Name,
    SecondName,
    Password,
    Exit
}; }

namespace MarkLocale { enum MarkLocale {
    Change,
    First,
    Second,
    Third,
    Total,
    Exit
}; }

class EditMenu {
public:
    void open(User* user);
private:
    // GUI
    void draw(void);
    void init(void);
    
    bool active_change(void);
    void draw_active_change(void);
    
    bool active_login(void);
    void draw_active_login(void);
    
    bool active_name(void);
    void draw_active_name(void);
    
    bool active_second_name(void);
    void draw_active_second_name(void);
    
    bool active_password(void);
    void draw_active_password(void);
    
    bool active_first(void);
    void draw_active_first(void);
    
    bool active_second(void);
    void draw_active_second(void);
    
    bool active_third(void);
    void draw_active_third(void);
    
    bool active_total(void);
    void draw_active_total(void);
    
    bool active_exit(void);
    void draw_active_exit(void);
    
    // db work
    bool check_login(void);
    class Student getMarks(void);
    
    // reset
    void reset(void);
    
    void reset_login(void);
    void reset_name(void);
    void reset_second_name(void);
    void reset_password(void);
    
    void clear_password(void);
    
    void reset_first(void);
    void reset_second(void);
    void reset_third(void);
    void reset_total(void);
    
    void clear_error(void);
private:
    enum ChangeLocale {
        Account,
        Marks
    };
    
    WINDOW* m_Window = nullptr;
    User* m_User = nullptr;
    class Student m_Marks;
    db_user m_db_user;
    db_student m_db_student;
    AccountLocale::AccountLocale account_locale = AccountLocale::Login;
    MarkLocale::MarkLocale mark_locale = MarkLocale::First;
    ChangeLocale change_locale = ChangeLocale::Account;
    
    Mark mark_first  = Mark::Empty;
    Mark mark_second = Mark::Empty;
    Mark mark_third  = Mark::Empty;
    Mark mark_total  = Mark::Empty;
    
    bool deep = false;
    bool isExit = false;
    
    // text
    const std::string text_hello            = "Редактирование";
    const std::string text_change_account   = " Аккаунт ";
    const std::string text_change_mark      = " Оценки ";
    
    std::string text_login          = " Логин:  ";
    std::string text_name           = " Имя:  ";
    std::string text_second_name    = " Фамилия:  ";
    std::string text_password       = " Пароль:  ";
    
    const std::string text_first    = " Первый тест:  ";
    const std::string text_second   = " Второй тест:  ";
    const std::string text_third    = " Третий тест:  ";
    const std::string text_total    = "    Зачёт:     ";
    
    const std::string text_exit     = " Назад ";
    
    const std::string pseudo_password = "***********";
    
    const std::string text_empty = "Не пройдено";
    const std::string text_two   = "2";
    const std::string text_three = "3";
    const std::string text_four  = "4";
    const std::string text_five  = "5";
    
    // login input
    std::string show_login;
    std::string real_login;
    std::string show_new_login;
    std::string new_real_login;
    
    // name input
    std::string show_name;
    std::string real_name;
    std::string show_new_name;
    std::string new_real_name;
    
    // second name input
    std::string show_second_name;
    std::string real_second_name;
    std::string show_new_second_name;
    std::string new_real_second_name;
    
    // password input
    std::string show_password;
    std::string real_password;
    
    // marks
    std::string show_first;
    std::string show_second;
    std::string show_third;
    std::string show_total;
    
    // errors
    const std::string error_empty_login         = "Введите логин";
    const std::string error_login               = "Такой логин уже занят";
    const std::string error_empty_name          = "Введите имя";
    const std::string error_empty_second_name   = "Введите фамилию";
    const std::string error_empty_password      = "Введите новый пароль";
};

#endif
