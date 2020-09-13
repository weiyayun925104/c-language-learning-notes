#include <stdio.h>

#define MIN_PER_HOUR 60

int main(int argc, char **argv)
{
    int tim;   // time_in_minutes
    int h;   // hours
    int m;   // minutes

    printf("Please enter the time to convert in minutes: ");
    scanf("%d", &tim);
    while (tim > 0)
    {
        h = tim / MIN_PER_HOUR;
        m = tim % MIN_PER_HOUR;
        printf("%d minutes equals to %d hours and %d minutes.\n", tim, h, m);
        printf("Please enter another time (0 to quit): ");
        scanf("%d", &tim);
    }
    printf("Done!\n");

    return 0;
}
