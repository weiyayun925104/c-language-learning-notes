#include <stdio.h>

int main(void)
{
    int toes = 10;
    int toes_twice;
    int toes_squared;

    toes_twice = 2 * toes;
    toes_squared = toes * toes;

    printf("The value of toes is %d\n", toes);
    printf("The value of twice toes is %d\n", toes_twice);
    printf("The value of toes squared is %d\n", toes_squared);

    return 0;
}
