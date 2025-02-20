#include <stdio.h>

int calculator(int a, int b) {
    int sum = a + b;
    return sum;
}

int main () {
    int a = 1;
    int b = 1;
    printf("Sum: %d",calculator(a,b));

    return 0;
}
