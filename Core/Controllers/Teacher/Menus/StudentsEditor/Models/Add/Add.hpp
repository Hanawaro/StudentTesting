#ifndef Add_hpp
#define Add_hpp

#include <iomanager.hpp>
#include <ncurses.h>

#include "../../../../../../DB/User.hpp"
#include "../../../../../../DB/DB.hpp"

#define MAXIMAL_SYMBOLS   23
#define LEFT 7

class Add {
public:
    void open(void);
private:
    // GUI
    void init(void);
    void draw(void);

    bool active_login(void);
    void draw_active_login(void);
    
    bool active_name(void);
    void draw_active_name(void);
    
    bool active_second_name(void);
    void draw_active_second_name(void);
    
    bool active_password(void);
    void draw_active_password(void);
    
    bool active_register(void);
    void draw_active_register(void);
    
    bool active_exit(void);
    void draw_active_exit(void);

    // db work
    bool check_login(void);
    void add_user(void);
    
    // reset
    void reset(void);
    void reset_login(void);
    void reset_name(void);
    void reset_second_name(void);
    void reset_password(void);
private:
    enum Locale {
        Login,
        Name,
        SecondName,
        Password,
        Register,
        Exit
    };

    WINDOW* m_Window = nullptr;
    Locale locale = Locale::Login;
    db_user m_db_user;

    bool isExit = false;

    // texts
    std::string text_hello        = "Регистрация нового ученика";
    std::string text_login        = "Логин:  ";
    std::string text_name         = "Имя:  ";
    std::string text_second_name  = "Фамилия:  ";
    std::string text_password     = "Пароль:  ";

    const std::string text_register     = " Зарегестрировать ";
    const std::string text_exit         = " Выход ";

    // inputs
    std::string show_login = "";
    std::string real_login = "";

    std::string show_name = "";
    std::string real_name = "";

    std::string show_second_name = "";
    std::string real_second_name = "";

    std::string show_password = "";
    std::string real_password = "";

    // errors
    const std::string error_empty_login       = "Введите логин";
    const std::string error_login             = "Такой логин уже занят";
    const std::string error_empty_name        = "Введите имя";
    const std::string error_empty_second_name = "Введите фамилию";
    const std::string error_empty_password    = "Введите пароль";

    // sucsess
    const std::string sucsess_register = "Ученик зарегестрирован";
};

#endif
