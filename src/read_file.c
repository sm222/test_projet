#include "../include.h"


int print_file(char *name)
{
    int f;
    char d[1];

    f = open(name,O_RDWR);
    if (f == -1)
    {
        sm_print_str("can't open file\n");
        return (1);
    }
    while(read(f ,d ,1) > 0)
        sm_putchar(d[0]);
    close(f);
    return (0);
}