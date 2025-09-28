/* Error handling with errno and perror() 
 * Try to open a file (filename passed as a command line argument)
 * if the file opens successfully, prints "File opened successfully" and close it
 * if opening fails, prints an error message using perror() with a custom prefix
 * returns exit status 0 on success, 1 on failure */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 2) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            perror("Failed opening file");
            exit(EXIT_FAILURE);
        }
        else {
            printf("File opened successfully..");
            fclose(f);
        }
    }
    else {
        printf("No argument given for filename.. exiting");
    }
    return EXIT_SUCCESS;
}

