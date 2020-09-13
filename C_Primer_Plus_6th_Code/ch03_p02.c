#include <stdio.h>

int main(int argc, char **argv)
{
    int ascii;

    printf("Enter an ASCII code value: ");
    scanf("%3d", &ascii);
    printf("The character having ASCII code %d is %c.\n", ascii, ascii);

    return 0;
}
