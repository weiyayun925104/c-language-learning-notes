#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define MAX_TIMES 100
#define MAX_LEN 255

struct deparr
{
    int departure;
    int arrival;
};

int compare_deparrs(const void *a, const void *b);

int main(int argc, char **argv)
{
    FILE *fp;
    char line[MAX_LEN];
    int i, hour, min, flights, user_time, dep_hr, dep_min, arr_hr, arr_min;
    struct deparr deparrs[MAX_TIMES];

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s flights_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ( ( fp = fopen(argv[1], "r") ) == NULL )
    {
        fprintf(stderr, "Error: file %s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    i = 0;
    while ( read_line_file(line, MAX_LEN, fp) != 0 )
    {
        sscanf(line, "%d:%d %d:%d", &dep_hr, &dep_min, &arr_hr, &arr_min);
        deparrs[i].departure = (dep_hr * 60) + dep_min;
        deparrs[i].arrival = (arr_hr * 60) + arr_min;
        i++;
        if (i == MAX_TIMES)
        {
            fprintf(stderr, "Error: file %s too long, using first %d listings\n", argv[1], MAX_TIMES);
            break;
        }
    }
    flights = i;
    fclose(fp);

    qsort(deparrs, flights, sizeof(struct deparr), compare_deparrs);

    printf("Enter departure time in 24-hour format (HH:mm): ");
    scanf("%d :%d", &hour, &min);
    user_time = (60 * hour) + min;

    for (i = 0; i < flights - 1; i++)
    {
        if ( user_time < deparrs[i].departure + ( deparrs[i + 1].departure - deparrs[i].departure ) / 2 )
        {
            break;
        }
    }

    int departure_time, arrival_time;
    int d_hour, d_minute, a_hour, a_minute;

    departure_time = deparrs[i].departure;
    arrival_time = deparrs[i].arrival;

    d_hour = departure_time / 60 > 12 ? departure_time / 60 - 12 : departure_time / 60;
    d_minute = departure_time % 60;
    a_hour = arrival_time / 60 > 12 ? arrival_time / 60 - 12 : arrival_time / 60;
    a_minute = arrival_time % 60;

    printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
           d_hour, d_minute, departure_time / 60 > 11 ? 'p' : 'a',
           a_hour, a_minute, arrival_time / 60 > 11 ? 'p' : 'a');

    exit(EXIT_SUCCESS);
}

int compare_deparrs (const void *p, const void *q)
{
    if ( ( (struct deparr *)p)->departure < ( (struct deparr *)q)->departure )
    {
        return -1;
    }
    else if ( ( (struct deparr *)p)->departure == ( (struct deparr *)q)->departure )
    {
        return 0;
    }

    return 1;
}
