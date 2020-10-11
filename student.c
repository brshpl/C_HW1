#include "student.h"

struct Student *create_student(const char* _first_name, const char* _last_name, const char _gender, const unsigned short _age) {
    struct Student *new_student = malloc(sizeof(struct Student));
    if (new_student == NULL)
        return NULL;
    size_t str_length = strlen(_first_name);
    new_student->first_name = (char*) calloc(str_length + 1, sizeof(char));
    if (new_student->first_name == NULL){
        free(new_student);
        return NULL;
    }
    strncpy(new_student->first_name, _first_name, str_length);

    str_length = strlen(_last_name);
    new_student->last_name = (char*) calloc(str_length + 1, sizeof(char));
    if (new_student->last_name == NULL){
        free(new_student->first_name);
        free(new_student);
        return NULL;
    }
    strncpy(new_student->last_name, _last_name, str_length);

    new_student->gender = _gender;
    new_student->age = _age;
    return new_student;
}

void remove_student(struct Student *student) {
    free(student->first_name);
    free(student->last_name);
    free(student);
}