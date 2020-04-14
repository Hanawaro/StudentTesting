#include "EditMenu.hpp"

void EditMenu::open(User *user) {
    m_User = user;
    
    init();
    
    while ((account_locale != AccountLocale::Exit && mark_locale != MarkLocale::Exit) || (!is_exit)) {
        switch (change_locale) {
            case ChangeLocale::Account:
                switch (account_locale) {
                    case AccountLocale::Change:
                        if ( active_change() )
                            continue;
                        break;
                    case AccountLocale::Login:
                        if ( active_login() )
                            continue;
                        break;
                    case AccountLocale::Name:
                        if ( active_name() )
                            continue;
                        break;
                    case AccountLocale::SecondName:
                        if ( active_second_name() )
                            continue;
                        break;
                    case AccountLocale::Password:
                        if ( active_password() )
                            continue;
                        break;
                    case AccountLocale::Exit:
                        if ( active_exit() )
                            continue;
                        break;
                }
                break;
            case ChangeLocale::Marks:
                switch (mark_locale) {
                    case MarkLocale::Change:
                        if ( active_change() )
                            continue;
                        break;
                    case MarkLocale::First:
                        if ( active_first() )
                            continue;
                        break;
                    case MarkLocale::Second:
                        if ( active_second() )
                            continue;
                        break;
                    case MarkLocale::Third:
                        if ( active_third() )
                            continue;
                        break;
                    case MarkLocale::Total:
                        if ( active_total() )
                            continue;
                        break;
                    case MarkLocale::Exit:
                        if ( active_exit() )
                            continue;
                        break;
                }
                break;
        }
    }
    
    delwin(m_Window);
}

void EditMenu::init(void) {
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

void EditMenu::reset(void) {
    m_Window = nullptr;
    
    account_locale = AccountLocale::Login;
    mark_locale = MarkLocale::First;
    change_locale = ChangeLocale::Account;
    
    deep = false;
    is_exit = false;
    
    text_login          = " Логин:  ";
    text_name           = " Имя:  ";
    text_second_name    = " Фамилия:  ";
    text_password       = " Пароль:  ";
    
    new_real_login = m_User->login;
    new_real_name = m_User->name;
    new_real_second_name = m_User->second_name;
    
    reset_login();
    reset_name();
    reset_second_name();
    clear_password();
    
    m_Marks = getMarks();
    
    mark_first  = m_Marks.first;
    mark_second = m_Marks.second;
    mark_third  = m_Marks.third;
    mark_total  = m_Marks.total;
    
    reset_first();
    reset_second();
    reset_third();
    reset_total();
}

void EditMenu::reset_login(void) {
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
void EditMenu::reset_name(void) {
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

void EditMenu::reset_second_name(void) {
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

void EditMenu::reset_password(void) {
    if (real_password.size() > MAXIMAL_SYMBOLS) {
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

void EditMenu::clear_password(void) {
    real_password = show_password = "";
}

void EditMenu::reset_first(void) {
    switch (mark_first) {
        case Mark::Empty:
            show_first = text_empty;
            break;
        case Mark::Two:
            show_first = text_two;
            break;
        case Mark::Three:
            show_first = text_three;
            break;
        case Mark::Four:
            show_first = text_four;
            break;
        case Mark::Five:
            show_first = text_five;
            break;
    }
}

void EditMenu::reset_second(void) {
    switch (mark_second) {
        case Mark::Empty:
            show_second = text_empty;
            break;
        case Mark::Two:
            show_second = text_two;
            break;
        case Mark::Three:
            show_second = text_three;
            break;
        case Mark::Four:
            show_second = text_four;
            break;
        case Mark::Five:
            show_second = text_five;
            break;
    }
}

void EditMenu::reset_third(void) {
    switch (mark_third) {
        case Mark::Empty:
            show_third = text_empty;
            break;
        case Mark::Two:
            show_third = text_two;
            break;
        case Mark::Three:
            show_third = text_three;
            break;
        case Mark::Four:
            show_third = text_four;
            break;
        case Mark::Five:
            show_third = text_five;
            break;
    }
}

void EditMenu::reset_total(void) {
    switch (mark_total) {
        case Mark::Empty:
            show_total = text_empty;
            break;
        case Mark::Two:
            show_total = text_two;
            break;
        case Mark::Three:
            show_total = text_three;
            break;
        case Mark::Four:
            show_total = text_four;
            break;
        case Mark::Five:
            show_total = text_five;
            break;
    }
}
