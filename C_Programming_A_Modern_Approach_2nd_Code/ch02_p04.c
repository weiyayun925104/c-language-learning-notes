#include <stdio.h>

int main(int argc, char **argv)
{
    float money = 0.0f;
    printf("Enter an amount: ");
    scanf("%f", &money);
    printf("With tax added: $%.2f\n", money * 1.05f);

    return 0;
}
