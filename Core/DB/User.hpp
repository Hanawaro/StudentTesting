#ifndef user_h
#define user_h

#include <iostream>
#include <string>

enum Status {
    None,
    Teacher,
    Student
};

enum Mark {
    Empty,
    Two,
    Three,
    Four,
    Five
};

class User {
public:
    Status status;
    std::string login;
    std::string first_name;
    std::string second_name;
};

class Student {
public:
    Mark first;
    Mark second;
    Mark third;
    Mark total;
    
    int32_t amount_of_first;
    int32_t amount_of_second;
    int32_t amount_of_third;
    int32_t amount_of_total;
};

struct info_student {
    User user;
    class Student student;
};

#endif
