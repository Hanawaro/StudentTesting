#ifndef Edit_hpp
#define Edit_hpp

#include <iomanager.hpp>
#include <ncurses.h>
#include <vector>

#include "../../../../../../DB/User.hpp"
#include "../../../../../../DB/DB.hpp"

#include "Models/EditMenu/EditMenu.hpp"

#define MAXIMAL_SYMBOLS   23

class Edit {
public:
    void open(void);
private:
    // GUI
    void init(void);
    void draw(void);
    
    bool active_login(void);
    void draw_active_login(void);
    
    bool active_change(void);
    void draw_active_change(void);
    
    bool active_edit(void);
    void draw_active_edit(void);
    
    bool active_remove(void);
    void draw_active_remove(void);
    
    bool active_exit(void);
    void draw_active_exit(void);
    
    // db work
    void load_users(void);
    
    // reset
    void reset(void);
    void reset_login(void);
    void reset_change(void);
    
    void clear_data(void);
private:
    enum Locale {
        Login,
        ChangeBar,
        EditMenu,
        RemoveMenu,
        Exit
    };
    
    WINDOW* m_Window = nullptr;
    Locale locale = Locale::ChangeBar;
    db_user m_db_user;
    
    class EditMenu editMenu;
    
    bool deep = false;
    bool isExit = false;
    
    int user_index = 0;
    
    // text
    const std::string text_hello          = "Редактирование учеников";
    const std::string text_left           = " <   ";
    const std::string text_right          = "   > ";
    const std::string text_edit           = " Изменить ";
    const std::string text_remove         = " Удалить ";
    const std::string text_exit           = " Назад ";
    
    // input
    std::string show_login  = "";
    std::string real_login  = "";
    
    std::string show_name   = "";
    std::string real_name   = "";
    
    std::string show_second_name = "";
    std::string real_second_name = "";
    
    //errors
    const std::string error_empty_login = "Введите логин ученика";
    const std::string error_login   = "Такой ученик не найден";
    
    // data base
    std::vector<User> users;
};

#endif
