#include "Student.hpp"

int g_show_locale = 0;

static std::string getMark(Mark mark) {
    switch (mark) {
        case Mark::Empty:
            return "Не решено";
        case Mark::Two:
            return std::to_string(2);
        case Mark::Three:
            return std::to_string(3);
        case Mark::Four:
            return std::to_string(4);
        case Mark::Five:
            return std::to_string(5);
    }
}

bool StudentMenu::open(User user) {
    m_User = user;
    
    init();
    
    while ((locale != Locale::Exit && locale != Locale::UnsaveExit) || (!is_exit)) {
        switch (locale) {
            case Locale::Change:
                if ( active_change() )
                    continue;
                break;
            case Locale::Show:
                if ( active_show() )
                    continue;
                break;
            case Locale::UnsaveExit:
                if ( active_unsave_exit() )
                    continue;
                break;
            case Locale::Exit:
                if ( active_exit() )
                    continue;
                break;
        }
    }
    
    delwin(m_Window);
    
    if (!is_auth) {
        std::ofstream authorization("Source/authorization");
        authorization.close();
        return true;
    }
    
    return false;

}

void StudentMenu::init(void) {
    reset();
    
    // set defaults
    noecho();
    raw();
    curs_set(0);
    
    // make window
    m_Window = newwin(LINES, COLS, 0, 0);
    
    // set window
    wborder(m_Window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    keypad(m_Window, true);
    
    // draw
    color_set(iomanager::TEXT, NULL);

    draw();
}

void StudentMenu::reset(void) {
    m_Window = nullptr;
    locale = Locale::Change;
    show_locale = ShowLocale::First;
    change_locale = ChangeLocale::Training;
    
    is_auth = true;
    is_exit = false;
    
    text_login       = " Логин:  ";
    text_name        = " Имя:  ";
    text_second_name = " Фамилия:  ";
    
    load_student();
    
    reset_login();
    reset_name();
    reset_second_name();
    reset_marks();
}

void StudentMenu::reset_login(void) {
    if (m_User.login.size() > MAXIMAL_SYMBOLS) {
        show_login.clear();
        for (size_t i = 0; i < MAXIMAL_SYMBOLS; i++)
            show_login += m_User.login[i];
        show_login[show_login.size() - 1] = '.';
    } else {
        show_login = m_User.login;
        text_login[text_login.size() - 1] = ' ';
    }
}

void StudentMenu::reset_name(void) {
    if (m_User.name.size() > MAXIMAL_SYMBOLS) {
        show_name.clear();
        for (size_t i = 0; i < MAXIMAL_SYMBOLS; i++)
            show_name += m_User.name[i];
        show_name[show_name.size() - 1] = '.';
    } else {
        show_name = m_User.name;
        text_name[text_name.size() - 1] = ' ';
    }
}

void StudentMenu::reset_second_name(void) {
    if (m_User.second_name.size() > MAXIMAL_SYMBOLS) {
        show_second_name.clear();
        for (size_t i = 0; i < MAXIMAL_SYMBOLS; i++)
            show_second_name += m_User.second_name[i];
        show_second_name[show_second_name.size() - 1] = '.';
    } else {
        show_second_name = m_User.second_name;
        text_second_name[text_second_name.size() - 1] = ' ';
    }
}

void StudentMenu::reset_marks(void) {
    show_first_mark  = getMark(m_Student.first);
    show_second_mark = getMark(m_Student.second);
    show_third_mark  = getMark(m_Student.third);
    show_total_mark  = getMark(m_Student.total);
}
