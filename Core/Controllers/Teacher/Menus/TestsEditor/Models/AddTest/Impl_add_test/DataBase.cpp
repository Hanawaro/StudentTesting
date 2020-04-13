#include "../AddTest.hpp"

void AddTest::add_new_test(void) {
    Test test;
    test.id = 0;
    test.question = real_question;
    test.answer[0] = real_first_answer;
    test.answer[1] = real_second_answer;
    test.answer[2] = real_third_answer;
    test.right = (int) is_check_bar;
    switch (g_locale) {
        case 0 :
            m_db_test_first.add_test(test);
            break;
        case 1:
            m_db_test_second.add_test(test);
            break;
        case 2:
            m_db_test_third.add_test(test);
            break;
    }
    
    std::vector<Test> tests;
    m_db_test_first.load_tests(tests);
    std::ofstream dbg("debug");
    
    dbg << tests.size() << std::endl << std::endl;
    
    for (int i = 0; i < tests.size(); i++) {
        dbg << tests[i].id << std::endl;
        dbg << tests[i].question << std::endl;
        for (int j = 0; j < 3; j++)
            dbg << tests[i].answer[j] << std::endl;
        dbg << tests[i].right << std::endl << std::endl;
    }
    
    dbg.close();
    return;
}
