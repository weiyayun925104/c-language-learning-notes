#include <stdio.h>
#define ROWS 5

int main(int argc, char **argv)
{
    int row;
    int column;

    for (row = 0; row < ROWS; row++)
    {
        for (column = 0; column <= row; column++)
        {
            printf("$");
        }
        printf("\n");
    }

    return 0;
}
