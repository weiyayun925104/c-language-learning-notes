#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

int main(int argc, char **argv)
{
    char message[MAX_LEN];
    char c;
    int i = 0, j;

    printf("Enter a message: ");

    while ( ( c = toupper(getchar()) ) != '\n' && i < MAX_LEN)
    {
        if ( isalpha(c) )
        {
            message[i] = c;
            i++;
        }
    }
    i--;

    for (j = 0; j < i; j++, i--)
    {
        if (message[i] != message[j])
        {
            printf("Not a palindrome\n");
            return 0;
        }
    }
    printf("Palindrome\n");
    return 0;
}
