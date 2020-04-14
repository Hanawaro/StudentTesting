#include "Edit.hpp"

void Edit::open(void) {
    init();
    
    while ((locale != Locale::Exit) || (!is_exit)) {
        switch (locale) {
            case Locale::Login:
                if ( active_login() && users.size() )
                    continue;
                break;
            case Locale::ChangeBar:
                if ( active_change() && users.size() )
                    continue;
                break;
            case Locale::EditMenu:
                if ( active_edit() && users.size() )
                    continue;
                break;
            case Locale::RemoveMenu:
                if ( active_remove() && users.size() )
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

void Edit::init(void) {
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

void Edit::reset(void) {
    users.clear();
    
    user_index = 0;
    
    deep = false;
    is_exit = false;
    
    load_users();
    
    if (users.size()) {
        real_login = users[user_index].login;
        reset_login();
        real_name = users[user_index].name;
        reset_change();
    }
    m_Window = nullptr;
    locale = Locale::ChangeBar;
    

    std::string show_login  = "";
    std::string real_login  = "";
    
    std::string show_name   = "";
    std::string real_name   = "";
    
    std::string show_second_name = "";
    std::string real_second_name = "";
}

void Edit::reset_login(void) {
    if (real_login.size() > MAXIMAL_SYMBOLS) {
        show_login = "";
        if (deep) {
            for (size_t i = real_login.size() - MAXIMAL_SYMBOLS; i < real_second_name.size(); i++)
                show_login += real_second_name[i];
            show_login[0] = '.';
        } else {
            for (size_t i = 0; i < MAXIMAL_SYMBOLS; i++)
                show_login += real_login[i];
            show_login[show_login.size() - 1] = '.';
        }
    } else {
        show_login = real_login;
    }
}

void Edit::reset_change(void) {
    if (real_name.size() > MAXIMAL_SYMBOLS) {
        show_name = "";
        for (size_t i = 0; i < MAXIMAL_SYMBOLS; i++)
            show_name += real_name[i];
        show_name[show_name.size() - 1] = '.';
    } else {
        show_name = real_name;
    }
    
    real_second_name = users[user_index].second_name;
    if (real_second_name.size() > MAXIMAL_SYMBOLS) {
        show_second_name = "";
        for (size_t i = 0; i < MAXIMAL_SYMBOLS; i++)
            show_second_name += real_second_name[i];
        show_second_name[show_second_name.size() - 1] = '.';
    } else {
        show_second_name = real_second_name;
    }
}

void Edit::clear_data(void) {
    real_login = real_name = real_second_name = "";
    show_name = show_second_name = "_____";
    show_login = "";
}
