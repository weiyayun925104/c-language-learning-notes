#include <stdio.h>

#define ROWS 6

int main(int argc, char **argv)
{
    int row, count = 0;
    char ch;

    for (row = 0; row < ROWS; row++)
    {
        for (ch = 'A' + count; ch <= 'A' + count + row; ch++)
        {
            printf("%c", ch);
        }
        count += row + 1;
        printf("\n");
    }

    return 0;
}
