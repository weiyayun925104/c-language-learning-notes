// when.c -- ��ʱ�˳�ѭ��

#include <stdio.h>

int main(int argc, char **argv)
{
    int n = 5;

    while (n < 7)
    {
        printf ("n = %d\n", n);
        n++;
        printf ("Now n = %d\n", n);
    }
    printf ("The loop has finished.\n");

     return 0;
}
