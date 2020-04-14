#ifndef Core_hpp
#define Core_hpp

#include "Authorization/Authorization.hpp"
#include "Controllers/Teacher/Teacher.hpp"
#include "Controllers/Student/Student.hpp"

class Core {
public:
    void start(void);
private:
    Authorization m_authorization;
    class StudentMenu m_student;
    class TeacherMenu m_teacher;
};

#endif
