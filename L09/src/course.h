/**
 * @file student.h
 * @brief Header file for Course struct and related functions. Defines the Course and Student structs and function prototypes for enroll_student, print_course, top_student, and passing. 
 * @date 2023-3-30
 */
#include "student.h"
#include <stdbool.h>
/**
 * \brief A structure representing a course.
 * 
 * This structure holds information about a course, including its name and code, 
 * as well as an array of enrolled students and the total number of enrolled students.
 */
typedef struct _course 
{
  char name[100]; /**< The name of the course. */
  char code[10]; /**< The course code. */
  Student *students; /**< An array of enrolled students. */
  int total_students; /**< The total number of enrolled students. */
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);

