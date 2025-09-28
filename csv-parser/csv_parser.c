/* Open a file named students.csv.
 * Read the file line by line using fgets
 * skip the header line
 * For each line: split it on commas using strtok, convert the age and grade fields using atoi and atof
 * store the values in a struct Student, print all parsed students at the end*/

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

//MAIN
int main(int argc, char *argv[])
{
    const char *filename = "students.csv";
    char *full_path = get_filepath(argv, filename);
    if (!full_path) {
        return EXIT_FAILURE;
    }
    //open the file
    char line[MAX_LINE_LENGTH];
    char *lines[MAX_LINES];
    int line_count = 0;
    FILE *f = fopen(full_path, "r");
    //read the lines and save them in lines
    while(fgets(line,sizeof(line), f)) {
        if (line_count == 0) {
            line_count++;
            continue;
        }
        if( line_count >= MAX_LINES) break;
        lines[line_count-1] = strdup(line);
        line_count++;
    }
    fclose(f);
    // create structs
    Student students[MAX_LINES];
    // strip lines
    for (int i = 0; i < line_count-1;i++) {
        char *token = strtok(lines[i],",");
        if(token == NULL) return EXIT_FAILURE;
        strcpy(students[i].name, token);
        token = strtok(NULL,",");
        if(token == NULL) return EXIT_FAILURE;
        students[i].age = atoi(token);
        token = strtok(NULL,",");
        if(token == NULL) return EXIT_FAILURE;
        students[i].grade = atof(token);
    }
    //print the structs
    printf("\n\n");//formatting
    for(int i = 0; i < line_count -1; i++) {
        printf("Name: %s | Age: %d | Grade: %.1f\n",students[i].name,students[i].age, students[i].grade);
    }
    //cleanup
    free(full_path);
    printf("\nExiting successfully..\n");
    return EXIT_SUCCESS;
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
    printf("Built full path: %s", full_path);
    return full_path;
}
