#include <stdio.h>

#define initial 5
#define Dunbar 150

int main(int argc, char **argv)
{
    int weeks = 1, friends = initial;

    printf("weeks friends\n");
    while (friends <= Dunbar)
    {
        friends -= weeks;
        friends *= 2;
        printf("%5d %7d\n", weeks, friends);
        weeks++;
    }

    return 0;
}
