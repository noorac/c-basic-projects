/*main.c*/

/*
 * create two .c files main.c and helper.c 
 * in helper.c define a static int counter = 0; and a function increment_counter() that returns ++counter
 * int main.c call that function a few times and rpint the result.
 * tryu to access counter directly from main.c see what error we get
 * remove the static keyword observe change in linker behavior*/

#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int main(int argc, char *argv[])
{
    for (int i = 0; i < 5; i++) {
        printf("\nCounter: %d",increment_counter());
    }
    //throws error because undecleared. Works if #include "helper.c" though, but it is not good code apparently.
    int a = counter;
    printf("\n\na: %d", a);
    return EXIT_SUCCESS;
}
