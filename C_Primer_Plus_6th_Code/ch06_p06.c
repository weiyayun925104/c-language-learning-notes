#include <stdio.h>

int main(int argc, char **argv)
{
    int ll;   // lower limit
    int ul;   // upper limit
    int i;

    printf("Please enter the lower limit for the table: ");
    scanf("%d", &ll);
    printf("Please enter the upper limit for the table: ");
    scanf("%d", &ul);

    printf("%12s %12s %12s\n", "integer", "square", "cube");
    for (i = ll; i <= ul; i++)
    {
        printf("%12d %12d %12d\n", i, i * i, i * i * i);
    }

    return 0;
}
