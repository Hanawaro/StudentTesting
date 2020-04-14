#include "Testing.hpp"

void Testing::start(const User& user) {
    m_User = user;
    init();
    
    while ((locale != Locale::Exit) || (!is_exit)) {
        switch (locale) {
            case Locale::First:
                if ( active_first() && !empty)
                    continue;
                break;
            case Locale::Second:
                if ( active_second() && !empty)
                    continue;
                break;
            case Locale::Third:
                if ( active_third() && !empty)
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

void Testing::init(void) {
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

void Testing::reset(void) {
    m_Window = nullptr;
    locale = Locale::First;
    
    is_exit = false;
    empty = false;
    once = false;
    isAll = false;

    right_answer = 1;
    right_answers = 0;
    amount_of_tests = 0;
    counter = 0;
    
    show_question.clear();
    show_first_answer.clear();
    show_second_anser.clear();
    show_third_anser.clear();
    
    load_tests();
    if (!empty)
        locale = Locale::Exit;
}

void Testing::reset_test(void) {
    if (once) {
        isAll = true;
        locale = Locale::Exit;
        return;
    }
    
    counter--;
    
    if (randomize.size() > 1 && counter > 0) {
        randomize.erase(randomize.begin() + 0);
        show_question = tests[randomize[0]].question;
        show_first_answer = tests[randomize[0]].answer[0];
        show_second_anser = tests[randomize[0]].answer[1];
        show_third_anser = tests[randomize[0]].answer[2];
    } else if (counter <= 0){
        isAll = true;
        locale = Locale::Exit;
    }
}

void Testing::reset_answers(Test& test) {
    std::vector<int> rand_answers = { 0, 1, 2 };
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(rand_answers.begin(), rand_answers.end(), g);
    std::string old[3];
    bool change_right = false;
    for (size_t j = 0; j < 3; j++)
        old[j] = test.answer[j];
    for (size_t j = 0; j < 3; j++) {
        test.answer[j] = old[rand_answers[j]];
        if (rand_answers[j] + 1 == test.right && !change_right) {
            test.right = (int) j + 1;
            change_right = true;
        }
    }
}
