#include <stdio.h>

int main(int argc, char **argv)
{
    int r = 0;

    printf("Enter radius: ");
    scanf("%d", &r);

    printf("\nSphere volume: %.3f cubic meters\n", (4.0f / 3.0f) * (3.141592f * r * r * r));
    return 0;
}
