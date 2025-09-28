/*
 * 1. Asks the user how many numbers they want to input 
 * 2. allocates enough memory dynamically using malloc 
 * 3. asks for each number and stores them
 * 4. computes and prints the average of the numbers 
 * 5. frees the memory after use 
 */ 

#include <stdio.h>
#include <stdlib.h>

int get_int();
float get_average(int pArray[], int user_number);

int main(int argc, char *argv[])
{
    int user_number;
    float average_number;
    user_number = get_int();
    int *pArray = malloc(user_number*sizeof(int));
    if (pArray == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < user_number; i++)
    {
        pArray[i] = get_int();
    }
    average_number = get_average(pArray, user_number);
    printf("\n\nYou  entered %d numbers, the average is: %.2f", user_number, average_number);


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

float get_average(int pArray[], int user_number)
{
    float average_number = 0.0;
    for (int i = 0; i < user_number; i++)
    {
        average_number += pArray[i];
    }
    return average_number/(float)user_number;
}
