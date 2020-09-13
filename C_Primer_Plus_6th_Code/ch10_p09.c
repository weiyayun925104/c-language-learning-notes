#include <stdio.h>

#define ROWS 3
#define COLS 5

void copy(int rows, int cols, double target[rows][cols], double source[rows][cols]);
void display(int rows, int cols, double target[rows][cols], double source[rows][cols]);

int main(int argc, char **argv)
{
    double source[ROWS][COLS] = { {1.1, 2.2, 3.3, 4.4, 5.5}, {6.6, 7.7, 8.8, 9.9, 10.10}, {11.11, 12.12, 13.13, 14.14, 15.15} };
    double target[ROWS][COLS];

    copy(ROWS, COLS, target, source);
    display(ROWS, COLS, target, source);

    return 0;
}

void copy(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            target[i][j] = source[i][j];
        }
    }
}

void display(int rows, int cols, double target[rows][cols], double source[rows][cols])
{
    printf("Source array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%5g ", source[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Target array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%5g ", target[i][j]);
        }
        printf("\n");
    }
}
