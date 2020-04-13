#ifndef Core_hpp
#define Core_hpp

#include "Authorization/Authorization.hpp"
#include "Controllers/Teacher/Teacher.hpp"
#include "Controllers/Student/Student.hpp"

class Core {
public:
    void Start(void);
private:
    bool Running = false;
    Authorization authorization;
    class StudentMenu student;
    class TeacherMenu teacher;
};

#endif
