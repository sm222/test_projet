#include "../include.h"

int make_dir(char *name_dir)
{
    int v;

    v = mkdir(name_dir);
    if (v == -1)
    {
        sm_print_str("\nfail to make file\n");
        return (1);
    }
    return (0);
}


int ls(char *path)
{
    DIR *dir;
    dir = NULL;
    if (path[0] == '\0')
        dir = opendir(".");
    else
        dir = opendir(path);
    if (dir == NULL)
        return (1);
    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL)
    {
        printf("%s\n", entity->d_name);
        entity = readdir(dir);
    }
    return (0);
}

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
    printf("\nstart of - %s\n",name);
    while(read(f ,d ,1) > 0)
        sm_putchar(d[0]);
    printf("\n\nfile : %s \nwas read.\n",name);
    close(f);
    return (0);
}