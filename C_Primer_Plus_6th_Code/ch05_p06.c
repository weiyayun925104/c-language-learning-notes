#include <stdio.h>

int main(int argc, char **argv)
{
    int count, sum, end;

    count = 0;
    sum = 0;
    printf("Please enter the end: ");
    scanf("%d", &end);
    while (count++ < end)
    {
        sum = sum + (count * count);
    }
    printf("sum = %d\n", sum);

    return 0;
}
