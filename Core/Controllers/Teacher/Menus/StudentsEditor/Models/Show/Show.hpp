#ifndef Show_hpp
#define Show_hpp

#include <iomanager.hpp>
#include <ncurses.h>
#include <map>

#include "Models/Students/Students.hpp"
#include "Models/First/First.hpp"
#include "Models/Second/Second.hpp"
#include "Models/Third/Third.hpp"
#include "Models/Total/Total.hpp"

#include "../../../../../../DB/User.hpp"
#include "../../../../../../DB/DB.hpp"

class Show {
public:
    void open(void);
private:
    // GUI
    void init(void);
    void draw(void);
    
    bool active_students(void);
    void draw_active_students(void);
    
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
    void load_users(void);
    
    // reset
    void reset(void);
private:
    enum Locale {
        StudentsMenu,
        FirstMenu,
        SecondMenu,
        ThirdMenu,
        TotalMenu,
        Exit
    };
    
    WINDOW* m_Window = nullptr;
    db_user m_db_user;
    Locale locale = Locale::StudentsMenu;
    
    Students students_menu;
    First first_menu;
    Second second_menu;
    Third third_menu;
    Total total_menu;
    
    bool is_exit = false;
    
    const std::string text_hello    = " Список учеников ";
    const std::string text_students = " Ученики ";
    const std::string text_first    = " Первый тест ";
    const std::string text_second   = " Второй тест ";
    const std::string text_third    = " Третий тест ";
    const std::string text_total    = " Зачёт ";
    const std::string text_exit     = " Назад ";
    
    std::vector<info_student> users;
};

#endif
