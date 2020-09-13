// designate.c -- 使用指定初始化器

#include <stdio.h>

#define MONTHS 12

int main(int argc, char **argv)
{
    int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
    int index;

    for (index = 0; index < MONTHS; index++)
    {
        printf ("Month %2d has %2d days.\n", index + 1, days[index]);
    }

    return 0;
}
