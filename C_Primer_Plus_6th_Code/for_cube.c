/* for_cube.c -- ʹ��forѭ������һ�������� */

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
