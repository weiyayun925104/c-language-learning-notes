#include <stdio.h>

int main(int argc, char **argv)
{
    const int dpw = 7;   // days_per_week
    int n, days, weeks;
    printf("Please enter the number of days: ");
    scanf("%d", &n);
    while (n > 0)
    {
        weeks = n / dpw;
        days = n % dpw;
        printf("%d days are %d weeks, %d days.\n", n, weeks, days);
        printf("Please enter another number of days (0 to quit): ");
        scanf("%d", &n);
    }
    printf("Done!\n");

    return 0;
}
