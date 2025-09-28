/*
 * Dynamically builds a list of integersx entered by the user
 * The user can enter as many numbers as they want - entering -1 stops the input
 * The program should grow the array using realloc every time the array fills up
 * At the end, print the number values and their average
 */

#include <stdio.h>
#include <stdlib.h>

//constants
const int EXIT_CODE = -1;
//prototype functions
int get_int();

int main(int argc, char *argv[])
{
    //create intitial array
    int *pArray = (int*) malloc(0 * sizeof(int));
    //size of the array
    size_t pArray_l = 0;
    //initialize user_input
    int user_input;
    printf("\n(-1 exits the program): ");

    if (pArray == NULL)
    {
        printf("Failed to create array, exiting..\n");
        return EXIT_FAILURE;
    }

    do {
        //get user input, add it to pArray, if input is -1
        //we stop the loop.
        user_input = get_int();
        if (user_input != EXIT_CODE)
        {
            pArray = (int*) realloc(pArray, (pArray_l + 1) * sizeof(int));
            pArray_l++;
            pArray[pArray_l-1] = user_input;
            if (pArray == NULL)
            {
                printf("Failed to create array, exiting..\n");
                return EXIT_FAILURE;
            }
        }

    }while (user_input != EXIT_CODE);

    //printout all numbers in array
    //also sum them all in the forloop to calc 
    //average later
    printf("\nAll numbers: ");
    int sum = 0;
    for (int i = 0; i < pArray_l; i++)
    {
        printf("%d ",pArray[i]);
        sum += pArray[i];
    }
    //find average
    printf("\nAverage: %.2f", (float)sum/(float)pArray_l);

    free(pArray);
    return EXIT_SUCCESS;
}

int get_int()
{
    char integer[32];
    size_t idx = 0;
    char c;

    printf("\nInput a number: ");

    while ((c = getchar()) != '\n' && c != EOF && idx < sizeof(integer) - 1)
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
