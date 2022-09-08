


#include "../include.h"

void math_game(char *str)
{
    int size = 40;
    char text[size];

    //int gameon = 1;
    //while (gameon == 1)
    //{
    //}
    sm_get_keybord_input(text,size);
    
    printf("%d\n",sm_calculate(text));
    
    menu_code(str,"");
}