/*
 * Program that will define a struct Student. Asks the user how
 * many students to input(max 50), for each student, gets their name and grade.
 * After all inputs are done, prints student with highest grade, average grade
 * a list of students who scored above average.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//create and typedef the struct of students
typedef struct
{
    char name[100];
    int grade;
} Student;

void clear_buffer () 
{
    //Used to clear input buffer after scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void get_name (Student * student, int student_number)
{
    //Gets the name of the students from the user
    printf("\nName of student No. %d: ", student_number+1);
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0'; // removes newline
}

void get_grade (Student * student, int student_number)
{
    //Gets the grade of the student from the user
    int grade;
    printf("\nGrade of %s: ",student->name);
    scanf("%d", &(student->grade));
    clear_buffer();
}

int find_highest_grade(Student * students, int num_students)
{
    int idx;
    int highest_grade = students[0].grade;
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].grade > highest_grade)
        {
            highest_grade = students[i].grade;
            idx = i;
        }
    }
    return idx;
}

int find_average_grades(Student * students, int num_students)
{
    float avg;
    int sum_grades = 0;
    for (int i = 0; i < num_students; i++)
    {
        sum_grades += students[i].grade;
    }
    avg = sum_grades/ (float)num_students;
    return avg;
}

int main(int argc, char *argv[])
{

    //Get number of students from user
    int num_students;
    printf("How many students do you want to enter(max 50): ");
    scanf("%d", &num_students);
    clear_buffer();

    //check if the number entered is valid or not
    if (num_students < 1 || num_students > 50)
    {
        printf("\nInvalid number.\n");
        return 1;
    }

    //create the students array
    Student students[num_students];

    for (int i = 0; i < num_students; i++)
    {
        get_name(&students[i],  i);
        get_grade(&students[i], i);

    }
    
    //decor
    printf("\n\n*********************\n");

    // Student with highest grade
    printf("\nStudent with highest grade is: %s", students[find_highest_grade(students, num_students)].name);

    //average grade
    float avg_grades = find_average_grades(students, num_students);
    printf("\nAverage grade of all students: %f", avg_grades);

    //list of students who scored above average
    printf("\nStudents who score above average: ");
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].grade >= avg_grades) 
        {
            printf("%s ",students[i].name);
        }
    }

    //decor
    printf("\n\n*********************\n");
    return EXIT_SUCCESS;
}
