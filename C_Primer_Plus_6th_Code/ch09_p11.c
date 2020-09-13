#include <stdio.h>

void Fibonacci (unsigned int n);

int main(int argc, char **argv)
{
    unsigned int n;

    printf("Please enter an integer (>=1): ");
    scanf("%u", &n);
    Fibonacci(n);
    printf("\n");

    return 0;
}

void Fibonacci(unsigned int n)
{
    int Fn = 1;
    int Fn1 = 1;
    int Fn2 = 0;
    int counter = 1;

    printf("All Fibanocci numbers <= %d are: \n", n);
    while (Fn <= n)
    {
        printf("%d ", Fn);
        if(counter % 8 == 0)
        {
            printf("\n");
        }
        Fn = Fn1 + Fn2;
        if (counter % 2 == 0)
        {
            Fn1 = Fn;
        }
        else
        {
            Fn2 = Fn;
        }
        counter++;
    }
}
