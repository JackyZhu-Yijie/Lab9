/**
 * @file course.c
 * @brief Implementation file for Course struct and related functions.
 * @author Yijie Zhu
 * @date 2023-3-30
 */
#include "course.h"
#include <stdlib.h>
#include <stdio.h>
/**
 *  \brief Enrolls a student in a course.
 *
 * This function increases the number of students in the course by one and adds the
 * new student to the list of students.
 *
 * @param course The course to enroll the student in.
 * @param student The student to enroll in the course.
 */
void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  course->students[course->total_students - 1] = *student;
}
/**
 * \brief Prints information about a course and its students.
 *
 * This function prints the name, code, and total number of students in the course, and
 * then calls the `print_student` function for each student in the course.
 *
 * @param course The course to print information about.
 */
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}
/**
 * \brief Finds the student with the highest average grade in the course.
 *
 * This function iterates through the list of students in the course and calculates the
 * average grade for each student. It returns a pointer to the student with the highest
 * average grade.
 *
 * @param course The course to find the top student in.
 * @return A pointer to the student with the highest average grade, or NULL if there are no
 *         students in the course.
 */
Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}
/**
 * \brief Calculates the number of passing students in a course.
 *
 * This function calculates the number of students in a course who have a passing grade.
 * A passing grade is defined as a grade of 50 or above.
 *
 * @param course The course to calculate the number of passing students for.
 * @param total_passing A pointer to an integer that will be set to the total number of passing students.
 * @return An array of pointers to Student structures, containing the passing students.
 *         The size of the array is equal to the number of passing students.
 *         If there are no passing students, NULL is returned.
 *
 * @note The returned array must be freed by the caller using free().
 * @warning The total_passing parameter must point to a valid integer variable.
 */
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  passing = calloc(count, sizeof(Student));

  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}
