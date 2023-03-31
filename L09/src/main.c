/**
 * @file main.c
 * @author Yijie Zhu
 * @date 2023-03-31
 * @brief Entry point for the program, which creates a course, enrolls students, and performs various operations on them.
 */
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"
/**
 * \brief The main function of the program.
 * 
 * This function generates a course object, enrolls students, and performs some basic analysis on the students' performance.
 * 
 * @return 0 upon successful completion of the program.
 */
int main()
{
  srand((unsigned) time(NULL));

  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  // Enroll 20 randomly generated students
  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  // Print the course information and enrolled students
  print_course(MATH101);
  // Get the top performing student and print their information
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);
  // Get the passing students and print their information
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}
