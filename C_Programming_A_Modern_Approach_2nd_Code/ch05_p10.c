#include <stdio.h>

int main(int argc, char **argv)
{
    int grade;

    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    if (grade > 100 || grade < 0)
    {
        printf("Error: numerical grade out of range 0-100\n");
    }
    else
    {
        switch (grade / 10)
        {
        case 0 :
        case 1 :
        case 2 :
        case 3 :
        case 4 :
        case 5 :
            printf("Letter grade: F\n");
            break;
        case 6:
            printf("Letter grade: D\n");
            break;
        case 7:
            printf("Letter grade: C\n");
            break;
        case 8:
            printf("Letter grade: B\n");
            break;
        case 9:
        case 10:
            printf("Letter grade: A\n");
            break;
        default:
            break;
        }
    }

    return 0;
}
