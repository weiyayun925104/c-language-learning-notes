// colddays.c -- 找出0摄氏度以下的天数占总天数的百分比

#include <stdio.h>

int main(int argc, char **argv)
{
    const float FREEZING = 0.0f;
    float temperature;
    int cold_days = 0;
    int all_days = 0;

    printf ("Enter the list of daily low temperatures.\n");
    printf ("Use Celsius, and enter q to quit.\n");
    while (scanf ("%f", &temperature) == 1)
    {
        all_days++;
        if (temperature < FREEZING)
        {
            cold_days++;
        }
    }
    if (all_days != 0)
    {
        printf ("%d days total: %.2f%% were below freezing.\n", all_days, 100.0f * ( (float) cold_days / all_days) );
    }
    if (all_days == 0)
    {
        printf ("No data entered!\n");
    }

    return 0;
}
