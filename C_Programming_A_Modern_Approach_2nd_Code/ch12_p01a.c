#include <stdio.h>

#define MAX_LEN 100

int main(int argc, char **argv)
{
    char message[MAX_LEN];
    char c;
    int i = 0;

    printf("Enter a message: ");

    while ( (c = getchar()) != '\n' && i < MAX_LEN) {
        message[i] = c;
        i++;
    }

    i--;
    printf("Reversal is: ");

    while (i >= 0) {
        putchar(message[i]);
        i--;
    }

    printf("\n");

    return 0;
}    
