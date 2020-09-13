#include <stdio.h>

int main(int argc, char **argv)
{
    int i, n, sign = 1;
    double answer1 = 0.0, answer2 = 0.0;

    printf("Please enter the number of terms: ");
    scanf("%d", &n);
    while (n > 0)
    {
        for (i = 1; i <= n; i++)
        {
            answer1 += (1.0 / (double) i);
            answer2 += (1.0 / (double) i) * sign;
            sign = -sign;
        }
        printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... 1.0/%d.0 = %f\n", n, answer1);
        printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... 1.0/%d.0 = %f\n", n, answer2);
        answer1 = 0.0;
        answer2 = 0.0;
        printf("Please enter the number of terms (zero or negative to terminate): ");
        scanf("%d", &n);
    }
    printf("Done!\n");

    return 0;
}
