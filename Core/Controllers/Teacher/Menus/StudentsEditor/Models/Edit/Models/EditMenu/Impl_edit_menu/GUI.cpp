#include "../EditMenu.hpp"

void EditMenu::draw(void) {
    wclear(m_Window);
    
    switch (change_locale) {
        case ChangeLocale::Account:
            // hello
            mvwaddstr(m_Window, LINES/4 - 2, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
            
            // change
            if (!deep) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
            mvwaddstr(m_Window, LINES/4 + 1, COLS/2 - (int) iomanager::strlen(text_change_account) - 3, text_change_account.c_str());
            if (!deep) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
            mvwaddstr(m_Window, LINES/4 + 1, COLS/2 + 3, text_change_mark.c_str());
            
            // login
            mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - LEFT - (int) iomanager::strlen(text_login), text_login.c_str());
            wattron(m_Window, A_UNDERLINE);
            for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_login.size())/2.); i++)
                waddch(m_Window, ' ');
            waddstr(m_Window, show_login.c_str());
            for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_login.size())/2.); i++)
                waddch(m_Window, ' ');
            wattroff(m_Window, A_UNDERLINE);
            
            // name
            mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - LEFT - (int) iomanager::strlen(text_name), text_name.c_str());
            wattron(m_Window, A_UNDERLINE);
            for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_name.size())/2.); i++)
                waddch(m_Window, ' ');
            waddstr(m_Window, show_name.c_str());
            for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_name.size())/2.); i++)
                waddch(m_Window, ' ');
            wattroff(m_Window, A_UNDERLINE);

            // second name
            mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - LEFT - (int) iomanager::strlen(text_second_name), text_second_name.c_str());
            wattron(m_Window, A_UNDERLINE);
            for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_second_name.size())/2.); i++)
                waddch(m_Window, ' ');
            waddstr(m_Window, show_second_name.c_str());
            for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_second_name.size())/2.); i++)
                waddch(m_Window, ' ');
            wattroff(m_Window, A_UNDERLINE);
            
            // password
            mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - LEFT - (int) iomanager::strlen(text_password), text_password.c_str());
            wattron(m_Window, A_UNDERLINE);
            for (int i = 0; i < floor((MAXIMAL_SYMBOLS - pseudo_password.size())/2.); i++)
                waddch(m_Window, ' ');
            waddstr(m_Window, pseudo_password.c_str());
            for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - pseudo_password.size())/2.); i++)
                waddch(m_Window, ' ');
            wattroff(m_Window, A_UNDERLINE);
            
            // exit button
            mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
            
            break;
        case ChangeLocale::Marks:
            // hello
            mvwaddstr(m_Window, LINES/4 - 2, (COLS - (int) iomanager::strlen(text_hello))/2, text_hello.c_str());
            
            // change
            mvwaddstr(m_Window, LINES/4 + 1, COLS/2 - (int) iomanager::strlen(text_change_account) - 3, text_change_account.c_str());
            if (!deep) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
            mvwaddstr(m_Window, LINES/4 + 1, COLS/2 + 3, text_change_mark.c_str());
            if (!deep) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
            
            mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - (int) iomanager::strlen(text_first), text_first.c_str());
            if (mark_first == Mark::Empty)
                for (int i = 0; i < 2; i++) waddch(m_Window, ' ');
            else
                for (int i = 0; i < 7; i++) waddch(m_Window, ' ');
            waddstr(m_Window, show_first.c_str());
            
            mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - (int) iomanager::strlen(text_second), text_second.c_str());
            if (mark_second == Mark::Empty)
                for (int i = 0; i < 2; i++) waddch(m_Window, ' ');
            else
                for (int i = 0; i < 7; i++) waddch(m_Window, ' ');
            waddstr(m_Window, show_second.c_str());
            
            mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - (int) iomanager::strlen(text_third), text_third.c_str());
            if (mark_third == Mark::Empty)
                for (int i = 0; i < 2; i++) waddch(m_Window, ' ');
            else
                for (int i = 0; i < 7; i++) waddch(m_Window, ' ');
            waddstr(m_Window, show_third.c_str());
            
            mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - (int) iomanager::strlen(text_total), text_total.c_str());
            if (mark_total == Mark::Empty)
                for (int i = 0; i < 2; i++) waddch(m_Window, ' ');
            else
                for (int i = 0; i < 7; i++) waddch(m_Window, ' ');
            waddstr(m_Window, show_total.c_str());
            
            // exit button
            mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
            
            break;
    }
    
    refresh();
    wrefresh(m_Window);
}

