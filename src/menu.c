

#include "../include.h"

void menu_loop(char *name,char *call_back)
{
    int size_i = 80;
    char u_input[size_i];
    char copy[size_i];
    char *copy_p;
    int str_p = 0;
    //look for recall input
    if (sm_func_looking(call_back,"",&str_p) == 0)
    {
        printf("%s: ",name);
        sm_get_keybord_input(u_input, size_i);
        sm_clear_str(u_input);
    }
    else
        sm_copy_str_to(call_back, u_input, 0, -1);
    str_p = 0;

    //help func
    if (sm_func_looking(u_input,("help"), &str_p) == 0)
    {
        if (sm_func_looking(u_input,"-a",&str_p) == 0)
        {
			printf("help list -a\n\n");
			printf("help -a give all information\n");
			printf("su -u change the name of the user directely\n");
			printf("clear - clear console\n");
			printf("cal -i (number and operator with no space) open the calculator\n");
			printf("games - game list\n");
			printf("sig - show the sm222\n");
			printf("exit - close the programe\n");
			printf("\n");
        }
        else if(sm_func_looking(u_input,"",&str_p) == 0)
        {
            printf("help list\n\n");
            printf("help - give all the u_inputs line (-a for more info)\n");
            printf("su - change the name of the user\n");
            printf("clear - clear console\n");
            printf("cal - open the calculator\n");
            printf("games - game list\n");
            printf("sig - show the sm222\n");
            printf("exit - close the programe\n");
            printf("\n");
        }
        else
        {
            sm_copy_str_to(u_input ,copy ,str_p +1,-1);
            printf(YEL "help "RESET RED"%s " RESET "is not a valid argumant\n",copy);
        }
        menu_loop(name,"");
        return;
    }
    //clear
    else if(sm_func_looking(u_input,"clear", &str_p) == 0)
    {
        sm_print_str(CLE);
        signature();
        menu_loop(name,"");
        return;
    }
    //sig
    if (sm_func_looking(u_input ,"sig", &str_p) == 0)
    {
        signature();
        menu_loop(name,"");
        return;
    }
    //example
    else if (sm_func_looking(u_input,("yes"), &str_p) == 0)
    {
        if(sm_find_mix_str(u_input,("itwork"), &str_p) == 0)
            printf("yes\n");
        menu_loop(name,"");
    }
    //tictactoe
    else if (sm_func_looking(u_input,("tic"), &str_p) == 0)
    {
        tictactoe(name);
        return;
    }
    //snake 
    else if (sm_func_looking(u_input,("snake"), &str_p) == 0)
    {
        if(sm_func_looking(u_input,("-s"), &str_p) == 0)
        {
            sm_copy_str_to(u_input, copy, str_p +1, -1);
            if (sm_atoi(copy) < 7 || sm_atoi(copy) > 45)
                printf(RED "%s " RESET "is not a valid input\n", copy);
            else
                game_snake(name,sm_atoi(copy));
        }
        else if(sm_func_looking(u_input,(""), &str_p) == 0)
        {
            printf("please put a number between 7 and 45\n");
            sm_get_keybord_input(u_input, 3);
            sm_clear_str(u_input);
            if (sm_atoi(u_input) < 7 || sm_atoi(u_input) > 45)
                printf(RED"%s " RESET "is not a valid argumant\n",u_input);
            else
                game_snake(name,sm_atoi(u_input));
        }
        else
        {
            sm_copy_str_to(u_input ,copy ,str_p +1,-1);
            printf(YEL "snake "RESET RED"%s " RESET "is not a valid argumant\n",copy);
        }
        menu_loop(name,"");
        return;
    }
    //defi
    else if (sm_func_looking(u_input,("defi"),&str_p) == 0)
    {
        if (sm_copy_str_to(u_input, copy ,str_p + 1, 5) == 0)
            printf("fail input\n");
        else
            defi(copy);
        menu_loop(name,(""));
        return;
    }
    //games list
    else if (sm_func_looking(u_input ,("games"),&str_p) == 0)
    {
        printf("Game list - \n");
		printf("snake\n");
		printf("tic - tictactoe\n");
		printf("\n");
        menu_loop(name,"");
        return;
    }
    //su = swich user
    else if (sm_func_looking(u_input, ("su"), &str_p) == 0)
    {
        if(sm_func_looking(u_input, ("-u"), &str_p) == 0)
        {
            if(sm_copy_str_to(u_input , copy ,str_p +1,-1) == 0)
                printf("no input was given\n");
            else
                name = copy;
        }
        else if(sm_func_looking(u_input,(""), &str_p) == 0)
        {
            printf("please give a new name\n");
            sm_get_keybord_input(u_input,10);
            sm_clear_str(u_input);
            if (u_input[0] == '\0')
                printf("no valid input\n");
            else
                name = u_input;
        }
        else
            printf(RED "%s " RESET "is not a valid input\n", u_input);
        menu_loop(name,(""));
        return;
    }
    //cal
    else if (sm_func_looking(u_input ,"cal" , &str_p) == 0)
    {
        sm_get_keybord_input(u_input, 50);
        sm_clear_str(u_input);
        printf("%f\n",sm_get_number(u_input));
        menu_loop(name,"");
    }
    //noise
    else if (sm_func_looking(u_input ,"noise", &str_p) == 0)
    {
        noise(1000,130);
        menu_loop(name,"");
        return;
    }
    //12
    else if (sm_func_looking(u_input,"12", &str_p) == 0)
    {
        menu_loop(name,"echo "RED"12 "RESET": is not valid input, did you mean "YEL"\"Windouze XP\" "RESET"?");
        return;
    }
    //put nbr
    else if(sm_func_looking(u_input, "put_nbr",&str_p) == 0)
    {
        sm_copy_str_to(u_input, copy, str_p + 1, -1);
        sm_put_number(sm_atoi(copy));
        printf("\n");
        
        menu_loop(name,"");
    }
    //c06
    else if(sm_func_looking(u_input ,"c06",&str_p) == 0)
    {
        ft_print_comb2();
        menu_loop(name,"");
        return;
    }
    //echo
    else if (sm_func_looking(u_input,"echo", &str_p) == 0)
    {
        copy_p = sm_calloc(sizeof(char),sm_str_size(call_back));
        sm_copy_str_to(copy_p,u_input,sm_while_space_tab(0,copy_p),-1);
        printf("%s\n",u_input);
        free(copy_p);
        menu_loop(name,"");
        return;
    }
    //put_file
    else if(sm_func_looking(u_input,"rf",&str_p) == 0)
    {
        if(sm_func_looking(u_input, (""), &str_p) == 0)
            print_file("test.txt");
        else
        {
            sm_copy_str_to(u_input,copy,str_p +1,-1);
            printf("%s\n",copy);
            print_file(copy);
        }
        menu_loop(name,"");
    }
    //ls
    else if(sm_func_looking(u_input,"ls",&str_p) == 0)
    {
        if(sm_func_looking(u_input, (""), &str_p) == 0)
            ls("");
        else
        {
            sm_copy_str_to(u_input,copy,str_p +1,-1);
            ls(copy);
        }
        menu_loop(name,"");
    }
    /*cd
    else if(sm_func_looking(u_input,"cd",&str_p) == 0)
    {
        if(sm_func_looking(u_input, (""), &str_p) == 0)
            ls("");
        else
        {
            sm_copy_str_to(u_input,copy,str_p +1,-1);
            ls(copy);
        }
        menu_loop(name,"");
    */
    //make dir
    else if(sm_func_looking(u_input,"mkdir",&str_p) == 0)
    {
        if(sm_func_looking(u_input, (""), &str_p) == 0)
            sm_print_str("\nneed a file name\n");
        else
        {
            sm_copy_str_to(u_input,copy,str_p +1,-1);
            //make_dir(copy);
        }
        menu_loop(name,"");
    }
    //void
    else if (sm_func_looking(u_input,(""), &str_p) == 0)
    {
        printf(RED"void " WHT"is not a valid input\n");
        //printf("%f\n",sm_fl(6));
        menu_loop(name,"");
        return;
    }
    //exit
    else if (sm_func_looking(u_input,("exit"), &str_p) == 0)
        exit(0);
    //default 
    else
    {
        printf(RED"%s " WHT"is not a valid input\n",u_input);
        menu_loop(name,"");
    }
}
