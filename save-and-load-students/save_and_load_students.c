/*
 * 1. Define a struct student
 * 2. Lets the user choose to:
 * - Add student, Save to file, load from file and display, quit
 * 3. Stores all students in a dynamically growing array 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[100];
    int grade;
} Student;

void addstudent(Student pStudents[], int student_count);
void printstudents(Student pStudents[], int student_count);
void saveandquit(Student pStudents[], int student_count);
int get_int();

int main(int argc, char *argv[])
{
    //First we load the file, then we store the load
    //in an array. All new students are then added as more
    //elements. Give option to save, display or add.

    //Load the file
    FILE *f = fopen("students.txt", "r");
    if (f == NULL)
    {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    //init student structarray
    Student * pStudents = NULL;
    size_t student_count = 0;

    //init linearray
    char *pLine = NULL;
    size_t f_len = 0;
    ssize_t read;

    while ((read = getline(&pLine, &f_len, f)) != -1)
    {
        Student * temp = realloc(pStudents, (student_count +1) * sizeof(Student));
        if (temp == NULL)
        {
            perror("Memory allocation failed");
            free(pStudents);
            free(pLine);
            fclose(f);
            return EXIT_FAILURE;
        }
        pStudents = temp;
        char name[100];
        int grade;
        if (sscanf(pLine, "%99s %d", name, &grade) == 2) 
        {
            strncpy(pStudents[student_count].name, name, sizeof(pStudents[student_count].name)-1);
            pStudents[student_count].name[sizeof(pStudents[student_count].name)-1] = '\0';
            pStudents[student_count].grade = grade;
            student_count++;
        }
        else 
        {
            fprintf(stderr, "Invalid line format: %s", pLine);
        }
    }
    //cleanup the file
    free(pLine);
    fclose(f);

    //menu or something
    int menuanswer = -1;
    while (menuanswer != 3)
    {
        printf("What do you want to do: 1. Add student 2. Print students 3. Save and quit");
        menuanswer = get_int();
        switch(menuanswer)
        {
            case(1):
                Student * temp = realloc(pStudents, (student_count +1) * sizeof(Student));
                if (temp == NULL)
                {
                    perror("Memory allocation failed");
                    free(pStudents);
                    free(pLine);
                    fclose(f);
                    return EXIT_FAILURE;
                }
                addstudent(pStudents, student_count);
                student_count++;
                break;
            case(2):
                printstudents(pStudents, student_count);
                break;
            case(3):
                saveandquit(pStudents, student_count);
                break;
        }

    }
    free(pStudents);


    return EXIT_SUCCESS;
}

void addstudent(Student pStudents[], int student_count)
{
    int c;
    printf("\nEnter student name: ");
    scanf("%99s", pStudents[student_count].name);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nEnter student grade: ");
    scanf("%d", &pStudents[student_count].grade);
    while ((c = getchar()) != '\n' && c != EOF);
}
void printstudents(Student pStudents[], int student_count)
{
    printf("\nLoaded %d students: \n", student_count);
    for (size_t i = 0; i < student_count; i++) 
    {
        printf("%s: %d\n", pStudents[i].name, pStudents[i].grade);
    }
}
void saveandquit(Student pStudents[], int student_count)
{
    FILE *f = fopen("students.txt", "w");
    if (f == NULL)
    {
        perror("Could not open file");
    }
    else 
    {
        for (size_t i = 0; i < student_count; i++)
        {
            fprintf(f, "%s %d\n",pStudents[i].name,pStudents[i].grade);
        }
        fclose(f);
    }
}

int get_int()
{
    char integer[32];
    size_t idx = 0;
    char c;

    printf("\nInput a number: ");

    while ((c = getchar()) != '\n' && c != EOF && idx < sizeof(integer) - 1)
    {
        //if (isdigit(c) || (c == '-' && idx == 0))
        if ((c >= '0' && c <= '9') || (c == '-' && idx == 0))
        {
            integer[idx++] = c;
        }
    }
    integer[idx] = '\0';
    return atoi(integer);
}
