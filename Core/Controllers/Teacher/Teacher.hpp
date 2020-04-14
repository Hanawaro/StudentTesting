#ifndef Teacher_hpp
#define Teacher_hpp

#include <iomanager.hpp>
#include <ncurses.h>

#include "../../DB/User.hpp"

#include "Menus/Profile/Profile.hpp"
#include "Menus/StudentsEditor/StudentsEditor.hpp"
#include "Menus/TestsEditor/TestsEditor.hpp"

class TeacherMenu {
public:
    bool open(User user);
private:
    // GUI
    void init(void);
    void draw(void);
    
    bool active_profile(void);
    void draw_active_profile(void);
    
    bool active_tests_editor(void);
    void draw_active_tests_editor(void);
    
    bool active_students_editor(void);
    void draw_active_students_editor(void);
    
    bool active_unsave_exit(void);
    void draw_active_unsave_exit(void);
    
    bool active_exit(void);
    void draw_active_exit(void);
    
    // reset
    void reset(void);
private:
    enum Locale {
        Profile,
        TestsEditor,
        StudentsEditor,
        UnsaveExit,
        Exit
    };
    
    WINDOW* m_Window = nullptr;
    Locale locale = Locale::Profile;
    User m_User;
    
    class Profile menu_profile;
    class StudentsEditor menu_students;
    class TestsEditor menu_tests_editor;
    
    bool is_auth = true;
    bool is_exit = false;
    
    // text
    const std::string text_hello            = "Добро пожаловать!";
    const std::string text_profile          = " Профиль ";
    const std::string text_tests_editor     = " Тесты ";
    const std::string text_students_editor  = " Студенты ";
    const std::string text_unsave_exit        = " Выйти из системы ";
    const std::string text_exit             = " Выход ";
};

#endif
