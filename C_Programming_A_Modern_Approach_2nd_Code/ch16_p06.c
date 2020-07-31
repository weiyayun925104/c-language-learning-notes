#include <stdio.h>

struct date
{
    int year;
    int month;
    int day;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(int argc, char **argv)
{
    struct date d1, d2;
    int comparison;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d /%d /%d", &d1.month, &d1.day, &d1.year);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d /%d /%d", &d2.month, &d2.day, &d2.year);

    comparison = compare_dates(d1, d2);
    if (comparison < 0)
    {
        printf("%d/%d/%d comes before %d/%d/%d\n",
               d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
    }
    else if (comparison > 0)
    {
        printf("%d/%d/%d comes before %d/%d/%d\n",
               d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
    }
    else
    {
        printf("%d/%d/%d and %d/%d/%d are equal\n",
               d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
    }

    return 0;
}
int day_of_year(struct date d)
{
    int res = 0, i;
    const int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.month > 2 && ( (d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0 ) )
    {
        res++;
    }
    for (i = 1; i < d.month; i++)
    {
        res += days_month[i - 1];
    }
    res += d.day;
    return res;
}
int compare_dates(struct date d1, struct date d2)
{
    if(d1.year < d2.year)
    {
        return -1;
    }
    else if(d1.year > d2.year)
    {
        return 1;
    }
    if(d1.month < d2.month)
    {
        return -1;
    }
    else if(d1.month > d2.month)
    {
        return 1;
    }
    if(d1.day < d2.day)
    {
        return -1;
    }
    else if(d1.day > d2.day)
    {
        return 1;
    }
    return 0;
}
