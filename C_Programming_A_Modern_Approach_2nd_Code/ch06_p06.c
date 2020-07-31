#include <stdio.h>

int main(int argc, char **argv)
{
    int n, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 1; i * i <= n; i++)
    {
        if ((i * i) % 2 != 0)
        {
            continue;
        }
        printf("%d\n", i * i);
    }

    return 0;
}
