#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    for (i = 0; i < 1000; i++)
    {
        printf("%d ", rand() & 1);
        if ( (i % 40) == 39 )
        {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
