// useheader.c -- 使用names__st结构

#include "names_st.h"

int main(int argc, char **argv)
{
    names candidate;

    get_names (&candidate);
    printf ("Let's welcome ");
    show_names (&candidate);
    printf (" to this program!\n");

    return 0;
}
