#ifndef StudentsEditor_hpp
#define StudentsEditor_hpp

#include <iomanager.hpp>
#include <ncurses.h>

#include "../../../../DB/User.hpp"

#include "Models/Add/Add.hpp"
#include "Models/Edit/Edit.hpp"
#include "Models/Show/Show.hpp"

#define AMOUNT_OF_SYMBOLS   23

class StudentsEditor {
public:
    void open(void);
private:
    // GUI
    void init(void);
    void draw(void);
    
    bool active_add(void);
    void draw_active_add(void);
    
    bool active_edit(void);
    void draw_active_edit(void);
    
    bool active_show(void);
    void draw_active_show(void);
    
    bool active_exit(void);
    void draw_active_exit(void);
    
    // reset
    void reset(void);
private:
    enum Locale {
        AddMenu,
        EditMenu,
        ShowMenu,
        Exit
    };
    
    WINDOW* m_Window = nullptr;
    Locale locale = Locale::AddMenu;
    
    Add add;
    Edit edit;
    Show show;
    
    bool is_exit = false;
    
    const std::string text_hello    = "Меню редактирования учеников";
    const std::string text_add      = " Добавить ученика ";
    const std::string text_edit     = " Редактировать ученика ";
    const std::string text_show     = " Список учеников ";
    const std::string text_exit     = " Назад ";
};
#endif
