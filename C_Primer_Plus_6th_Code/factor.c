// factor.c -- 使用循环和递归计算阶乘

#include <stdio.h>

long fact (int n);
long rfact (int n);

int main(int argc, char **argv)
{
    int num;

    printf ("This program calculates factorials.\n");
    printf ("Enter a value in the range 0-12 (q to quit) : \n");
    while ( scanf ("%d", &num) == 1)
    {
        if (num < 0)
        {
            printf ("No negative numbers, please.\n");
        }
        else if (num > 12)
        {
            printf ("Keep input under 13.\n");
        }
        else
        {
            printf ("loop: %d factorial = %ld\n", num, fact (num) );
            printf ("recursion: %d factorial = %ld\n", num, rfact (num) );
        }
        printf ("Enter a value in the range 0-12 (q to quit) : \n");
    }
    printf ("Done.\n");

    return 0;
}
long fact (int n)
{
    long ret = 1;

    for (; n > 1; n--)
    {
        ret *= n;
    }

    return ret;
}
long rfact (int n)
{
    long ret;

    if (n > 0)
    {
        ret = n * rfact (n-1);
    }
    else
    {
        ret = 1;
    }

    return ret;
}
