#include <stdio.h>

int main(int argc, char **argv)
{
    int i, j, temp_total, high, low;
    int n[5][5];

    for (i = 0; i < 5; i++)
    {
        printf("Enter quiz grades for student %d: ", i + 1);

        for (j = 0; j < 5; j++)
        {
            scanf("%d", &n[i][j]);
        }
    }

    printf("\n");

    for (i = 0; i < 5; i++)
    {
        printf("\nTotal and average score for student %d: ", i + 1);
        temp_total = 0;
        for (j = 0; j < 5; j++)
        {
            temp_total += n[i][j];
        }
        printf("%d %.2f", temp_total, (double) temp_total / 5);
    }

    printf("\n");

    for (j = 0; j < 5; j++)
    {
        printf("\nAverage, high and low scores for quiz %d: ", j + 1);
        temp_total = 0;
        high = low = n[0][j];

        for (i = 0; i < 5; i++)
        {
            temp_total += n[i][j];
            if (n[i][j] > high)
            {
                high = n[i][j];
            }
            if (n[i][j] < low)
            {
                low = n[i][j];
            }
        }
        printf("%.2f %d %d", (double) temp_total / 5, high, low);
    }

    printf("\n");

    return 0;
}
