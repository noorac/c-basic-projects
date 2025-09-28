/*
 * Define a struct representing a 2D point with x and y as floats
 * Use typedef to give the struct a cleaner name, so you can just write Point instead of struct Point
 * Write a function that takes a Point and returns the distance to the origin
 * In main() define a few points, call the function and print the results */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
    float x;
    float y;
} Point;

float point_distance(Point *p);

int main(int argc, char *argv[])
{
    Point p1 = { 3.2, 2.4};
    printf("Distance to center: %f", point_distance(&p1));

    return EXIT_SUCCESS;
}

float point_distance(Point *p) {
    return sqrt(pow(p->x,p->x)+pow(p->y,p->y));
}