void EditMenu::draw_active_change(void) {
    switch (change_locale) {
        case ChangeLocale::Account:
            wattron(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4 + 1, COLS/2 - (int) iomanager::strlen(text_change_account) - 3, text_change_account.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4 + 1, COLS/2 + 3, text_change_mark.c_str());
            break;
        case ChangeLocale::Marks:
            mvwaddstr(m_Window, LINES/4 + 1, COLS/2 - (int) iomanager::strlen(text_change_account) - 3, text_change_account.c_str());
            wattron(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            mvwaddstr(m_Window, LINES/4 + 1, COLS/2 + 3, text_change_mark.c_str());
            wattroff(m_Window, COLOR_PAIR(iomanager::WARNING) | A_UNDERLINE);
            break;
    }
}

void EditMenu::draw_active_login(void) {
    for (int i = 0; i < COLS; i++)
        mvwaddch(m_Window, LINES/4 + 3, i, ' ');
    
    if (deep) {
        curs_set(1);
        
        wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
        mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - LEFT - (int) iomanager::strlen(text_login), text_login.c_str());
        waddstr(m_Window, show_new_login.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
    } else {
        curs_set(0);
        
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - LEFT - (int) iomanager::strlen(text_login), text_login.c_str());
        for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_login.size())/2.); i++)
            waddch(m_Window, ' ');
        waddstr(m_Window, show_login.c_str());
        for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_login.size())/2.); i++)
            waddch(m_Window, ' ');
        waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void EditMenu::draw_active_name(void) {
    for (int i = 0; i < COLS; i++)
        mvwaddch(m_Window, LINES/4 + 5, i, ' ');
    
    if (deep) {
        curs_set(1);
        
        wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
        mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - LEFT - (int) iomanager::strlen(text_name), text_name.c_str());
        waddstr(m_Window, show_new_name.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
    } else {
        curs_set(0);
        
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - LEFT - (int) iomanager::strlen(text_name), text_name.c_str());
        for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_name.size())/2.); i++)
            waddch(m_Window, ' ');
        waddstr(m_Window, show_name.c_str());
        for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_name.size())/2.); i++)
            waddch(m_Window, ' ');
        waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void EditMenu::draw_active_second_name(void) {
    for (int i = 0; i < COLS; i++)
        mvwaddch(m_Window, LINES/4 + 7, i, ' ');
    
    if (deep) {
        curs_set(1);
        
        wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
        mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - LEFT - (int) iomanager::strlen(text_second_name), text_second_name.c_str());
        waddstr(m_Window, show_new_second_name.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
    } else {
        curs_set(0);
        
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - LEFT - (int) iomanager::strlen(text_second_name), text_second_name.c_str());
        for (int i = 0; i < floor((MAXIMAL_SYMBOLS - show_second_name.size())/2.); i++)
            waddch(m_Window, ' ');
        waddstr(m_Window, show_second_name.c_str());
        for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - show_second_name.size())/2.); i++)
            waddch(m_Window, ' ');
        waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }

}

