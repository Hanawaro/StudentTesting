#include "../EditTest.hpp"

void EditTest::edit_test(void) {
    // write
    m_Test.question  = real_question;
    m_Test.answer[0] = real_first_answer;
    m_Test.answer[1] = real_second_answer;
    m_Test.answer[2] = real_third_answer;
    m_Test.right     = (int) is_check_bar;
    
    // load to server
    switch (g_locale) {
        case 0:
            m_db_test_first.edit_test(m_Test);
            break;
        case 1:
            m_db_test_second.edit_test(m_Test);
            break;
        case 2:
            m_db_test_third.edit_test(m_Test);
            break;
    }
}
