/* showchar1.c -- 有较大I/O问题的程序 */

#include <stdio.h>

void display(int ch, int rows, int cols);

int main(int argc, char **argv)
{
    int ch;
    int rows, cols;

    printf ("Enter a character and two integers (a newline to quit): \n");
    while ( ( ch = getchar() ) != '\n')
    {
        scanf ("%d %d", &rows, &cols);
        display (ch, rows, cols);
        printf ("Enter a character and two integers (a newline to quit): \n");
    }
    printf ("Done!\n");

    return 0;
}
void display(int ch, int rows, int cols)
{
    int row, col;

    for (row = 1; row <= rows; row++)
    {
        for (col = 1; col <= cols; col++)
        {
            putchar(ch);
        }
        putchar('\n');
    }
}
