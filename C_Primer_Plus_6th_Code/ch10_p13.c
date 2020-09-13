#include <stdio.h>

void get_array2d(double array[][5]);
double Compute1(double array[][5], int row_index);
double Compute2(double array[][5]);
double Largest(double array[][5]);
void report_array2d(double array[][5]);

int main(int argc, char **argv)
{
    double array[3][5];

    get_array2d(array);

    report_array2d(array);

    return 0;
}

void get_array2d(double array[][5])
{
    printf("Please enter three sets of five double numbers:\n");
    printf("Please enter the first set:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%lf", &array[0][i]);
    }
    printf("Please enter the second set:\n");
    for (int j = 0; j < 5; j++)
    {
        scanf("%lf", &array[1][j]);
    }
    printf("Please enter the third set:\n");
    for (int k = 0; k < 5; k++)
    {
        scanf("%lf", &array[2][k]);
    }
}

double Compute1(double array[][5], int row_index)
{
    double average = 0.0;
    double sum = 0.0;

    for (int i = 0; i < 5; i++)
    {
        sum += array[row_index][i];
    }

    average = sum / 5;

    return average;
}

double Compute2(double array[][5])
{
    double average = 0.0;
    double sum = 0.0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum += array[i][j];
        }
    }
    average = sum / 15;

    return average;
}

double Largest(double array[][5])
{
    double largest = array[0][0];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (array[i][j] > largest)
            {
                largest = array[i][j];
            }
        }
    }

    return largest;
}

void report_array2d(double array[][5])
{
    for (int i = 0; i < 3; i++)
    {
        printf("The average of the %d set is: %g.\n", i, Compute1(array, i));
    }
    printf("The average of all values is: %g.\n", Compute2(array));

    printf("The largest value among these values is: %g\n", Largest(array));
}
