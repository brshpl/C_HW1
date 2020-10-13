#ifndef HW1_STUDENT_H
#define HW1_STUDENT_H

#include "malloc.h"
#include <string.h>

//const char MALE = 'm';
//const char FEMALE = 'f';

struct Student {
    char* first_name;
    char* last_name;
    char gender; // 'm' or MALE = male, 'f' or FEMALE = female
    unsigned short age;
};

struct Student *create_student(const char* _first_name, const char* _last_name, char _gender, unsigned short _age);

void remove_student(struct Student *student);

#endif //HW1_STUDENT_H
