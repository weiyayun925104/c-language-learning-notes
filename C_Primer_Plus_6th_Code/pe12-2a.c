#include <stdio.h>
#include "pe12-2a.h"

static int the_mode;
static int distance;
static double fuel;

void set_mode(int mode)
{
    if (mode == 1)
    {
        the_mode = 1;
    }
    else if (mode == 0)
    {
        the_mode = 0;
    }
    else
    {
        if(the_mode == 0)
        {
            printf("Invalid mode specified. Mode %d(metric) used.\n", the_mode);
        }
        else
        {
            printf("Invalid mode specified. Mode %d(US) used.\n", the_mode);
        }
    }
}

void get_info()
{
    if (the_mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%d", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%d", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
    }
}

void show_info()
{
    if (the_mode == 0)
    {
        printf("Fuel consumption is %g liters per 100 km.\n", fuel * 100.0 / (double) distance);
    }
    else
    {
        printf("Fuel consumption is %g miles per gallon.\n",  (double) distance / fuel);
    }
}
