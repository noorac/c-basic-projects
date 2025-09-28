/*
 * Asks the user to input two integers.
 * Pass the adresses to a function swap
 * and swaps them. prints the before and after values
 */

#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>

int get_int()
{
    char integer[255];
    int idx = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF && idx < 254)
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

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[])
{
    int a;
    int b;
    printf("\nType the first integer: ");
    a = get_int();
    printf("\nType the second integer: ");
    b = get_int();
    //decor
    printf("\n*****************");
    printf("\nYour first integer is: %d", a);
    printf("\nYour second integer is: %d", b);
    //decor
    printf("\n*****************");
    swap(&a, &b);
    printf("\nNow they are swapped!");
    printf("\nYour first integer is: %d", a);
    printf("\nYour second integer is: %d", b);
    //decor
    printf("\n*****************");
    return EXIT_SUCCESS;
}
