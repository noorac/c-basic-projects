/*
 * Takes arguments from the command line. Treats the first argument as a name, and second as a number
 * prints a greeting + first argument number amount of times. if arguments are missing or wrong, print 
 * an error with usage hints;*/

#include <stdio.h>
#include <stdlib.h>
//comment
//
int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("\nUsage: programname <name> <integer>, where name is a string, and integer is number of times to be print greeting");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < atoi(argv[2]); i++) {
        printf("Hello, %s\n", argv[1]);
    }
    return EXIT_SUCCESS;
}
