#include <stdio.h>

void br(void);
void ic(void);

int main(int argc, char **argv)
{
    br();
    printf(", ");
    ic();
    printf("\n");
    ic();
    printf(", \n");
    br();
    printf("\n");

    return 0;
}

void br()
{
    printf("Brazil, Russia");
}

void ic()
{
    printf("India, China");
}
