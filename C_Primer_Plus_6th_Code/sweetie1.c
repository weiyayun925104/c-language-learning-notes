// sweetiel.c -- 一个计数循环

#include <stdio.h>

int main(int argc, char **argv)
{
    const int NUMBER = 22;
    int count = 1;

    while (count <= NUMBER)
    {
        printf ("Be my Valentine!\n");
        count++;
    }

    return 0;
}
