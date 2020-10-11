#include <stdio.h>
#include <stdio.h>
#include "../include/student.h"
#include "../include/students_list.h"

int main() {
    const char MALE = 'm';
    const char FEMALE = 'f';
    struct StudentsList* students_list = create_students_list();
    if (students_list == NULL)
        return -1;
    struct Student *test_student_1 = create_student("Igor", "Barishpol", MALE, 20);
    struct Student *test_student_2 = create_student("Dasha", "Glibchenko", FEMALE, 20);
    struct Student *test_student_3 = create_student("Vladimir", "Lunkin", MALE, 19);
    struct Student *test_student_4 = create_student("Stas", "Yakovitskiy", MALE, 23);
    struct Student *test_student_33 = create_student("Vladimir", "Zelenskiy", MALE, 19);
    struct Student *test_student_44 = create_student("Max", "Yakovitskiy", MALE, 23);

    if (add_new_student(test_student_1, students_list) == NULL) {
        return -1;
    }
    if (add_new_student(test_student_2, students_list) == NULL) {
        return -1;
    }
    if (add_new_student(test_student_3, students_list) == NULL) {
        return -1;
    }
    if (add_new_student(test_student_4, students_list) == NULL) {
        return -1;
    }
    if (add_new_student(test_student_33, students_list) == NULL) {
        return -1;
    }
    if (add_new_student(test_student_44, students_list) == NULL) {
        return -1;
    }
    struct Student *founded = NULL;
    founded = find_student_by_name("Igor", "Barishpol", students_list);
    printf("%s %s\n", founded->first_name, founded->last_name);
    founded = find_student_by_name("Igor", "Baris", students_list);
    if (founded == NULL) {
        printf("/////////////\n");
    }

    struct StudentsList *founddd = NULL;
    founddd = find_students_by_first_name("Igor", students_list);
    printf("%s %s\n", founddd->arr[0].first_name, founddd->arr[0].last_name);
    remove_students_list(founddd);
    founddd = find_students_by_first_name("Vladimir", students_list);
    printf("%s %s\n%s %s\n", founddd->arr[0].first_name, founddd->arr[0].last_name, founddd->arr[1].first_name, founddd->arr[1].last_name);
    remove_students_list(founddd);
    founddd = find_students_by_first_name("Ivan", students_list);
    if (founddd == NULL) {
        printf("/////////////\n");
    }
    remove_students_list(founddd);

    founddd = find_students_by_last_name("Glibchenko", students_list);
    printf("%s %s\n", founddd->arr[0].first_name, founddd->arr[0].last_name);
    remove_students_list(founddd);
    founddd = find_students_by_last_name("Yakovitskiy", students_list);
    printf("%s %s\n%s %s\n", founddd->arr[0].first_name, founddd->arr[0].last_name, founddd->arr[1].first_name, founddd->arr[1].last_name);
    remove_students_list(founddd);
    founddd = find_students_by_last_name("Ivanov", students_list);
    if (founddd == NULL) {
        printf("/////////////\n");
    }
    remove_students_list(founddd);

    remove_students_list(students_list);
    printf("%9s", test_student_1->last_name);
    remove_student(test_student_1);
    remove_student(test_student_2);
    remove_student(test_student_3);
    remove_student(test_student_4);
    remove_student(test_student_33);
    remove_student(test_student_44);
    return 0;
}











#include <string.h>
#include <stdlib.h>
#include "../include/student.h"

#define NEW_STR "New"
#define END_STR "End"
#define UNEXP_INP "Error. Unexpected input."

struct Student* input_new_student();

int main() {
    printf("Input \"%s\" to add new student or \"%s\" to finish adding\n", NEW_STR, END_STR);
    char buffer[4];
    scanf("%3s", buffer);
    if (strncmp(NEW_STR, buffer, strlen(NEW_STR)) == 0) {
        input_new_student();
    }
    else if (strncmp(END_STR, buffer, strlen(END_STR)) == 0) {

    }
    else
        printf("%s\n", UNEXP_INP);
    return 0;
}

struct Student* input_new_student() {
    printf("Input first name:\n");
    char first_name[50];
    scanf("%49s", first_name);

    printf("Input last name:\n");
    char last_name[50];
    scanf("%49s", last_name);

    printf("Input age:\n");
    unsigned short age = 0;
    char buffer[4];
    scanf("%3s", buffer);
    // strtoul();

    printf("Input gender:\n");
    char gender;
    scanf("%c", &gender);

    return add_student(first_name, last_name, gender, age);
}