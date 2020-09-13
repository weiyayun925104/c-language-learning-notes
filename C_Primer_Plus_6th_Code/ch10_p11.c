
#include <stdio.h>

#define ROWS 3
#define COLS 5

void display(int array[][COLS], int rows);
void multipytwo(int array[][COLS], int rows);

int main(int argc, char **argv)
{
    int array[ROWS][COLS] = { {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15} };

    display(array, ROWS);
    printf("\n");
    multipytwo(array, ROWS);
    display(array, ROWS);

    return 0;
}

void display(int array[][COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%6d", array[i][j]);
        }
        printf("\n");
    }
}

void multipytwo(int array[][COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            array[i][j] *= 2;
        }
    }
}
