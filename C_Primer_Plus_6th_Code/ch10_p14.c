#include <stdio.h>

#define ROWS 3
#define COLS 5

void get_array2d(int rows, int cols, double array[rows][cols]);
double Compute1(int rows, int cols, double array[rows][cols], int row_index);
double Compute2(int rows, int cols, double array[rows][cols]);
double Largest(int rows, int cols, double array[rows][cols]);
void report_array2d(int rows, int cols, double array[rows][cols]);

int main(int argc, char **argv)
{
    double array[ROWS][COLS];

    get_array2d(ROWS, COLS, array);

    report_array2d(ROWS, COLS, array);

    return 0;
}

void get_array2d(int rows, int cols, double array[rows][cols])
{
    printf("Please enter three sets of five double numbers:\n");
    printf("Please enter the first set:\n");
    for (int i = 0; i < COLS; i++)
    {
        scanf("%lf", &array[0][i]);
    }
    printf("Please enter the second set:\n");
    for (int j = 0; j < COLS; j++)
    {
        scanf("%lf", &array[1][j]);
    }
    printf("Please enter the third set:\n");
    for (int k = 0; k < COLS; k++)
    {
        scanf("%lf", &array[2][k]);
    }
}

double Compute1(int rows, int cols, double array[rows][cols], int row_index)
{
    double average = 0.0;
    double sum = 0.0;

    for (int i = 0; i < COLS; i++)
    {
        sum += array[row_index][i];
    }

    average = sum / COLS;

    return average;
}

double Compute2(int rows, int cols, double array[rows][cols])
{
    double average = 0.0;
    double sum = 0.0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            sum += array[i][j];
        }
    }
    average = sum / (ROWS * COLS);

    return average;
}

double Largest(int rows, int cols, double array[rows][cols])
{
    double largest = array[0][0];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (array[i][j] > largest)
            {
                largest = array[i][j];
            }
        }
    }

    return largest;
}

void report_array2d(int rows, int cols, double array[rows][cols])
{
    for (int i = 0; i < ROWS; i++)
    {
        printf("The average of the %d set is: %g.\n", i, Compute1(rows, cols, array, i));
    }
    printf("The average of all values is: %g.\n", Compute2(rows, cols, array));

    printf("The largest value among these values is: %g\n", Largest(rows, cols, array));
}
