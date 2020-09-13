// vararr2d.c -- 使用变长数组的函数

#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d (int rows, int cols, int ar[rows][cols]);

int main(int argc, char **argv)
{
    int i, j;
    int rs = 3;
    int cs = 10;
    int junk[ROWS][COLS] = 
    {
        {2, 4, 6, 8},
        {3, 5, 7, 9},
        {12, 10, 8, 6}
    };
    int morejunk[ROWS-1][COLS + 2] = 
    {
        {20, 30, 40, 50, 60, 70}, 
        {5, 6, 7, 8, 9, 10}
    };

    int varr[rs][cs];

    for (i = 0; i < rs; i++)
    {
        for (j = 0; j < cs; j++)
        {
            varr[i][j] = (i * j) + j;
        }
    }
    printf ("3x4 array\n");
    printf ("Sum of all elements = %d\n", sum2d (ROWS, COLS, junk) );
    printf ("2x6 array\n");
    printf ("Sum of all elements = %d\n", sum2d (ROWS - 1, COLS + 2, morejunk) );
    printf ("%dx%d array\n", rs, cs);
    printf ("Sum of all elements = %d\n", sum2d (rs, cs, varr) );

    return 0;
}
int sum2d (int rows, int cols, int ar[rows][cols])
{
    int row, col, total = 0;

    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
        {
            total += ar[row][col];
        }
    }

    return total;
}
