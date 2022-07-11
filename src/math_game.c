


#include "../include.h"

void math_game(char *str)
{
    int size = 40;
    char text[size];

    //int gameon = 1;
    //while (gameon == 1)
    //{
    //}
    get_str(text,size);
    
    printf("%d\n",calculate(text));
    
    menu_code(str,"");
}