#include "gtest/gtest.h"

extern "C" {
#include "students/student.h"
}

TEST(create_student, check_value) {
    struct Student test_Student = {"Igor", "Barishpol", 'm', 20};
    struct Student* test_Student_2_ptr = create_student("Igor", "Barishpol", 'm', 20);
    EXPECT_STREQ(test_Student_2_ptr->first_name, test_Student.first_name);
    EXPECT_STREQ(test_Student_2_ptr->last_name, test_Student.last_name);
    EXPECT_EQ(test_Student_2_ptr->age, test_Student.age);
    EXPECT_EQ(test_Student_2_ptr->gender, test_Student.gender);
    remove_student(test_Student_2_ptr);
}
//TEST(create_student, check ) {
//    struct Student* test_Student_ptr = create_student("Igor", "Barishpol", 'm', 20);
//    if (test_Student_ptr != nullptr) {
//        remove_student(test_Student_ptr);
//        //EXPECT_EQ(test_Student_ptr, nullptr);
//    }
//}