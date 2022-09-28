#include "../include.h"
void put_char(char c)
{
    write(1, &c, 1);
}

void print_value(int size, int *array)
{
    while(--size >= 0)
        array[size] = size;
}

void ft_print_comb2(void)
{
    int size_array = 1;
    int array_int[size_array];
    int i;

    i = 0;
    while(i < size_array)
    {
        printf("%d", array_int[i]);
        i++;
    }
    print_value(size_array,array_int);
    i = 0;
    printf("\n");
    while(i < size_array)
    {
        printf("%d", array_int[i]);
        i++;
    }
    printf("\n");
}