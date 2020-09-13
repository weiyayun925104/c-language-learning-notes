#include <stdio.h>

int function();

int main(int argc, char **argv)
{
    int times;
    printf ("Enter a positive integer : ");
    scanf("%d", &times);

    for (int i = 0; i < times; i++)
    {
        printf("The function has been called for %d times.\n", function());
    }

    return 0;
}

int function()
{
    static int times = 0;
    
    ++times;
    return times;
}
