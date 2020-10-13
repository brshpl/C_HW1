#include "students/students_list.h"

//const size_t NUM_STUD_DEFAULT = 100;

struct StudentsList *create_students_list() {
    struct StudentsList *list = NULL;
    list = (struct StudentsList*) malloc(sizeof(struct StudentsList));
    if (list == NULL) {
        return NULL;
    }
    list->arr = (struct Student*) malloc(NUM_STUD_DEFAULT * sizeof(struct Student));
    if (list->arr == NULL) {
        free(list);
        return NULL;
    }
    list->cur_size = 0;
    list->mem_size = NUM_STUD_DEFAULT;
    return list;
}

void remove_students_list(struct StudentsList *list) {
    if (list == NULL)
        return;
    for(size_t i = 0; i < list->cur_size; ++i) {
        remove_student_from_list(&(list->arr[i]));
    }
    free(list->arr);
    free(list);
}

void remove_student_from_list(struct Student *student) {
    free(student->first_name);
    free(student->last_name);
    student->gender = '\0';
    student->age = 0;
}

struct Student *add_new_student(const struct Student *const new_student, struct StudentsList **list) {
    if (new_student == NULL || list == NULL || (*list) == NULL)
        return NULL;
    if ((*list)->cur_size == (*list)->mem_size) {
        struct StudentsList *tmp = NULL;
        tmp = (struct StudentsList*) realloc((*list), (*list)->mem_size + NUM_STUD_DEFAULT);
        if (tmp == NULL)
            return NULL;
        (*list) = tmp;
        (*list)->mem_size += NUM_STUD_DEFAULT;
    }
    struct Student *student_in_list = &((*list)->arr[(*list)->cur_size]);

    size_t str_length = strlen(new_student->first_name);
    student_in_list->first_name = malloc(sizeof(char) * str_length + 1);
    if (student_in_list->first_name == NULL)
        return NULL;
    strncpy(student_in_list->first_name, new_student->first_name, str_length + 1);

    str_length = strlen(new_student->last_name);
    student_in_list->last_name = malloc(sizeof(char) * str_length + 1);
    if (student_in_list->last_name == NULL) {
        free(student_in_list->first_name);
        return NULL;
    }
    strncpy(student_in_list->last_name, new_student->last_name, str_length + 1);

    student_in_list->age = new_student->age;
    student_in_list->gender = new_student->gender;

    ++((*list)->cur_size);
    return student_in_list;
}

struct StudentsList *find_students_by_last_name(const char *const last_name, const struct StudentsList *const list) {
    if (last_name == NULL || list == NULL)
        return NULL;
    struct StudentsList *found_students = create_students_list();
    if (found_students == NULL) {
        return NULL;
    }
    size_t l_name_length = strlen(last_name);
    for (size_t i = 0; i < list->cur_size; ++i) {
        if (strncmp(last_name, list->arr[i].last_name, l_name_length + 1) == 0 &&
            strlen(list->arr[i].last_name) == l_name_length) {
            if (add_new_student(&(list->arr[i]), &found_students) == NULL) {
                remove_students_list(found_students);
                return NULL;
            }
        }
    }
    if (found_students->cur_size == 0) {
        remove_students_list(found_students);
        return NULL;
    }
    return found_students;
}

struct StudentsList *find_students_by_first_name(const char *const first_name, const struct StudentsList *const list) {
    if (first_name == NULL || list == NULL)
        return NULL;
    struct StudentsList *found_students = create_students_list();
    if (found_students == NULL) {
        return NULL;
    }
    size_t f_name_length = strlen(first_name);
    for (size_t i = 0; i < list->cur_size; ++i) {
        if (strncmp(first_name, list->arr[i].first_name, f_name_length + 1) == 0 &&
            strlen(list->arr[i].first_name) == f_name_length) {
            if (add_new_student(&(list->arr[i]), &found_students) == NULL) {
                remove_students_list(found_students);
                return NULL;
            }
        }
    }
    if (found_students->cur_size == 0) {
        remove_students_list(found_students);
        return NULL;
    }
    return found_students;
}

struct Student *find_student_by_name(const char *const first_name, const char *const last_name, const struct StudentsList *const list) {
    if (first_name == NULL || last_name == NULL || list == NULL)
        return NULL;
    size_t f_name_length = strlen(first_name);
    size_t l_name_length = strlen(last_name);
    for (size_t i = 0; i < list->cur_size; ++i) {
        if (strncmp(first_name, list->arr[i].first_name, f_name_length) == 0 &&
            strlen(list->arr[i].first_name) == f_name_length)
            if (strncmp(last_name, list->arr[i].last_name, l_name_length) == 0 &&
                strlen(list->arr[i].last_name) == l_name_length)
                return &(list->arr[i]);
    }
    return NULL;
}