#include "Add.hpp"

void Add::open(void) {
    init();
    
    while ((locale != Locale::Exit) || (!is_exit)) {
        switch (locale) {
            case Locale::Login:
                if ( active_login() )
                    continue;
                break;
            case Locale::Name:
                if ( active_name() )
                    continue;
                break;
            case Locale::SecondName:
                if ( active_second_name() )
                    continue;
                break;
            case Locale::Password:
                if ( active_password() )
                    continue;
                break;
            case Locale::Register:
                if ( active_register() )
                    continue;
                break;
            case Locale::Exit:
                if ( active_exit() )
                    continue;
                break;
        }
    }
    
    delwin(m_Window);
}

void Add::init(void) {
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

void Add::reset(void) {
    m_Window = nullptr;
    locale = Locale::Login;
    
    is_exit = false;

    text_hello        = "Регистрация нового ученика";
    text_login        = "Логин:  ";
    text_name         = "Имя:  ";
    text_second_name  = "Фамилия:  ";
    text_password     = "Пароль:  ";

    show_login = "";
    real_login = "";

    show_name = "";
    real_name = "";

    show_second_name = "";
    real_second_name = "";

    show_password = "";
    real_password = "";
}

void Add::reset_login(void) {
    if (real_login.size() > MAXIMAL_SYMBOLS ) {
        show_login = "";
        for (size_t i = real_login.size() - MAXIMAL_SYMBOLS; i < real_login.size(); i++)
            show_login += real_login[i];
        text_login[text_login.size() - 1] = '.';
    } else {
        show_login = real_login;
        text_login[text_login.size() - 1] = ' ';
    }
}

void Add::reset_name(void) {
    if (real_name.size() > MAXIMAL_SYMBOLS ) {
        show_name = "";
        for (size_t i = real_name.size() - MAXIMAL_SYMBOLS; i < real_name.size(); i++)
            show_name += real_name[i];
        text_name[text_name.size() - 1] = '.';
    } else {
        show_name = real_name;
        text_name[text_name.size() - 1] = ' ';
    }
}

void Add::reset_second_name(void) {
    if (real_second_name.size() > MAXIMAL_SYMBOLS ) {
        show_second_name = "";
        for (size_t i = real_second_name.size() - MAXIMAL_SYMBOLS; i < real_second_name.size(); i++)
            show_second_name += real_second_name[i];
        text_second_name[text_second_name.size() - 1] = '.';
    } else {
        show_second_name = real_second_name;
        text_second_name[text_second_name.size() - 1] = ' ';
    }
}

void Add::reset_password(void) {
    if (real_password.size() > MAXIMAL_SYMBOLS ) {
        show_password = "";
        for (size_t i = real_password.size() - MAXIMAL_SYMBOLS; i < real_password.size(); i++)
            show_password += '*';
        text_password[text_password.size() - 1] = '.';
    } else {
        show_password = "";
        for (size_t i = 0; i < real_password.size(); i++)
            show_password += '*';
        text_password[text_password.size() - 1] = ' ';
    }
}
