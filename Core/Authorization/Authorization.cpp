#include "Authorization.hpp"

User Authorization::authorization(void) {
    User user;
    
    if (check_save(user))
        return user;
    
    init();
    
    while ((locale != Locale::Enter && locale != Locale::Exit) || (!is_auth && !is_exit)) {
        switch (locale) {
            case Locale::Login:
                if ( active_login() )
                    continue;
                break;
            case Locale::Password:
                if ( active_password() )
                    continue;
                break;
            case Locale::Save:
                if ( active_save() )
                    continue;
                break;
            case Locale::Enter:
                if ( active_enter() )
                    continue;
                break;
            case Locale::Exit:
                if ( active_exit() )
                    continue;
                break;
        }
    }
    
    // Exit
    if (is_auth) {
        user.login = real_login.c_str();
        user.name = Security::Cipher::get_un_chipher(m_db_user.get_name(real_login)).c_str();
        user.second_name = Security::Cipher::get_un_chipher(m_db_user.get_second_name(real_login)).c_str();
        if (m_db_user.get_status(real_login)) {
            user.status = Status::Teacher;
        } else {
            user.status = Status::Student;
        }
        // Reset save file
        if (isSave) {
            std::ofstream ofsave("Source/authorization");
            ofsave.write(Security::Cipher::get_chipher(real_login).c_str(), 255);
            ofsave.write(Security::Cipher::get_chipher(m_db_user.get_password_hash(real_login)).c_str(), 255);
            ofsave.close();
        }
    } else if (is_exit) {
        user.login          = "";
        user.name     = "";
        user.second_name    = "";
        user.status = Status::None;
    }

    delwin(m_Window);
    
    return user;
}

void Authorization::init(void) {
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

void Authorization::reset(void) {
    m_Window = nullptr;
    locale = Locale::Login;
    
    is_auth = false;
    isSave = false;
    is_exit = false;
    
    text_login    = "Логин:  ";
    text_password = "Пароль:  ";
    text_save     = " [ ] Оставаться авторизированным ";
    
    show_login    = "";
    real_login    = "";
    show_password = "";
    real_password = "";
}

void Authorization::reset_show_login(void) {
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

void Authorization::reset_show_password(void) {
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
