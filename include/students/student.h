#ifndef INCLUDE_STUDENTS_STUDENT_H_
#define INCLUDE_STUDENTS_STUDENT_H_

#include <string.h>
#include "/usr/include/malloc.h"

#define MALE 'm'
#define FEMALE 'f'

struct Student {
    char* first_name;
    char* last_name;
    char gender;      // 'm' or MALE = male, 'f' or FEMALE = female
    unsigned int age;
};

struct Student *create_student(const char* _first_name,
        const char* _last_name, char _gender, unsigned int _age);

void remove_student(struct Student *student);

#endif  // INCLUDE_STUDENTS_STUDENT_H_
