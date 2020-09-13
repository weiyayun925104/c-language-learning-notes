#include <stdio.h>

void copy_arr(double target[], double source[], int number);

int main(int argc, char **argv)
{
    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double target[3];
    copy_arr(target, &source[2], 3);

    for (int x = 0; x < 3; x++)
    {
        printf("%g ", target[x]);
    }
    printf("\n");

    return 0;
}

void copy_arr(double target[], double source[], int number)
{
    for (int i = 0; i < number; i++)
    {
        target[i] = source[i];
    }
}
