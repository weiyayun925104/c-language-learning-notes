#include <stdio.h>

#define ARRAY_LEN(x) ( (int) ( sizeof( (x) ) / sizeof( (x)[0] ) ) )

struct flight
{
    int departure;
    int arrival;
};

const struct flight times[] =
{
    {480, 616}, {583,  712}, { 679,  811},  {767,  900},
    {840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438}
};

void print(const struct flight time);

int main(int argc, char **argv)
{
    int user_time, hour, minute;
    int i, length;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);
    user_time = hour * 60 + minute;

    printf("Closest departure time is ");
    length = ARRAY_LEN(times);
    for (i = 0; i < length - 1; i++)
    {
        if (user_time <= ( times[i].departure + (times[i + 1].departure - times[i].departure) / 2 ) )
        {
            print(times[i]);
            return 0;
        }
    }
    print(times[length - 1]);
    return 0;
}

void print(const struct flight time)
{
    int d_hour, d_minute, a_hour, a_minute;

    d_hour = time.departure / 60 > 12 ? time.departure / 60 - 12 : time.departure / 60;
    d_minute = time.departure % 60;
    a_hour = time.arrival / 60 > 12 ? time.arrival / 60 - 12 : time.arrival / 60;
    a_minute = time.arrival % 60;

    printf("%d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
           d_hour, d_minute, time.departure / 60 > 11 ? 'p' : 'a',
           a_hour, a_minute, time.arrival / 60 > 11 ? 'p' : 'a');
}
