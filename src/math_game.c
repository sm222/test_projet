


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
    
    printf("%d\n", get_argP_from_str(text,'-',2));
    
    menu_code(str);
}