/**
 * @file student.h
 * \brief Contains the definition of the Student struct and the declarations of functions related to students.
 * 
 * This header file provides the definition of the Student struct, which holds information about a student,
 * such as their first name, last name, and grades. Additionally, it declares functions that can be used to
 * manipulate and print information about students, as well as generate random students.
 *
 * @date 2023-03-31
 * @author Yijie Zhu
 */
typedef struct _student 
{ 
  char first_name[50]; /**< First name of the student */
  char last_name[50]; /**< Last name of the student */
  char id[11]; /**< Student ID */
  double *grades;  /**< List of grades for the student */
  int num_grades; /**< Total number of grades for the student */
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
