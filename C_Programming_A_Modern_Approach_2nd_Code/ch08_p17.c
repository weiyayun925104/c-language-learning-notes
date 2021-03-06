#include <stdio.h>

int main(int argc, char **argv)
{
    int count, n, x, y, x_last, y_last;


    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    int square[n][n];

    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n; y++)
        {
            square[x][y] = 0;
        }
    }

    x = 0;
    y = n / 2;
    square[x][y] = 1;

    count = 2;
    while (count <= n * n)
    {

        x_last = x;
        y_last = y;

        if (x_last - 1 < 0)
        {
            x = n - 1;
        }
        else
        {
            x = x_last - 1;
        }
        if (y_last + 1 >= n)
        {
            y = 0;
        }
        else
        {
            y = y_last + 1;
        }

        if (square[x][y] == 0)
        {
            square[x][y] = count++;
        }
        else
        {
            if (x_last + 1 >= n)
            {
                square[x = 0][y = y_last] = count++;
            }
            else
            {
                square[x = x_last + 1][y = y_last] = count++;
            }
        }
    }

    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n; y++)
        {
            printf("%4d", square[x][y]);
        }
        printf("\n");
    }

    return 0;
}
