/* addemup.c -- 几种常见的语句 */

#include <stdio.h>

int main(int argc, char **argv)
{
    int count, sum;

    count = 0;
    sum = 0;
    while (count++ < 20)
    {
        sum = sum + count;
    }
    printf ("sum = %d\n", sum);

    return 0;
}