void EditMenu::draw_active_password(void) {
    for (int i = 0; i < COLS; i++)
        mvwaddch(m_Window, LINES/4 + 9, i, ' ');
    
    if (deep) {
        curs_set(1);
        
        wattron(m_Window, COLOR_PAIR(iomanager::TEXT));
        mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - LEFT - (int) iomanager::strlen(text_password), text_password.c_str());
        waddstr(m_Window, show_password.c_str());
        wattroff(m_Window, COLOR_PAIR(iomanager::TEXT));
    } else {
        curs_set(0);
        
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - LEFT - (int) iomanager::strlen(text_password), text_password.c_str());
        for (int i = 0; i < floor((MAXIMAL_SYMBOLS - pseudo_password.size())/2.); i++)
            waddch(m_Window, ' ');
        waddstr(m_Window, pseudo_password.c_str());
        for (int i = 0; i < ceil((MAXIMAL_SYMBOLS - pseudo_password.size())/2.); i++)
            waddch(m_Window, ' ');
        waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void EditMenu::draw_active_first(void) {
    curs_set(0);
    
    if (deep) {
        mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - (int) iomanager::strlen(text_first), text_first.c_str());
        
        if (m_Marks.first == Mark::Empty) wattron(m_Window, A_UNDERLINE);
        if (mark_first == Mark::Empty) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_empty.c_str());
        if (mark_first == Mark::Empty) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.first == Mark::Empty) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.first == Mark::Two) wattron(m_Window, A_UNDERLINE);
        if (mark_first == Mark::Two) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_two.c_str());
        if (mark_first == Mark::Two) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.first == Mark::Two) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.first == Mark::Three) wattron(m_Window, A_UNDERLINE);
        if (mark_first == Mark::Three) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_three.c_str());
        if (mark_first == Mark::Three) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.first == Mark::Three) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.first == Mark::Four) wattron(m_Window, A_UNDERLINE);
        if (mark_first == Mark::Four) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_four.c_str());
        if (mark_first == Mark::Four) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.first == Mark::Four) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.first == Mark::Five) wattron(m_Window, A_UNDERLINE);
        if (mark_first == Mark::Five) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_five.c_str());
        if (mark_first == Mark::Five) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.first == Mark::Five) wattroff(m_Window, A_UNDERLINE);
        
    } else {
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 3, COLS/2 - (int) iomanager::strlen(text_first), text_first.c_str());
        if (mark_first == Mark::Empty)
            for (int i = 0; i < 2; i++) waddch(m_Window, ' ');
        else
            for (int i = 0; i < 7; i++) waddch(m_Window, ' ');
        waddstr(m_Window, show_first.c_str());
        if (mark_first == Mark::Empty)
            for (int i = 0; i < 1; i++) waddch(m_Window, ' ');
        else
            for (int i = 0; i < 6; i++) waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void EditMenu::draw_active_second(void) {
    curs_set(0);
    
    if (deep) {
        mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - (int) iomanager::strlen(text_second), text_second.c_str());
        
        if (m_Marks.second == Mark::Empty) wattron(m_Window, A_UNDERLINE);
        if (mark_second == Mark::Empty) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_empty.c_str());
        if (mark_second == Mark::Empty) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.second == Mark::Empty) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.second == Mark::Two) wattron(m_Window, A_UNDERLINE);
        if (mark_second == Mark::Two) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_two.c_str());
        if (mark_second == Mark::Two) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.second == Mark::Two) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.second == Mark::Three) wattron(m_Window, A_UNDERLINE);
        if (mark_second == Mark::Three) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_three.c_str());
        if (mark_second == Mark::Three) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.second == Mark::Three) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.second == Mark::Four) wattron(m_Window, A_UNDERLINE);
        if (mark_second == Mark::Four) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_four.c_str());
        if (mark_second == Mark::Four) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.second == Mark::Four) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.second == Mark::Five) wattron(m_Window, A_UNDERLINE);
        if (mark_second == Mark::Five) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_five.c_str());
        if (mark_second == Mark::Five) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.second == Mark::Five) wattroff(m_Window, A_UNDERLINE);
        
    } else {
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 5, COLS/2 - (int) iomanager::strlen(text_second), text_second.c_str());
        if (mark_second == Mark::Empty)
            for (int i = 0; i < 2; i++) waddch(m_Window, ' ');
        else
            for (int i = 0; i < 7; i++) waddch(m_Window, ' ');
        waddstr(m_Window, show_second.c_str());
        if (mark_second == Mark::Empty)
            for (int i = 0; i < 1; i++) waddch(m_Window, ' ');
        else
            for (int i = 0; i < 6; i++) waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void EditMenu::draw_active_third(void) {
    curs_set(0);
    
    if (deep) {
        mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - (int) iomanager::strlen(text_third), text_third.c_str());
        
        if (m_Marks.third == Mark::Empty) wattron(m_Window, A_UNDERLINE);
        if (mark_third == Mark::Empty) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_empty.c_str());
        if (mark_third == Mark::Empty) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.third == Mark::Empty) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.third == Mark::Two) wattron(m_Window, A_UNDERLINE);
        if (mark_third == Mark::Two) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_two.c_str());
        if (mark_third == Mark::Two) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.third == Mark::Two) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.third == Mark::Three) wattron(m_Window, A_UNDERLINE);
        if (mark_third == Mark::Three) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_three.c_str());
        if (mark_third == Mark::Three) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.third == Mark::Three) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.third == Mark::Four) wattron(m_Window, A_UNDERLINE);
        if (mark_third == Mark::Four) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_four.c_str());
        if (mark_third == Mark::Four) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.third == Mark::Four) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.third == Mark::Five) wattron(m_Window, A_UNDERLINE);
        if (mark_third == Mark::Five) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_five.c_str());
        if (mark_third == Mark::Five) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.third == Mark::Five) wattroff(m_Window, A_UNDERLINE);
        
    } else {
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 7, COLS/2 - (int) iomanager::strlen(text_third), text_third.c_str());
        if (mark_third == Mark::Empty)
            for (int i = 0; i < 2; i++) waddch(m_Window, ' ');
        else
            for (int i = 0; i < 7; i++) waddch(m_Window, ' ');
        waddstr(m_Window, show_third.c_str());
        if (mark_third == Mark::Empty)
            for (int i = 0; i < 1; i++) waddch(m_Window, ' ');
        else
            for (int i = 0; i < 6; i++) waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void EditMenu::draw_active_total(void) {
    curs_set(0);
    
    if (deep) {
        mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - (int) iomanager::strlen(text_total), text_total.c_str());
        
        if (m_Marks.total == Mark::Empty) wattron(m_Window, A_UNDERLINE);
        if (mark_total == Mark::Empty) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_empty.c_str());
        if (mark_total == Mark::Empty) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.total == Mark::Empty) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.total == Mark::Two) wattron(m_Window, A_UNDERLINE);
        if (mark_total == Mark::Two) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_two.c_str());
        if (mark_total == Mark::Two) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.total == Mark::Two) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.total == Mark::Three) wattron(m_Window, A_UNDERLINE);
        if (mark_total == Mark::Three) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_three.c_str());
        if (mark_total == Mark::Three) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.total == Mark::Three) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.total == Mark::Four) wattron(m_Window, A_UNDERLINE);
        if (mark_total == Mark::Four) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_four.c_str());
        if (mark_total == Mark::Four) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.total == Mark::Four) wattroff(m_Window, A_UNDERLINE);
        
        for (int i = 0; i < 2; i++)
            waddch(m_Window, ' ');
        
        if (m_Marks.total == Mark::Five) wattron(m_Window, A_UNDERLINE);
        if (mark_total == Mark::Five) wattron(m_Window, COLOR_PAIR(iomanager::WARNING));
        waddstr(m_Window, text_five.c_str());
        if (mark_total == Mark::Five) wattroff(m_Window, COLOR_PAIR(iomanager::WARNING));
        if (m_Marks.total == Mark::Five) wattroff(m_Window, A_UNDERLINE);
        
    } else {
        wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
        mvwaddstr(m_Window, LINES/4 + 9, COLS/2 - (int) iomanager::strlen(text_total), text_total.c_str());
        if (mark_total == Mark::Empty)
            for (int i = 0; i < 2; i++) waddch(m_Window, ' ');
        else
            for (int i = 0; i < 7; i++) waddch(m_Window, ' ');
        waddstr(m_Window, show_total.c_str());
        if (mark_total == Mark::Empty)
            for (int i = 0; i < 1; i++) waddch(m_Window, ' ');
        else
            for (int i = 0; i < 6; i++) waddch(m_Window, ' ');
        wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    }
}

void EditMenu::draw_active_exit(void) {
    curs_set(0);
    
    wattron(m_Window, COLOR_PAIR(iomanager::ACTIVE));
    mvwaddstr(m_Window, LINES/4 + 13, (COLS - (int) iomanager::strlen(text_exit))/2, text_exit.c_str());
    wattroff(m_Window, COLOR_PAIR(iomanager::ACTIVE));
}

void EditMenu::clear_error(void) {
    for (int i = 0; i < COLS; i++)
        mvwaddch(m_Window, LINES/4 + 11, i, ' ');
}
