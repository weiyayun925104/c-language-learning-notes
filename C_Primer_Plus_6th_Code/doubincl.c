// doubincl.c -- ����ͷ�ļ�����
#include "names.h"
#include "names.h"

int main(int argc, char **argv)
{
    names winner = {"Less", "Ismoor"};

    printf ("The winner is %s %s.\n", winner.first, winner.last);

    return 0;
}
