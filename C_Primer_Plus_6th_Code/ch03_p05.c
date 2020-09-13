#include <stdio.h>

int main(void)
{
    int age_years;
    long long age_seconds;

    printf("Please enter your age in years: ");
    scanf("%d", &age_years);
    age_seconds = (age_years * 3.156e7);
    printf("Your age in seconds is %lld seconds.\n", age_seconds);

    return 0;
}
