#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "students/student.h"
#include "students/students_list.h"

#define NEW_STR "New"
#define END_STR "End"
#define UNEXP_INP "Error. Unexpected input."

#define FIND_FIRST "by first"
#define FIND_LAST "by last"
#define FIND_FULL "by full"

#define ERROR "Something goes wrong"


struct Student* input_new_student(struct StudentsList *cur_list);
struct Student* start_finding(struct StudentsList *cur_list);

int main() {
    struct StudentsList *cur_list = create_students_list();
    printf("Input \"%s\" to add new student \n"
           "or \"%s\" to find someone\n", NEW_STR, END_STR);
    char buffer[4];
    scanf("%3s", buffer);
    if (strncmp(NEW_STR, buffer, strlen(NEW_STR)) == 0) {
        struct Student *new_stud = input_new_student(cur_list);
        if (new_stud == NULL) {
            printf("\"%s\"", ERROR);
            remove_students_list(cur_list);
            return -1;
        }
    }
    else if (strncmp(END_STR, buffer, strlen(END_STR)) == 0) {
        start_finding(cur_list);
    }
    else
        printf("%s\n", UNEXP_INP);
    return 0;
}

struct Student* input_new_student(struct StudentsList *cur_list) {
    printf("Input first name:\n");
    char first_name[50];
    scanf("%49s", first_name);

    printf("Input last name:\n");
    char last_name[50];
    scanf("%49s", last_name);
    fflush(stdin);

//    printf("Input age:\n");
    unsigned short age = 20;
//    char buffer[4];
//    scanf("%3s", buffer);
//    char **end = NULL;
//    age = strtoul(buffer, end, 0);

    printf("Input gender:\n");
    char gender;
    scanf("%c", &gender);

    struct Student *new_stud = create_student(first_name, last_name, gender, age);
    if (new_stud == NULL) return NULL;
    struct Student *stud_in_list = add_new_student(new_stud, &cur_list);
    if (stud_in_list == NULL) {
        remove_student(new_stud);
        return NULL;
    }
    return stud_in_list;
}

struct Student* start_finding(struct StudentsList *cur_list) {
    printf("Input \"%s\" if you want to find student by first name \n"
           "or \"%s\" to find student by last name\n"
           "or \"%s\" to find student by full name\n"
           "or \"%s\" to add someone more", FIND_FIRST, FIND_LAST, FIND_FULL, END_STR);
    char buffer[9];
    scanf("%8s", buffer);
    if (strncmp(FIND_FIRST, buffer, strlen(FIND_FIRST)) == 0) {
        printf("Input first name\n");
        char input[50];
        scanf("%49s", input);
        find_students_by_first_name(input, cur_list);
    }
    else if (strncmp(FIND_LAST, buffer, strlen(FIND_LAST)) == 0) {
        printf("Input last name\n");
        char input[50];
        scanf("%49s", input);
        find_students_by_last_name(input, cur_list);
    }
    else if (strncmp(FIND_FULL, buffer, strlen(FIND_FULL)) == 0) {
        printf("Input first name\n");
        char first_name_inp[50];
        scanf("%49s", first_name_inp);
        printf("Input last name\n");
        char last_name_inp[50];
        scanf("%49s", last_name_inp);
        find_student_by_name(first_name_inp, last_name_inp, cur_list);
    }
    else if (strncmp(END_STR, buffer, strlen(END_STR)) == 0) {
        input_new_student(cur_list);
    }
    else
        printf("%s\n", UNEXP_INP);
    return 0;
}

// int main() {
//    struct StudentsList* students_list = create_students_list();
//    if (students_list == NULL)
//        return -1;
//    struct Student *test_student_1 = create_student("Igor", "Barishpol", MALE, 20);
//    struct Student *test_student_2 = create_student("Dasha", "Glibchenko", FEMALE, 20);
//    struct Student *test_student_3 = create_student("Vladimir", "Lunkin", MALE, 19);
//    struct Student *test_student_4 = create_student("Stas", "Yakovitskiy", MALE, 23);
//    struct Student *test_student_33 = create_student("Vladimir", "Zelenskiy", MALE, 19);
//    struct Student *test_student_44 = create_student("Max", "Yakovitskiy", MALE, 23);
//
//    if (add_new_student(test_student_1, &students_list) == NULL) {
//        return -1;
//    }
//    if (add_new_student(test_student_2, &students_list) == NULL) {
//        return -1;
//    }
//    if (add_new_student(test_student_3, &students_list) == NULL) {
//        return -1;
//    }
//    if (add_new_student(test_student_4, &students_list) == NULL) {
//        return -1;
//    }
//    if (add_new_student(test_student_33, &students_list) == NULL) {
//        return -1;
//    }
//    if (add_new_student(test_student_44, &students_list) == NULL) {
//        return -1;
//    }
//    struct Student *founded = NULL;
//    founded = find_student_by_name("Igor", "Barishpol", students_list);
//    printf("%s %s\n", founded->first_name, founded->last_name);
//    founded = find_student_by_name("Igor", "Baris", students_list);
//    if (founded == NULL) {
//        printf("/////////////\n");
//    }
//
//    struct StudentsList *founddd = NULL;
//    founddd = find_students_by_first_name("Igor", students_list);
//    printf("%s %s\n", founddd->arr[0].first_name, founddd->arr[0].last_name);
//    remove_students_list(founddd);
//    founddd = find_students_by_first_name("Vladimir", students_list);
//    printf("%s %s\n%s %s\n", founddd->arr[0].first_name, founddd->arr[0].last_name, founddd->arr[1].first_name, founddd->arr[1].last_name);
//    remove_students_list(founddd);
//    founddd = find_students_by_first_name("Ivan", students_list);
//    if (founddd == NULL) {
//        printf("/////////////\n");
//    }
//    remove_students_list(founddd);
//
//    founddd = find_students_by_last_name("Glibchenko", students_list);
//    printf("%s %s\n", founddd->arr[0].first_name, founddd->arr[0].last_name);
//    remove_students_list(founddd);
//    founddd = find_students_by_last_name("Yakovitskiy", students_list);
//    printf("%s %s\n%s %s\n", founddd->arr[0].first_name, founddd->arr[0].last_name, founddd->arr[1].first_name, founddd->arr[1].last_name);
//    remove_students_list(founddd);
//    founddd = find_students_by_last_name("Ivanov", students_list);
//    if (founddd == NULL) {
//        printf("/////////////\n");
//    }
//    remove_students_list(founddd);
//
//    remove_students_list(students_list);
//    printf("%9s", test_student_1->last_name);
//    remove_student(test_student_1);
//    remove_student(test_student_2);
//    remove_student(test_student_3);
//    remove_student(test_student_4);
//    remove_student(test_student_33);
//    remove_student(test_student_44);
//    return 0;
// }