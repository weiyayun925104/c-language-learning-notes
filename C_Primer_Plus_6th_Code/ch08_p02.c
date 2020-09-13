#include <stdio.h>

int main(int argc, char **argv)
{
    int ch;
    int pairs = 0;

    while ( ( ch = getchar() ) != EOF)
    {
        if (ch == 9)
        {
            printf("\\t");
        }
        else if (ch == 10)
        {
            printf("\\n");
            printf("-%d ", ch);
            printf("\n");
            pairs = 0;
            continue;
        }
        else if (ch < 32)
        {
            printf("^%c", ch + 64);
        }
        else
        {
            printf("%c", ch);
        }

        printf("-%d ", ch);
        pairs++;
        if (pairs % 10 == 0)
        {
            printf("\n");
            pairs = 0;
        }
    }

    return 0;
}
