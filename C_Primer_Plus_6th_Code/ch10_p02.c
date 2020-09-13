
#include <stdio.h>

void copy_arr (double target[], double source[], int number);
void copy_ptr (double target[], double source[], int number);
void copy_ptrs (double target[], double source[], double *f_source);

int main(int argc, char **argv)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);

    for (int x = 0; x < 5; x++)
    {
        printf("%.2f ", target1[x]);
    }
    printf("\n");

    for (int y = 0; y < 5; y++)
    {
        printf("%.2f ", target2[y]);
    }
    printf("\n");

    for (int z = 0; z < 5; z++)
    {
        printf("%.2f ", target3[z]);
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

void copy_ptr(double target[], double source[], int number)
{
    for (int j = 0; j < number; j++)
    {
        *(target + j) = *(source + j);
    }
}

void copy_ptrs(double target[], double source[], double *f_source)
{
    double *k;
    int i = 0;
    for (k = source, i = 0; k < f_source; k++, i++)
    {
        *(target + i) = *(source + i);
    }
}
