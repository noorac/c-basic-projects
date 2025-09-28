#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_correct(int num, int guess){
    int cont = 1;
    if (num == guess) {
        printf("Correct, the answer was %d\n", num);
        cont = 0;
    }
    else if (num > guess) {
        printf("Too low!\n");
    }
    else if (num < guess) {
        printf("Too high!\n");
    }
    return cont;
}

int main(int argc, char *argv[])
{
    int guess;
    //initialize randomizer using current timestamp as a seed
    //Prevents from using the seed during compilation i guess?
    srand(time(NULL));
    //generate the random number
    int num = rand() % 100 + 1;
    //to keep while going
    int cont = 1;
    int counter = 0;
    printf("Guess the number(1-100):\n");
    while (cont) {
        scanf("%d", &guess);
        cont = is_correct(num, guess);
        counter++;
    }
    printf("It took you %d tries\n",counter);
    return EXIT_SUCCESS;
}
