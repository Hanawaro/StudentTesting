#ifndef Profile_hpp
#define Profile_hpp

#include <iomanager.hpp>
#include <ncurses.h>
#include <cmath>

#include "../../../../DB/User.hpp"
#include "../../../../DB/DB.hpp"

#define MAXIMAL_SYMBOLS   23
#define LEFT 7

class Profile {
public:
    void open(User* user);
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
    
    bool active_exit(void);
    void draw_active_exit(void);
    
    // save
    void set_save_login(void);
    void set_save_password(void);
    
    // db work
    bool check_login(void);
    bool check_password(void);
    
    // reset
    void reset(void);
    void reset_login(void);
    void reset_name(void);
    void reset_second_name(void);
    void clear_password(void);
    void reset_old_password(void);
    void reset_new_password(void);
    
    void clear_error(void);
private:
    enum Locale {
        Login,
        Name,
        SecondName,
        Password,
        Exit
    };
    
    WINDOW* m_Window = nullptr;
    Locale locale = Locale::Exit;
    User* m_User;
    db_user m_db_user;
    
    bool deep = false;
    bool deepPassword = false;
    bool is_exit = false;
    
    // text
    std::string text_hello       = "Ваш аккаунт";
    std::string text_status      = "Учитель";
    std::string text_login       = " Логин:  ";
    std::string text_name        = " Имя:  ";
    std::string text_second_name = " Фамилия:  ";
    std::string text_password    = " Пароль:  ";
    std::string text_exit        = " Назад ";
    
    // deep password
    std::string text_old_password = "Старый пароль:  ";
    std::string text_new_password = "Новый пароль:  ";
    
    // errors
    const std::string error_empty_login         = "Введите логин";
    const std::string error_login               = "Такой логин уже занят";
    const std::string error_empty_name          = "Введите имя";
    const std::string error_empty_second_name   = "Введите фамилию";
    const std::string error_empty_old_password  = "Введите старый пароль";
    const std::string error_empty_new_password  = "Введите новый пароль";
    const std::string error_passwords           = "Пароли не совпадают";
    
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
    const std::string pseudo_password   = "***********";
    
    std::string show_old_pass;
    std::string real_old_pass;
    
    std::string show_new_pass;
    std::string real_new_pass;
};

#endif
