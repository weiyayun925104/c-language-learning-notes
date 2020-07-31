#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE] = {0};
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int evaluate_RPN_expression(const char *expression);

int main(int argc, char **argv)
{
    char c, expr[STACK_SIZE], *p;

    while(true)
    {
        p = expr;
        printf("Enter an RPN expression: ");
        while ( ( c = getchar() ) != '\n' && p < expr + STACK_SIZE )
        {
            *p++ = c;
        }

        printf("Value of expression: %d\n", evaluate_RPN_expression(expr));
        p = expr;
        while (*p)
        {
            *p++ = '\0';
        }
    }
    exit(EXIT_SUCCESS);
}

int evaluate_RPN_expression(const char *expression)
{
    int op1, op2;

    while (*expression)
    {
        if ( isdigit(*expression) )
        {
            push(*expression - '0');
        }
        else
        {
            switch(*expression)
            {
            case '+':
                push( ( pop() + pop() ) );
                break;
            case '-':
                op2 = pop();
                op1 = pop();
                push( (op1 - op2) );
                break;
            case '*':
                push( ( pop() * pop() ) );
                break;
            case '/':
                op2 = pop();
                op1 = pop();
                push( (op1 / op2) );
                break;
            case '=':
                return pop();
                break;
            case ' ':
                break;
            default:
                exit(EXIT_FAILURE);
                break;
            }
        }
        expression++;
    }
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if ( is_full() )
    {
        stack_overflow();
    }
    else
    {
        contents[top++] = i;
    }
}

int pop(void)
{
    if ( is_empty() )
    {
        stack_underflow();
    }
    else
    {
        return contents[--top];
    }
}

void stack_overflow(void)
{
    printf("\nExpression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("\nNot enough operands in expression\n");
    exit(EXIT_FAILURE);
}
