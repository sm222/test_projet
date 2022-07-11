

#include "../include.h"

void menu_loop(char *name)
{
    int size_i = 60;
    char u_input[size_i];
    int str_p = 0;
    printf("(beta) %s:",name);
    
    get_str(u_input, size_i);
    clear_str(u_input);

    if (func_looking(u_input,("snake"), &str_p) == 0)
    {
        printf("please put a number between 7 and 45\n");
		get_str(u_input, 21);
		clear_str(u_input);
		if (ft_atoi(u_input) < 7 || ft_atoi(u_input) > 45)
		{
			printf(RED "%s " RESET "is not a valid input\n", u_input);
			menu_loop(name);
			return;
		}
		game_snake(name,ft_atoi(u_input));
        return;
    }
    else if (func_looking(u_input,("exit"), &str_p) == 0)
    {
        menu_code(name,(""));
        return;
    }
    else if (func_looking(u_input,(""), &str_p) == 0)
    {
        printf(RED"void " WHT"is not a valid input\n");
    }
    else if (func_looking(u_input,("yes"), &str_p) == 0)
    {
        if(mix(u_input,"letgo",&str_p) == 0)
            printf("yooooo\n");
    }
    else
    {
        printf(RED"%s " WHT"is not a valid input\n",u_input);
    }
    menu_code(name,("test"));
    return;
}