/*
 * Asks the user how many lines of input they want to enter, allocates memory for that number of strings using char**
 * for each line: dynamic read the line using fgetc() or getchar(), character by character. Allocate and grow each string with realloc() as you go
 *
 * print all the lines back to the user
 * Free all memory at the end(each string and the outer array)
 *
 * (skip empty lines, and trim newline at the end of each input).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_number_of_lines();
char *get_line();
void print_lines(char **strings, int size);

int main(int argc, char *argv[])
{
    //get number of lines to make
    int number_of_lines = get_number_of_lines();
    //allocate memory and check for failure
    char **strings = malloc(number_of_lines * sizeof(char *));
    if (strings == NULL) {
        perror("\nStrings allocation failed, exiting..\n");
        return EXIT_FAILURE;
    }
    //ask user for input of the strings
    for (int i = 0; i < number_of_lines; i++) {
        strings[i] = get_line();
    }
    //print the lines
    print_lines(strings, number_of_lines);
    //free the memory
    for (int i = 0; i < number_of_lines; i++) {
        free(strings[i]);
    }
    free(strings);
    //formating
    printf("\n\n");
    return EXIT_SUCCESS;
}

int get_number_of_lines() {
    //asks the user for number of lines they want to make
    int number_of_lines;
    printf("\nHow many lines do you want to input: ");
    scanf("%d", &number_of_lines);
    //clear input buffer
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
    return number_of_lines;
}

char *get_line() {
    int ch;
    int capacity = 20;
    int size = 0;
    //allocate the string size and check for failure
    char *string = malloc(capacity * sizeof(char));
    if(string == NULL) {
        perror("\nString allocation failed\n");
        return NULL;
    }
    //get characters from user
    while ((ch = getchar()) != '\n' && ch != EOF) {
        string[size++] = ch;
        //increase size if at capacity, also check for failure of allocation
        if (size == capacity) {
            capacity *= 2;
            char *temp = realloc(string, capacity * sizeof(char));
            if (temp == NULL) {
                free(string);
                perror("\nString allocation failed\n");
                return NULL;
            }
            string=temp;
        }
    }
    //string formatting
    string[size] = '\0';
    return string;
}

void print_lines(char **strings, int size) {
    //loop through the strings
    for (int i = 0; i < size; i++) {
        printf("\nLine %d: %s",i+1,strings[i]);
    }
}
