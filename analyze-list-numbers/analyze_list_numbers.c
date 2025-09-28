/*
 * Analyze a list of numbers
 */
#include <stdio.h>
#include <stdlib.h>

void clear_buffer()
{
    //this function is called to clear the input buffer
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int calculate_sum(int *list, int num)
{
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += list[i];
    }
    return sum;
}

float calculate_average(int num, int sum)
{
    return (float)sum/num;
}

int find_min(int *list, int num)
{
    int min = list[0];
    for (int i = 0; i < num; i++)
    {
        if (min > list[i])
        {
            min = list[i];
        }
    }
    return min;
}

int find_max(int *list, int num)
{
    int max = list[0];
    for (int i = 0; i < num; i++)
    {
        if (max < list[i])
        {
            max = list[i];
        }
    }
    return max;
}

int ask_length()
{
    int num;
    while (1)
    {
        scanf("%d", &num);
        //clear input buffer
        clear_buffer();
        if (num < 1 || num > 100)
        {
            printf("Invalid number, try again between 1 and 100\n");
            continue;
        }
        break;
    }
    return num;
}

int main(int argc, char *argv[])
{
    /*
     * Program will ask user how many numbers they want to enter. 
     * Up to a maximum of 100(so no malloc)
     * Then store those in an array. When finisdhed, prints out
     * the sum of all numbers, then the average, the min and max 
     * values. 
     */
    int list[100];
    int num;

    printf("How many numbers do you want to input?(Max: 100) \n");
    num = ask_length();

    for (int i = 0; i < num; i++)
    {
        printf("Number %d: \n", i+1);
        scanf("%d", &list[i]);
    }

    //prettyfy
    printf("\n\n*****************\n\n");
    //printout list
    printf("Numbers entered: ");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", list[i]);
    }
    
    //nextline
    printf("\n\n");

    //printout sum
    int sum = calculate_sum(list, num);
    printf("Sum of numbers: %d\n", sum);
    //nextline
    printf("\n");
    
    //printout average
    printf("Average of numbers: %.2f\n", calculate_average(num, sum));
    //nextline
    printf("\n");

    //find min 
    printf("Lowest number in list: %d\n", find_min(list, num));
    //nextline
    printf("\n");

    //find max 
    printf("Largest number in list: %d\n", find_max(list, num));
    //nextline
    printf("\n");
    //prettyfy
    printf("*****************");

    //printf to skip the % sign at the end
    printf("\n");
    return EXIT_SUCCESS;
}
