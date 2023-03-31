/**
 * @file student.c
 * @brief Contains the implementation of the functions for managing students defined in student.h
 * @author Yijie Zhu
 * @date 2023-03-31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
/**
 * \brief Adds a grade to a student's record
 * 
 * @param student Pointer to the student record to update
 * @param grade The grade to add
 */
void add_grade(Student* student, double grade)
{
  student->num_grades++;
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));
  else 
  {
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }
  student->grades[student->num_grades - 1] = grade;
}
/**
 * \brief Calculates the average grade for a student
 * 
 * @param student Pointer to the student record to calculate the average for
 * @return The average grade for the student
 */
double average(Student* student)
{
  if (student->num_grades == 0) return 0;

  double total = 0;
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];
  return total / ((double) student->num_grades);
}
/**
 * \brief Prints out the information for a student, including their name, ID, grades, and average
 * 
 * @param student Pointer to the student record to print
 */
void print_student(Student* student)
{
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}
/**
 * \brief Generates a new random student record
 * 
 * @param grades The number of grades to generate for the student
 * @return A pointer to the newly generated student record
 * @note The caller is responsible for freeing the memory allocated for the student record
 * @attention This function uses a fixed list of first and last names to generate the student's name
 * @warning The student ID generated is a random 10-digit string of digits
 */
Student* generate_random_student(int grades)
{
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
 
  Student *new_student = calloc(1, sizeof(Student));

  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  new_student->id[10] = '\0';

  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  return new_student;
}
