/* summing.c -- 根据用户键入的整数求和 */

#include <stdio.h>

int main(int argc, char **argv)
{
    long num;
    long sum = 0L;
    int status;

    printf ("Please enter an integer to be summed (q to quit): ");
    status = scanf ("%ld", &num);
    while (status == 1)
    {
        sum = sum + num;
        printf ("Please enter next integer to be summed (q to quit): ");
        status = scanf ("%ld", &num);
    }
    printf ("Those integers sum to %ld.\n", sum);

    return 0;
}
