#include <stdio.h>

int main(int argc, char **argv)
{
    int second_operand, first_operand;

    printf("Enter an integer to serve as the second operand: ");
    scanf("%d", &second_operand);
    printf("Now enter the first operand: ");
    scanf("%d", &first_operand);
    while (first_operand > 0)
    {
        printf("%d %% %d is %d\n", first_operand, second_operand, first_operand % second_operand);
        printf("Enter next number for first operand (<=0 to quit): ");
        scanf("%d", &first_operand);
    }
    printf("Done!\n");

    return 0;
}
