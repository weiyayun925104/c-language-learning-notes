/* break.c -- 使用break退出循环 */

#include <stdio.h>

int main(int argc, char **argv)
{
    float length, width;

    printf ("Enter the length of the rectangle: ");
    while ( scanf("%f", &length) == 1 )
    {
        printf ("Length = %.2f\n", length);
        printf ("Enter its width: ");
        if ( scanf("%f", &width) != 1)
        {
            break;
        }
        printf ("width = %.2f\n", width);
        printf ("Area = %.2f\n", length * width);
        printf ("Enter the length of the rectangle: ");
    }
    printf ("Done.\n");

    return 0;
}
