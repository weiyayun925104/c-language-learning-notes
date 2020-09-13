/* for_cube.c -- 使用for循环创建一个立方表 */

#include <stdio.h>

int main(int argc, char **argv)
{
    int num;

    printf ("     n     n cubed\n");
    for (num = 1; num <= 6; num++)
    {
        printf ("%6d %6d\n", num, num * num * num);
    }

    return 0;
}
