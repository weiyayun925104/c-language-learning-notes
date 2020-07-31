#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};

char digits[4][MAX_DIGITS * 4];

const int segment_grid[7][2] = {{0, 1},
    {1, 2},
    {2, 2},
    {2, 1},
    {2, 0},
    {1, 0},
    {1, 1}
};

int main(int argc, char **argv)
{
    char c;
    int position = 0;

    clear_digits_array();

    printf("Enter a number: ");
    while ( (c = getchar()) != '\n' )
    {
        if ( isdigit(c) )
        {
            process_digit(c - '0', position);
            position += 4;
        }
    }
    print_digits_array();

    return 0;
}

void clear_digits_array(void)
{
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < MAX_DIGITS * 4; j++)
        {
            digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position)
{
    int i, row, col;

    for (i = 0; i < 7; i++)
    {
        if (segments[digit][i])
        {
            row = segment_grid[i][0];
            col = segment_grid[i][1] + position;
            digits[row][col] = i % 3 == 0 ? '_' : '|';
        }
    }
}

void print_digits_array(void)
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < MAX_DIGITS * 4; j++)
        {
            putchar(digits[i][j]);
        }
        printf("\n");
    }
}
