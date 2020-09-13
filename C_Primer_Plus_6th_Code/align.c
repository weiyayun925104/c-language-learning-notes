// align.c --  π”√ _Alignof∫Õ_Alignas

#include <stdio.h>

int main(int argc, char **argv)
{
    double dx;
    char ca;
    char cx;
    double dz;
    char cb;
    char _Alignas(double) cz;

    printf ("char alignment: %zu\n", _Alignof(char) );
    printf ("double alignment: %zu\n", _Alignof(double));
    printf ("&dx: %p\n", &dx);
    printf ("&ca: %p\n", &ca);
    printf ("&cx: %p\n", &cx);
    printf ("&dz: %p\n", &dz);
    printf ("&cb: %p\n", &cb);
    printf ("&cz: %p\n", &cz);

    return 0;
}
