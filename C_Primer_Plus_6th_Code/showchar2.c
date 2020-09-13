#include <stdio.h>

void display(int ch, int rows, int cols);

int main(int argc, char **argv)
{
    int ch;
    int rows, cols;

    printf ("Enter a character and two integers (a newline to quit): \n");
    while ( ( ch = getchar() ) != '\n')
    {
        if ( scanf ("%d %d", &rows, &cols) != 2 )
        {
            break;
        }
        display (ch, rows, cols);
        while ( getchar() != '\n' )
        {
            continue;
        }
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
