#include <stdio.h>

int main(int argc, char **argv)
{
    int n, m;

    printf("Please enter an integer: ");
    scanf("%d", &n);
    m = n + 10;
    while (n <= m)
    {
        printf("%d\n", n);
        n++;
    }

    return 0;
}
