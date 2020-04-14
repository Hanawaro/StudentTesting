#ifndef Authorization_hpp
#define Authorization_hpp

#include <iomanager.hpp>
#include <fstream>
#include <ncurses.h>

#include "../DB/User.hpp"
#include "../DB/DB.hpp"

#define MAXIMAL_SYMBOLS 23

class Authorization {
public:
    User authorization(void);
private:
    // GUI
    void init(void);
    void draw(void);
    
    bool active_login(void);
    void draw_active_login(void);
    
    bool active_password(void);
    void draw_active_password(void);
    
    bool active_save(void);
    void draw_active_save(void);
    
    bool active_enter(void);
    void draw_active_enter(void);
    
    bool active_exit(void);
    void draw_active_exit(void);
    
    // db work
    bool search_user(void);
    bool find_login(void);
    bool compare_password_hash(void);
    
    // check save account
    bool check_save(User& user);
    
    // reset
    void reset(void);
    void reset_show_login(void);
    void reset_show_password(void);
private:
    enum Locale {
        Login,
        Password,
        Save,
        Enter,
        Exit
    };
    
    WINDOW* m_Window = nullptr;
    Locale locale = Locale::Login;
    
    bool is_auth = false;
    bool isSave = false;
    bool is_exit = false;
    
    // text
    std::string text_hello    = "АВТОРИЗАЦИЯ";
    std::string text_login    = "Логин:  ";
    std::string text_password = "Пароль:  ";
    std::string text_enter    = " Вход ";
    std::string text_exit     = " Выход ";
    std::string text_save     = " [ ] Оставаться авторизированным ";
    
    // input
    std::string show_login       = "";
    std::string real_login       = "";
    std::string show_password    = "";
    std::string real_password    = "";
    
    // errors
    const std::string empty_login       = "Введите логин";
    const std::string empty_password    = "Введите пароль ";
    const std::string not_found         = "Неправильный логин или пароль";
    
    // DB
    db_user m_db_user;
};
#endif
