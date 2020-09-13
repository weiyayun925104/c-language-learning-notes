#include <stdio.h>

int main(int argc, char **argv)
{
    long long ll, ul, sum, i;

    printf("Enter lower and upper integer limits: ");
    scanf("%lld %lld", &ll, &ul);
    while (ll <= ul)
    {
        sum = 0;
        for (i = ll; i <= ul; i++)
        {
            sum += i * i;
        }
        printf("The sum of the squares is %lld\n", sum);
        printf("Enter lower and upper integer limits: ");
        scanf("%lld %lld", &ll, &ul);
    }

    printf("Done!\n");

    return 0;
}
