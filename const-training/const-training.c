/*
 * declare a const int variable and try to modify it, see what compiler says
 * write a function that takes a pointer to a const int(e.g. void print_value(const int *p) and tries to modify the value
 * write a function that takes a non-const pointer and modifies the value
 * explain in comments why const is useful*/

#include <stdio.h>
#include <stdlib.h>

const int const_int = 1;

void print_value(const int *p) {
    //gives error: tries to assign read-only location
    //*p = 2;
    printf("%d\n",*p);
}

void print_value2(int *p) {
    *p = 4;
    printf("%d",*p);
}

int main(int argc, char *argv[])
{
    int nonconst_int = 3;
    //gives error: tries to assign read-only variable
    //const_int += 1;
    print_value(&const_int);
    //Gives error that it requires type(const int) and not just int if passing const. and print_value2(int *p)
    print_value2(&nonconst_int);
    
    return EXIT_SUCCESS;
}
