// parta.c -- 不同的存储类别

#include <stdio.h>

void report_count(void);
void accumulate (int k);

int count = 0;

int main(int argc, char **argv)
{
    int value;
    int  ret;
    register int i;

    printf ("Enter a positive integer: ");
    while ( ( ret = scanf ("%d", &value) ) == 1 && value > 0)
    {
        ++count;
        for (i = value; i >= 0; i--)
        {
            accumulate (i);
        }
       printf ("Enter a positive integer: ");
    }
    report_count();

    return 0;
}
void report_count(void)
{
    printf ("Loop executed %d times\n", count);
}
