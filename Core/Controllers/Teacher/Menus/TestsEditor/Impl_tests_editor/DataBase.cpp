#include "../TestsEditor.hpp"

void TestsEditor::set_tests(void) {
    m_db_test_first.load_tests(all_tests[0]);
    m_db_test_second.load_tests(all_tests[1]);
    m_db_test_third.load_tests(all_tests[2]);
    for (size_t i = 0; i < 3; i++) {
        if (all_tests[i].size())
            empty[i] = false;
        else
            empty[i] = true;
    }
    reset_show();
    reset_pages();
}
