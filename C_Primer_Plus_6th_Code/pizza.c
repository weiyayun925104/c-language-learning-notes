/* pizza.c -- 在比萨饼程序中使用已定义的常量 */

#include <stdio.h>

#define PI 3.14159

int main(int argc, char **argv)
{
    double area, circum, radius;

    printf ("What is the radius of your pizza? \n");
    scanf ("%lf", &radius);
    area = PI * radius * radius;
    circum = 2.0 * PI * radius;
    printf ("Your basic pizza parameters are as follows: \n");
    printf ("circumference = %.2f, area = %.2f\n", circum, area);

    return 0;
}
