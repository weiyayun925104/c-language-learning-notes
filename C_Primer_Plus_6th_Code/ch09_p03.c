#include <stdio.h>

void function(char ch, int col, int row);

int main(int argc, char **argv)
{
    char ch;
    int col, row;

    printf("Please enter the character: ");
    ch = getchar();
    printf("Please enter the number of columns and the number of rows: ");
    scanf("%d %d", &col, &row);
    function(ch, col, row);

    return 0;
}

void function(char ch, int col, int row)
{
    int c, r;

    for (r = 0; r < row; r++)
    {
        for (c = 0; c < col; c++)
        {
            putchar(ch);
        }
        printf("\n");
    }
}
