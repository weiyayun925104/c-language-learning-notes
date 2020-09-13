// mytype.c

#include <stdio.h>

#define MYTYPE(X) _Generic((X), \
int:"int", \
long:"long", \
float:"float", \
double:"double", \
default:"other"\
)

int main(int argc, char **argv)
{
    int d = 5;

    printf ("%s\n", MYTYPE(d) );
    printf ("%s\n", MYTYPE(2.0*d) );
    printf ("%s\n", MYTYPE(3L) );
    printf ("%s\n", MYTYPE(&d) );

    return 0;
}
