#include <stdio.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int dep[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
int arr[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

int main(int argc, char **argv)
{
    int desired_time, departure_time, arrival_time, hour, minute;
    int d_hour, d_minute, a_hour, a_minute;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);
    desired_time = hour * 60 + minute;
    find_closest_flight(desired_time, &departure_time, &arrival_time);

    d_hour = departure_time / 60 > 12 ? departure_time / 60 - 12 : departure_time / 60;
    d_minute = departure_time % 60;
    a_hour = arrival_time / 60 > 12 ? arrival_time / 60 - 12 : arrival_time / 60;
    a_minute = arrival_time % 60;


    printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
           d_hour, d_minute, departure_time / 60 > 11 ? 'p' : 'a',
           a_hour, a_minute, arrival_time / 60 > 11 ? 'p' : 'a');

    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    int i;

    for (i = 0; i < 7; i++)
    {
        if (desired_time <= dep[i] + (dep[i + 1] - dep[i]) / 2)
        {
            *departure_time = dep[i];
            *arrival_time = arr[i];

            return ;
        }
    }

    *departure_time = dep[7];
    *arrival_time = arr[7];

    return ;
}
