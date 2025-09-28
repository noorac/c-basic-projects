#include <stdio.h>
#include <stdlib.h>

double add(double a, double b) {
    return (a+b);
}

double subtract(double a, double b) {
    return (a-b);
}

double multiply(double a, double b) {
    return (a*b);
}

double divide(double a, double b) {
    double sum;
    if (b == 0.0) {
        printf("Cannot divide by zero\n"); 
        return 0;
    }
    else {
        return (a/b);
    }
}

int main(int argc, char *argv[])
{
    double a, b;
    char operator;

    while (1) {
        printf("Write math expression(e.g. 4 + 3) or 'q' to quit: ");
        int input = scanf("%lf %c %lf", &a, &operator, &b);

        if (input != 3) {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /*
                    * Clear input buffer. If the statement end
                    * with a q or Q it will be caught by the 
                    * quitting operation. Don't get hung up on 
                    * this stuff. Can be understod better later.
                    *
                    */
                operator = ch;
            }
            if (operator == 'q' || operator == 'Q') break;
            printf("Invalid argument. Try again.\n");
            continue;
        }
        switch (operator) {
            case '+':
                printf("Add: %lf\n", add(a,b));
                break;
            case '-':
                printf("Subract: %lf\n",subtract(a,b));
                break;
            case '*':
                printf("Multiply: %lf\n", multiply(a,b));
                break;
            case '/':
                printf("Divide: %lf\n",divide(a,b));
                break;
            default:
                printf("Unknown operator %c\n", operator);
        }
    }
    return EXIT_SUCCESS;
}
