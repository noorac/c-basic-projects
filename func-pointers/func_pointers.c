/*
 * Define three simple math functions: add, subtract, multipoly each taking two int and returing int
 * Define a function pointer type with typedef for functions that take two ints and return int
 * write a function called compute() that takes two ints and a function pointer, and calls the function on the two values
 * In main() test calling compute(a,b,add) etc and print the results*/

#include <stdio.h>
#include <stdlib.h>

typedef int (*comp)(int a, int b);

int compute(int a, int b, comp f);
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);

int main(int argc, char *argv[])
{
    int a = 2;
    int b = 3;
    comp p_add = add;
    comp p_sub = sub;
    comp p_mul = mul;
    printf("%d + %d = %d\n", a, b, compute(a, b, p_add));
    printf("%d - %d = %d\n", a, b, compute(a, b, p_sub));
    printf("%d * %d = %d\n", a, b, compute(a, b, p_mul));
    return EXIT_SUCCESS;
}
int compute(int a, int b, comp f) {
    return f(a,b);
}
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a*b;
}
