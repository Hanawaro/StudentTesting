#include "Training.hpp"

void Training::start(void) {
    init();
    
    while ((locale != Locale::Exit) || (!isExit)) {
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

void Training::init(void) {
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

void Training::reset(void) {
    m_Window = nullptr;
    locale = Locale::First;
    
    isExit = false;
    isError = false;
    empty = false;
    once = false;
    
    show_question.clear();
    show_first_answer.clear();
    show_second_anser.clear();
    show_third_anser.clear();
    
    right_answer = 1;
    load_tests();
    if (!empty)
        reset_test();
    else
        locale = Locale::Exit;
}

void Training::reset_test(void) {
    if (once) {
        reset_answers(tests[0]);
        show_question = tests[0].question;
        show_first_answer = tests[0].answer[0];
        show_second_anser = tests[0].answer[1];
        show_third_anser = tests[0].answer[2];
        return;
    }
    
    if (randomize.size() > 1) {
        randomize.erase(randomize.begin() + 0);
        reset_answers(tests[randomize[0]]);
        show_question = tests[randomize[0]].question;
        show_first_answer = tests[randomize[0]].answer[0];
        show_second_anser = tests[randomize[0]].answer[1];
        show_third_anser = tests[randomize[0]].answer[2];
    } else {
        randomize.clear();
        for (size_t i = 0; i < tests.size(); i++)
            randomize.push_back(i);
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(randomize.begin(), randomize.end(), g);
        reset_test();
    }
}

void Training::reset_answers(Test& test) {
    std::vector<int> rand_answers = { 0, 1, 2 };
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(rand_answers.begin(), rand_answers.end(), g);
    std::string old[3];
    bool change_right = false;
    for (size_t j = 0; j < 3; j++) {
        test.answer[j].erase(test.answer[j].begin());
        old[j] = test.answer[j];
    }
    for (size_t j = 0; j < 3; j++) {
        test.answer[j] = std::to_string(j + 1) + old[rand_answers[j]];
        if (rand_answers[j] + 1 == test.right && !change_right) {
            test.right = (int) j + 1;
            change_right = true;
        }
    }
}
