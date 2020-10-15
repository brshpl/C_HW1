#ifndef INCLUDE_STUDENTS_STUDENTS_LIST_H_
#define INCLUDE_STUDENTS_STUDENTS_LIST_H_

#include "./student.h"

#define NUM_STUD_DEFAULT 100

struct StudentsList {
    size_t cur_size;
    size_t mem_size;
    struct Student *arr;
};

struct StudentsList *create_students_list();

void remove_students_list(struct StudentsList *list);

void remove_student_from_list(struct Student *student);

struct Student *add_new_student(const struct Student *new_student,
        struct StudentsList **list);

struct StudentsList *find_students_by_last_name(const char *last_name,
        const struct StudentsList *list);

struct StudentsList *find_students_by_first_name(const char *first_name,
        const struct StudentsList *list);

struct Student *find_student_by_name(const char *first_name,
        const char *last_name, const struct StudentsList *list);

#endif  // INCLUDE_STUDENTS_STUDENTS_LIST_H_
