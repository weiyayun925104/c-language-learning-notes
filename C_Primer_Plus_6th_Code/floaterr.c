/* floaterr.c -- ��ʾ������������� */

#include <stdio.h>

int main(int argc, char **argv)
{
    float a, b;
    b = 2.0e20 + 1.0;
    a = b - 2.0e20;
    printf ("%f\n", a);
    return 0;
}
