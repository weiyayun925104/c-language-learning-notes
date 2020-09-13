// where.c -- ���ݱ������ںδ�?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char * pcg = "String Literal";

int main(int argc, char **argv)
{
    int auto_store = 40;
    char auto_string[] = "Auto char Array";
    int * pi;
    char * pcl;

    pi = (int *) malloc ( 8 * sizeof (int) );
    pi[0] = 35;
    pcl = (char *) malloc ( strlen ("Dynamic String") + 1 );
    strcpy (pcl, "Dynamic String");
    printf  ("static_store: %d at %p\n", static_store, &static_store);
    printf ("auto_store: %d at %p\n", auto_store, &auto_store);
    printf ("*pi: %d at %p\n", *pi, pi);
    printf ("%s at %p\n", pcg, pcg);
    printf ("%s at %p\n", auto_string, auto_string);
    printf ("%s at %p\n", pcl, pcl);
    printf ("%s at %p\n", "Quoted String", "Quoted String");
    free (pi);
    free (pcl);

    return 0;
}
