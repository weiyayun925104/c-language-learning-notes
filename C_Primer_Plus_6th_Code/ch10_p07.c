#include <stdio.h>

void copy_ptr(double target[], double source[], int number);

int main(int argc, char **argv)
{
    double source[2][3] = { {1.1, 2.2, 3.3}, {4.4, 5.5, 6.6} };
    double target[2][3];
    for (int i = 0; i < 2; i++)
    {
        copy_ptr(target[i], source[i], 3);
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%5g ", target[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void copy_ptr(double target[], double source[], int number)
{
    for (int j = 0; j < number; j++)
    {
        *(target + j) = *(source + j);
    }
}
