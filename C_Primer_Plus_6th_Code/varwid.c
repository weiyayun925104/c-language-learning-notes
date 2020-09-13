/* varwid.c -- 使用变宽输出字段 */

#include <stdio.h>

int main(int argc, char **argv)
{
    int width, precision;
    int number = 256;
    double weight = 242.5;

    printf ("Enter a field width: ");
    scanf ("%d", &width);
    printf ("The number is: %*d\n", width, number);
    printf ("Now enter a width and a precision: ");
    scanf ("%d %d", &width, &precision);
    printf ("Weight = %*.*f\n", width, precision, weight);
    printf ("Done!\n");

    return 0;
}
