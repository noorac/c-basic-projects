/* Open and read the entire JSON file into a buffer
 * Parse the buffer to identify each student object(between { and }
 * Extract the values of name, age and grade fields as strings
 * Convert and store them in your Student struct 
 * print all structs */

//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>

//STRUCT
typedef struct Student {
    char name[100];
    int age;
    float grade;
} Student;

//MACROS
#define MAX_LINES 4
#define MAX_LINE_LENGTH 100

//FUNCTION PROTOTYPES
char *get_filepath(char *argv[], const char *filename);
Student *create_student(char *student_str);

//MAIN
int main(int argc, char *argv[])
{
    const char *filename = "students.json";
    char *full_path = get_filepath(argv, filename);
    if (!full_path) {
        return EXIT_FAILURE;
    }
    //open the file and read
    FILE *f = fopen(full_path, "r");
    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    rewind(f);
    char *json_text = malloc(filesize + 1);
    if(!json_text) {
        perror("Malloc failed..Exiting");
        fclose(f);
        free(full_path);
        return EXIT_FAILURE;
    }
    size_t read_size = fread(json_text, 1, filesize, f);
    if (read_size != filesize) {
        perror("Failed to read whole file.. Exiting");
        free(json_text);
        fclose(f);
        free(full_path);
        return EXIT_FAILURE;
    }
    json_text[filesize] = '\0';
    fclose(f);
    // parse the string
    Student *students[MAX_LINES];
    int student_count = 0;
    char *start = strstr(json_text, "{");
    while (start) {
        char *end = strstr(start, "}");
        if (!end) break;

        int len = end - start + 1;
        char student_str[len + 1];
        strncpy(student_str, start, len);
        student_str[len] = '\0';

        students[student_count] = create_student(student_str);
        student_count++;
        start = strstr(end+1,"{");
    }
    //print the structs
    printf("\n\n");//formatting
    for(int i = 0; i < student_count ; i++) {
        printf("Name: %s | Age: %d | Grade: %.1f\n",students[i]->name,students[i]->age, students[i]->grade);
    }
    //cleanup
    for (int i = 0; i < student_count; i++) {
        free(students[i]);
    }
    free(full_path);
    printf("\nExiting successfully..\n");
    return EXIT_SUCCESS;
}
//CREATE STUDENT
Student *create_student(char *student_str) {
    Student *student = malloc(sizeof(Student));
    if (!student) {
        perror("Malloc failure");
        exit(EXIT_FAILURE);
    }
    char *name_pos = strstr(student_str, "\"name\"");
    if (name_pos) {
        sscanf(name_pos, "\"name\" : \"%[^\"]\"", student->name);
    }
    char *age_pos = strstr(student_str, "\"age\"");
    if (age_pos) {
        sscanf(age_pos, "\"age\" : %d", &(student->age));
    }
    char *grade_pos = strstr(student_str, "\"grade\"");
    if (grade_pos) {
        sscanf(grade_pos, "\"grade\" : %f", &(student->grade));
    }
    printf("\nBuilt student\n");

    return student;
}

//GET FILEPATH
char *get_filepath(char *argv[], const char *filename) {
    char *exec_path = realpath(argv[0], NULL);
    if (!exec_path) {
        perror("Realpath");
        return NULL;
    }
    char *exec_dir = dirname(exec_path);
    size_t len = strlen(exec_dir) + strlen(filename) + 2; // we add / and '\0'
    char *full_path = malloc(len);
    if (!full_path) {
        perror("Malloc failure..");
        free(exec_path);
        return NULL;
    }
    snprintf(full_path, len, "%s/%s",exec_dir,filename);
    free(exec_path);
    printf("Built full path: %s\n\n", full_path);
    return full_path;
}
