#include "gtest/gtest.h"

extern "C" {
#include "students/students_list.h"
}

TEST(create_student_list, check_create) {
    struct StudentsList *list = create_students_list();
    EXPECT_NE(list, nullptr);
    remove_students_list(list);
}

TEST(add_new_student, check_to_add){
    struct StudentsList* list = create_students_list();
    struct Student* test_Student_ptr = create_student("Igor", "Barishpol", 'm', 20);
    add_new_student(test_Student_ptr, &list);
    EXPECT_STREQ(list->arr[0].first_name, test_Student_ptr->first_name);
    EXPECT_STREQ(list->arr[0].last_name, test_Student_ptr->last_name);
    EXPECT_EQ(list->arr[0].age, test_Student_ptr->age);
    EXPECT_EQ(list->arr[0].gender, test_Student_ptr->gender);
    remove_student(test_Student_ptr);
    remove_students_list(list);
}

TEST(add_new_student, add_nullptr) {
    struct StudentsList* list = create_students_list();
    struct Student* test_Student_ptr = nullptr;
    struct Student *stud_in_list = add_new_student(test_Student_ptr, &list);
    EXPECT_EQ(stud_in_list, nullptr);
    remove_students_list(list);
}

TEST(find_students_by_last_name, true_find) {
    struct StudentsList* list = create_students_list();
    struct Student *test_Student1 = create_student("Pavel", "Argentov", 'm', 45);
    struct Student *test_Student2 = create_student("Igor", "Barishpol", 'm', 20);
    add_new_student(test_Student1, &list);
    add_new_student(test_Student2, &list);
    struct StudentsList *found_students = find_students_by_last_name("Barishpol", list);
    struct StudentsList *not_found_students = find_students_by_last_name("Ivanov", list);
    EXPECT_STREQ(found_students->arr[0].last_name, test_Student2->last_name);
    EXPECT_STREQ(found_students->arr[0].first_name, test_Student2->first_name);
    EXPECT_EQ(found_students->arr[0].age, test_Student2->age);
    EXPECT_EQ(found_students->arr[0].gender, test_Student2->gender);
    EXPECT_EQ(not_found_students, nullptr);
    remove_student(test_Student1);
    remove_student(test_Student2);
    remove_students_list(list);
    remove_students_list(found_students);
}

TEST(find_students_by_last_name, false_find) {
    struct StudentsList* list = nullptr;
    struct Student *test_Student = create_student("Igor", "Barishpol",
            'm', 20);
    add_new_student(test_Student, &list);
    EXPECT_EQ(find_students_by_last_name("Barishpol", list), nullptr);
    remove_students_list(list);
    remove_student(test_Student);
}

TEST(find_students_by_first_name, true_find) {
    struct StudentsList* list = create_students_list();
    struct Student *test_Student1 = create_student("Pavel", "Argentov",
            'm', 45);
    struct Student *test_Student2 = create_student("Igor", "Barishpol",
            'm', 20);
    add_new_student(test_Student1, &list);
    add_new_student(test_Student2, &list);
    struct StudentsList *found_students = find_students_by_first_name(
            "Igor", list);
    struct StudentsList *not_found_students = find_students_by_first_name(
            "Ivan", list);
    EXPECT_STREQ(found_students->arr[0].last_name,
                 test_Student2->last_name);
    EXPECT_STREQ(found_students->arr[0].first_name,
                 test_Student2->first_name);
    EXPECT_EQ(found_students->arr[0].age,
              test_Student2->age);
    EXPECT_EQ(found_students->arr[0].gender,
              test_Student2->gender);
    EXPECT_EQ(not_found_students, nullptr);
    remove_student(test_Student1);
    remove_student(test_Student2);
    remove_students_list(list);
    remove_students_list(found_students);
}

TEST(find_students_by_first_name, false_find) {
    struct StudentsList* list = nullptr;
    struct Student *test_Student = create_student("Igor", "Barishpol",
            'm', 20);
    add_new_student(test_Student, &list);
    EXPECT_EQ(find_students_by_first_name("Igor", list), nullptr);
    remove_students_list(list);
    remove_student(test_Student);
}

TEST(find_student_by_name, false_find) {
    struct StudentsList* list = nullptr;
    struct Student *test_Student = create_student("Igor", "Barishpol",
            'm', 20);
    add_new_student(test_Student, &list);
    EXPECT_EQ(find_student_by_name("Igor", "Barishpol", list), nullptr);
    remove_students_list(list);
    remove_student(test_Student);
}

TEST(find_student_by_name, true_find) {
    struct StudentsList* list = create_students_list();
    struct Student *test_Student1 = create_student("Pavel", "Argentov",
            'm', 45);
    struct Student *test_Student2 = create_student("Igor", "Barishpol",
            'm', 20);
    add_new_student(test_Student1, &list);
    add_new_student(test_Student2, &list);
    struct Student *found_stud_addr = find_student_by_name("Igor",
            "Barishpol", list);
    struct Student *not_found_stud_addr = find_student_by_name("Ivan",
            "Ivanov", list);
    EXPECT_EQ(found_stud_addr, &list->arr[1]);
    EXPECT_EQ(not_found_stud_addr, nullptr);
    remove_students_list(list);
    remove_student(test_Student1);
    remove_student(test_Student2);
}
