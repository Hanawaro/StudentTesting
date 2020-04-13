#include "Core/DB/DB.hpp"
#include "Core/DB/Test.hpp"

namespace InitUsers {

    void init(void) {
        std::ofstream clear_db_user("Source/Users/user");
        clear_db_user.close();
        std::ofstream clear_db_student("Source/Users/student");
        clear_db_student.close();
        
        db_user m_db_user;
        // administrator
        m_db_user.addUser("admin", 404, "Hanawaro", "Kato", "123");
        // users
        m_db_user.addUser("19pri_Savkin", 123, "Stepan", "Savkin", "123");
        m_db_user.addUser("19pri_Shelepina", 123, "Olga", "Shelepina", "123");
        m_db_user.addUser("19pri_Telesheva", 123, "Elena", "Telesheva", "123");
        m_db_user.addUser("19pri_Kuzmina", 123, "Julia", "Kuzmina", "123");
        m_db_user.addUser("19pri_Marchencov", 123, "Dmitriy", "Marchencov", "123");
        
        db_test_first  m_db_test_first;
        db_test_second m_db_test_second;
        db_test_third  m_db_test_third;
        
        std::ofstream clear_auth("Source/authorization");
        clear_auth.close();
        
        std::ofstream clear_db_test_first("Source/Tests/firstTest");
        clear_db_test_first.close();
        std::ofstream clear_db_test_second("Source/Tests/secondTest");
        clear_db_test_second.close();
        std::ofstream clear_db_test_third("Source/Tests/thirdTest");
        clear_db_test_third.close();
        
        for (int i = 0; i < 13; i++) {
            Test tmp_test;
            tmp_test.id = 0;
            tmp_test.question = std::string("Question number ") + std::to_string(i + 1) + " by default";
            tmp_test.answer[0] = "false";
            tmp_test.answer[1] = "true";
            tmp_test.answer[2] = "false";
            tmp_test.right = 2;
            m_db_test_first.add_test(tmp_test);
        }
        
        Test tmp_test;
        tmp_test.question = std::string("Finaly gg");
        tmp_test.answer[0] = "Shit";
        tmp_test.answer[1] = "Not interesting";
        tmp_test.answer[2] = "The best";
        tmp_test.right = 3;
        m_db_test_third.add_test(tmp_test);
    }

}
