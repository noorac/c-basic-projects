/* Define a struct Student, create an array of 3 student manually in the program(hardcoded)
 * Save the student array to a file named students.dat using fwrite. Clears the array(set all elements to zero) and try to print
 * Load the student data back from the file using fread. Prints all student info to confirm it matches what was written*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[100];
    int age;
    float grade;
};

void print_students(struct Student *students, int number_of_students);

int main(int argc, char *argv[])
{
    //initialize the array of students
    const int number_of_students = 3;
    struct Student students[] = {
        { "Kjetil", 38, 3.8 },
        { "Alessia", 37, 4.0 },
        { "Nuukie", 3, 1.2 }
    };
    //print the array once
    printf("\nOriginal:");
    print_students(students, number_of_students);
    printf("\n---");
    //write to file
    FILE *file = fopen("students.dat","wb");
    if (file == NULL) {
        perror("Failed to open file..");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < number_of_students; i++) {
        fwrite(&students[i], sizeof(struct Student), 1, file);
    }
    fclose(file);
    //clear out the array
    for (int i = 0; i < number_of_students; i++) {
        strcpy(students[i].name , "N/A");
        students[i].age = 0;
        students[i].grade = 0.0;
    }
    //print of the array
    printf("\nWiped");
    print_students(students, number_of_students);
    printf("\n---");
    //read from file
    file = fopen("students.dat", "rb");
    if (file == NULL) {
        perror("Failed to open file..");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < number_of_students; i++) {
        fread(&students[i], sizeof(struct Student), 1, file);
    }
    //print of the array 
    printf("\nRead:");
    print_students(students, number_of_students);

    return EXIT_SUCCESS;
}

void print_students(struct Student *students, int number_of_students) {

    for (int i = 0; i < number_of_students; i++) {
        printf("\nNAME: %s, AGE: %d, GRADE: %.1f",students[i].name,students[i].age,students[i].grade);
    }

    return;
}
