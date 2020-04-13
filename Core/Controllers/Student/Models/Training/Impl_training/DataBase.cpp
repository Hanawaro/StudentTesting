#include "../Training.hpp"

void Training::load_tests(void) {
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
        return;
    } else if (tests.size() == 1) {
        once = true;
        randomize.push_back(0);
        for (size_t j = 0; j < 3; j++)
            tests[0].answer[j] = std::to_string(j + 1) + ") " + tests[0].answer[j];
        reset_answers(tests[0]);
        return;
    }
    
    for (size_t i = 0; i < tests.size(); i++) {
        randomize.push_back(i);
        for (size_t j = 0; j < 3; j++)
            tests[i].answer[j] = std::to_string(j + 1) + ") " + tests[i].answer[j];
        reset_answers(tests[i]);
    }
    
    std::random_device rd;
    std::mt19937 g(rd());
    
    std::shuffle(randomize.begin(), randomize.end(), g);
}
