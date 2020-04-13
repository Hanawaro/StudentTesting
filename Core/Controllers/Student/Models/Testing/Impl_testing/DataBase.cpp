#include "../Testing.hpp"

void Testing::load_tests(void) {
    tests.clear();
    std::vector<Test> tmp;
    switch (g_show_locale) {
        case 1:
            m_db_test_first.load_tests(tmp);
            for (size_t i = 0; i < tmp.size(); i++)
                tests.push_back(tmp[i]);
            break;
        case 2:
            m_db_test_second.load_tests(tmp);
            for (size_t i = 0; i < tmp.size(); i++)
                tests.push_back(tmp[i]);
            break;
        case 3:
            m_db_test_third.load_tests(tmp);
            for (size_t i = 0; i < tmp.size(); i++)
                tests.push_back(tmp[i]);
            break;
        case 4:
            m_db_test_first.load_tests(tmp);
            for (size_t i = 0; i < tmp.size(); i++)
                tests.push_back(tmp[i]);
            m_db_test_second.load_tests(tmp);
            for (size_t i = 0; i < tmp.size(); i++)
                tests.push_back(tmp[i]);
            m_db_test_third.load_tests(tmp);
            for (size_t i = 0; i < tmp.size(); i++)
                tests.push_back(tmp[i]);
            break;
    }
    
    if (!tests.size()) {
        empty = true;
        locale = Locale::Exit;
        return;
    } else if (tests.size() == 1) {
        once = true;
        randomize.push_back(0);
        reset_answers(tests[0]);
        for (size_t j = 0; j < 3; j++)
            tests[0].answer[j] = std::to_string(j + 1) + ") " + tests[0].answer[j];
        show_question = tests[0].question;
        show_first_answer = tests[0].answer[0];
        show_second_anser = tests[0].answer[1];
        show_third_anser = tests[0].answer[2];
        counter = amount_of_tests = 1;
        minus_life();
        return;
    } else {
        if (tests.size() > 10)
            counter = amount_of_tests = 10;
        else
            counter = amount_of_tests = (int) tests.size();
    }
    
    minus_life();
    
    for (size_t i = 0; i < tests.size(); i++) {
        randomize.push_back(i);
        reset_answers(tests[i]);
        for (size_t j = 0; j < 3; j++)
            tests[i].answer[j] = std::to_string(j + 1) + ") " + tests[i].answer[j];
    }
    
    std::random_device rd;
    std::mt19937 g(rd());
    
    std::shuffle(randomize.begin(), randomize.end(), g);
    
    show_question = tests[randomize[0]].question;
    show_first_answer = tests[randomize[0]].answer[0];
    show_second_anser = tests[randomize[0]].answer[1];
    show_third_anser = tests[randomize[0]].answer[2];
}

void Testing::minus_life(void) {
    m_Student = m_db_student.load_student(m_User.login);
    switch (g_show_locale) {
        case 1:
            if (m_Student.amount_of_first > 0)
                m_Student.amount_of_first--;
            m_db_student.setFirst(m_User.login, m_Student.first, m_Student.amount_of_first);
            break;
        case 2:
            if (m_Student.amount_of_second > 0)
                m_Student.amount_of_second--;
            m_db_student.setSecond(m_User.login, m_Student.second, m_Student.amount_of_second);
            break;
        case 3:
            if (m_Student.amount_of_third > 0)
                m_Student.amount_of_third--;
            m_db_student.setThird(m_User.login, m_Student.third, m_Student.amount_of_third);
            break;
        case 4:
            if (m_Student.amount_of_total > 0)
                m_Student.amount_of_total--;
            m_db_student.setTotal(m_User.login, m_Student.total, m_Student.amount_of_total);
            break;
    }
}

void Testing::set_new_result(void) {
    Mark mark = Mark::Empty;
    if (right_answers > amount_of_tests*0.9)
        mark = Mark::Five;
    else if (right_answers > amount_of_tests*0.7)
        mark = Mark::Four;
    else if (right_answers > amount_of_tests*0.5)
        mark = Mark::Three;
    else
        mark = Mark::Two;
    
    switch (g_show_locale) {
        case 1:
            m_db_student.setFirst(m_User.login, mark, m_Student.amount_of_first);
            break;
        case 2:
            m_db_student.setSecond(m_User.login, mark, m_Student.amount_of_second);
            break;
        case 3:
            m_db_student.setThird(m_User.login, mark, m_Student.amount_of_third);
            break;
        case 4:
            m_db_student.setTotal(m_User.login, mark, m_Student.amount_of_total);
            break;
    }
}
