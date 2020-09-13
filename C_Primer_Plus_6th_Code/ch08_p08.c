#include <stdio.h>

void menu(void);

int main(int argc, char **argv)
{
    char choice;
    char input;
    float first_num, second_num;
    float answer;
    int ret;

    menu();
    while ( ( choice = getchar() ) != 'q' )
    {
        while ( getchar() != '\n' )
        {
            continue;
        }
        if (choice != 'a' && choice != 's' && choice != 'm' && choice != 'd')
        {
            printf("Please enter a or s or m or d: ");
            continue;
        }
        printf("Enter the first number: ");
        while ( scanf("%g", &first_num) != 1 )
        {
            while ( ( input = getchar() ) != '\n' )
            {
                putchar(input);
            }
            printf(" is not an number.\n");
            printf("Please enter a number: ");
        }
        while ( getchar() != '\n' )
        {
            continue;
        }

        printf("Enter the second number: ");
        while ( ( ret = scanf("%g", &second_num) ) != 1 || (second_num == 0 && choice == 'd') )
        {
            if (ret != 1)
            {
                while ( ( input = getchar() ) != '\n' )
                {
                    putchar(input);
                }
                printf(" is not an number.\n");
                printf("Please enter a number: ");
            }
            else
            {
                while ( getchar() != '\n' )
                {
                    continue;
                }
                printf("Please enter a number other than 0: ");
            }
        }
        while ( getchar() != '\n' )
        {
            continue;
        }

        switch (choice)
        {
        case 'a':
            answer = first_num + second_num;
            printf("%g + %g = %g\n", first_num, second_num, answer);
            break;
        case 's':
            answer = first_num - second_num;
            printf("%g - %g = %g\n", first_num, second_num, answer);
            break;
        case 'm':
            answer = first_num * second_num;
            printf("%g * %g = %g\n", first_num, second_num, answer);
            break;
        case 'd':
            answer = first_num / second_num;
            printf("%g / %g = %g\n", first_num, second_num, answer);
            break;
        default :
            return 0;
            break;
        }
        menu();
    }

    printf("Done.\n");

    return 0;
}

void menu(void)
{
    printf("Enter the operation of your choice:\n");
    printf("a. add           s. subtract\n");
    printf("m. multiply      d. divide\n") ;
    printf("q. quit\n");
}
