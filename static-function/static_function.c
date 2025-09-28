/*
 * Program that calls a function next_id() that keeps
 * track of how many times it has been called using static
 */

#include <stdio.h>
#include <stdlib.h>

int next_id();

int main(int argc, char *argv[])
{
    for (int i = 0; i< 5; i++) {
        printf("\nCounter returns: %d",next_id());
    }
    return EXIT_SUCCESS;
}

int next_id() {
    static int count = 0;
    count++;
    return count;
}
