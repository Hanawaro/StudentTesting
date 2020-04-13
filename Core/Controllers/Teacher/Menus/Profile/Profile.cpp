#include "Profile.hpp"

void Profile::open(User *user) {
    m_User = user;
    
    init();
    
    while ((locale != Locale::Exit) || (!isExit)) {
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
            case Locale::Exit:
                if ( active_exit() )
                    continue;
                break;
        }
    }

    delwin(m_Window);
}

void Profile::init(void) {
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

void Profile::reset(void) {
    m_Window = nullptr;
    locale = Locale::Exit;
    
    deep = false;
    deepPassword = false;
    isExit = false;
    
    text_hello       = "Ваш аккаунт";
    text_status      = "Учитель";
    text_login       = " Логин:  ";
    text_name        = " Имя:  ";
    text_second_name = " Фамилия:  ";
    text_password    = " Пароль:  ";
    text_exit        = " Назад ";
    
    text_old_password = "Старый пароль:  ";
    text_new_password = "Новый пароль:  ";
    
    real_login = new_real_login = m_User->login;
    real_name = new_real_name = m_User->first_name;
    real_second_name = new_real_second_name = m_User->second_name;
  
    reset_login();
    reset_name();
    reset_second_name();
    clear_password();
}

void Profile::reset_login(void) {
    real_login = new_real_login;
    if (real_login.size() > MAXIMAL_SYMBOLS) {
        show_login = show_new_login = "";
        for (size_t i = 0; i < MAXIMAL_SYMBOLS; i++)
            show_login += real_login[i];
        show_login[show_login.size() - 1] = '.';
        for (size_t i = real_login.size() - MAXIMAL_SYMBOLS; i < real_login.size(); i++) {
            show_new_login += new_real_login[i];
        }
        if (deep)
            text_login[text_login.size() - 1] = '.';
        else
            text_login[text_login.size() - 1] = ' ';
    } else {
        show_login = show_new_login = real_login;
        text_login[text_login.size() - 1] = ' ';
    }
}

void Profile::reset_name(void) {
    real_name = new_real_name;
    if (real_name.size() > MAXIMAL_SYMBOLS) {
        show_name = show_new_name = "";
        for (size_t i = 0; i < MAXIMAL_SYMBOLS; i++) {
            show_name += real_name[i];
        }
        show_name[show_name.size() - 1] = '.';
        for (size_t i = new_real_name.size() - MAXIMAL_SYMBOLS; i < new_real_name.size(); i++) {
            show_new_name += new_real_name[i];
        }
        if (deep)
            text_name[text_name.size() - 1] = '.';
        else
            text_name[text_name.size() - 1] = ' ';
    } else {
        show_name = show_new_name = real_name;
        text_name[text_name.size() - 1] = ' ';
    }
}

void Profile::reset_second_name(void) {
    real_second_name = new_real_second_name;
    if (real_second_name.size() > MAXIMAL_SYMBOLS) {
        show_second_name = show_new_second_name = "";
        for (size_t i = 0; i < MAXIMAL_SYMBOLS; i++) {
            show_second_name += real_second_name[i];
        }
        show_second_name[show_second_name.size() - 1] = '.';
        for (size_t i = new_real_second_name.size() - MAXIMAL_SYMBOLS; i < new_real_second_name.size(); i++) {
            show_new_second_name += new_real_second_name[i];
        }
        if (deep)
            text_second_name[text_second_name.size() - 1] = '.';
        else
            text_second_name[text_second_name.size() - 1] = ' ';
    } else {
        show_second_name = show_new_second_name = real_second_name;
        text_second_name[text_second_name.size() - 1] = ' ';
    }
}

void Profile::clear_password(void) {
    real_old_pass = real_new_pass = show_old_pass = show_new_pass = "";
}

void Profile::reset_old_password(void) {
    if (real_old_pass.size() > MAXIMAL_SYMBOLS) {
        show_old_pass = "";
        for (size_t i = real_old_pass.size() - MAXIMAL_SYMBOLS; i < real_old_pass.size(); i++)
            show_old_pass += '*';
        text_old_password[text_old_password.size() - 1] = '.';
    } else {
        show_old_pass = "";
        for (size_t i = 0; i < real_old_pass.size(); i++)
            show_old_pass += '*';
        text_old_password[text_old_password.size() - 1] = ' ';
    }
}

void Profile::reset_new_password(void) {
    if (real_new_pass.size() > MAXIMAL_SYMBOLS) {
        show_new_pass = "";
        for (size_t i = real_new_pass.size() - MAXIMAL_SYMBOLS; i < real_new_pass.size(); i++)
            show_new_pass += '*';
        text_new_password[text_new_password.size() - 1] = '.';
    } else {
        show_new_pass = "";
        for (size_t i = 0; i < real_new_pass.size(); i++)
            show_new_pass += '*';
        text_new_password[text_new_password.size() - 1] = ' ';
    }
}

void Profile::clear_error(void) {
    for (int i = 0; i < COLS; i++)
        mvwaddch(m_Window, LINES/4 + 11, i, ' ');
}
