

#include "../include.h"
//UI, use to take input and navigate all the program
void menu_code(char *str,char *input_loop)
{
	int i_size = 80;
	char u_input[i_size];
	char arg_c;// use to look at arg int the function ex: -i -a -u
	int agr_number = 0; //number of arg
	int arp_p;
	char arg_v[31];//arg value
	int programe_loop = 0;
	
	if (look_for_func(input_loop,("")) == 0)
	{
		printf(WHT);
		sm_print_str(str);
		write(1,":",1);
		sm_get_keybord_input(u_input, i_size);
		sm_clear_str(u_input);
	}
	else
		sm_copy_str_to(input_loop,u_input,-1,10);
	
	//sm_inspect_arr(u_input, 'c' , i_size);
	if (look_for_func(u_input,("help")) == 0)
	{
		agr_number = number_arg(u_input,'-');
		if (get_argP_from_str(u_input,'-', 1) == 0)
		{
			printf("help list\n\n");
			printf("su - change the name of the user\n");
			printf("help - give all the u_inputs line (-a for more info)\n");
			printf("clear - clear console\n");
			printf("cal - open the calculator\n");
			printf("games - game list\n");
			printf("sig - show the sm222\n");
			printf("exit - close the programe\n");
		}
		else
		{
			while (agr_number > 0)
			{
				arp_p = get_argP_from_str(u_input, '-',agr_number);
				arg_c = u_input[arp_p];
				give_arg_v(u_input, arg_v, arp_p + 2);
				agr_number--;
				switch (arg_c)
				{
				case 'a':
					printf("help list -a\n");
					printf("help -a give all information\n");
					printf("su -u change the name of the user directely\n");
					printf("clear - clear console\n");
					printf("cal -i (number and operator with no space) open the calculator\n");
					printf("games - game list\n");
					printf("sig - show the sm222\n");
					printf("exit - close the programe\n");
					printf("\n");
					break;

				default:
					printf(YEL "help " RESET"-" RED "%c " RESET "is not a valid argumant\n",arg_c);
					break;
				}
			}
		}
		menu_code(str,(""));
		return;
	}

	else if (look_for_func(u_input,"test") == 0)
	{
		menu_loop(str,"clear");
		return;
	}
	else if(look_for_func(u_input,("su")) == 0)
	{
		agr_number = number_arg(u_input,'-');
		if (get_argP_from_str(u_input,'-', 1) == 0)
		{
			printf("type the new user (20 characters max, null to set back to default)\n");
			sm_get_keybord_input(u_input, 21);
			sm_clear_str(u_input);
			if (strcmp(u_input, "null") == 0)
				str = ("user");
			else
				str = u_input;
			menu_code(str,(""));
			return;
		}
		else
		{
			while (agr_number > 0)
			{
				arp_p = get_argP_from_str(u_input, '-',agr_number);
				arg_c = u_input[arp_p];
				give_arg_v(u_input, arg_v, arp_p + 2);
				agr_number--;
				switch (arg_c)
				{
				case 'u':
					if (strcmp(arg_v,"") == 0)
						printf(YEL "change user -u "RESET RED "void " RESET "is not a valid argumant\n");
					else
						str = arg_v;
					break;
				case 'd':
					str = ("user");
					break;

				default:
					printf(YEL "change user " RESET"-" RED "%c " RESET "is not a valid argumant\n",arg_c);
					break;
				}
			}
		}
		menu_code(str,(""));
		return;
	}

	else if (strcmp(u_input, "clear") == 0)
	{
		printf(CLE);
		menu_code(str,("sig"));
		return;
	}

	else if (look_for_func(u_input,("exit")) == 0)
	{
		printf("\e[1;1H\e[2J");
		return;
	}
//snake
	else if (look_for_func(u_input,("snake")) == 0)
	{
		agr_number = number_arg(u_input,'-');
		if (get_argP_from_str(u_input,'-', 1) == 0)
		{
			printf("please put a number between 7 and 45\n");
			sm_get_keybord_input(u_input, 21);
			sm_clear_str(u_input);
			if (sm_atoi(u_input) < 7 || sm_atoi(u_input) > 45)
			{
				printf(RED "%s " RESET "is not a valid input\n", u_input);
				menu_code(str,(""));
				return;
			}
			game_snake(str,sm_atoi(u_input));
			return;
		}
		else
		{
			while (agr_number > 0)
			{
				arp_p = get_argP_from_str(u_input, '-',agr_number);
				arg_c = u_input[arp_p];
				give_arg_v(u_input, arg_v, arp_p + 2);
				agr_number--;
				switch (arg_c)
				{
				case 's':
					if (sm_atoi(arg_v) < 7 || sm_atoi(arg_v) > 45)
						printf(YEL "snake -s "RESET RED "%d" RESET "is not a valid input\n", sm_atoi(arg_v));
					else
					{
						game_snake(str,sm_atoi(arg_v));
						return;
					}
					break;
				default:
					printf(YEL "snake " RESET"-" RED "%c " RESET "is not a valid argumant\n",arg_c);
					break;
				}
			}
		}
		menu_code(str,(""));
		return;
	}
//
	else if(look_for_func(u_input,("cal")) == 0)
	{
		agr_number = number_arg(u_input,'-');
		if (get_argP_from_str(u_input,'-', 1) == 0)
		{
			programe_loop = 1;
			printf("calculator V1, type x or q to exit\n");
			while(programe_loop == 1)
			{
				sm_get_keybord_input(u_input, i_size);
				sm_clear_str(u_input);
				if (look_for_func(u_input,("x")) == 0 || look_for_func(u_input,("q")) == 0)
					break;
				printf("%d\n", sm_calculate(u_input));
			}
			menu_code(str,(""));
			return;
		}
		else
		{
			while (agr_number > 0)
			{
				arp_p = get_argP_from_str(u_input, '-',agr_number);
				arg_c = u_input[arp_p];
				give_arg_v(u_input, arg_v, arp_p + 2);
				agr_number--;
				switch (arg_c)
				{
				case 'i':
					printf("%d\n",sm_calculate(arg_v));
					break;
				default:
					printf(YEL "cal " RESET"-" RED "%c " RESET "is not a valid argumant\n",arg_c);
					break;
				}
			}
		}
		menu_code(str,("\0"));
		return;
	}
//
	else if(strcmp(u_input, "games") == 0)
	{
		printf("Game list - \n");
		printf("snake\n");
		printf("tic - tictactoe\n");
		printf("\n");
		menu_code(str,(""));
		return;
	}

	else if (strcmp(u_input, "sig") == 0)
	{
		signature();
		menu_code(str,(""));
		return;
	}
	
	else if (strcmp(u_input, "math game") == 0)
	{
		math_game(str);
	}

	else if (strcmp(u_input, "noise") == 0)
	{
		noise(1000,130);
		menu_code(str,(""));
		return;
	}
	//
	else if (strcmp(u_input, "rn") == 0)
	{
		for (int loop = 0; loop < 10; loop++)
		{
			printf("%d\n", sm_r_num(10,10));		
		}
		menu_code(str,(""));
		return;
	}
	else if (strcmp(u_input, "") == 0)
	{
		printf(RED"void "RESET": is not valid input, try "YEL"\"help\"\n"RESET);
		menu_code(str,(""));
		return;
	}
	else if (strcmp(u_input, "12") == 0)
	{
		printf(RED"12 "RESET": is not valid input, did you mean "YEL"\"Windouze XP\" "RESET"?\n");
		menu_code(str,(""));
		return;
	}
	else if (strcmp(u_input, "tic") == 0)
	{
		tictactoe(str);
	}
	//default
	else
	{
		printf(RED"%s "RESET": commend not found, try "YEL"\"help\"\n"RESET, u_input);
		menu_code(str,(""));
		return;
	}
	
}

int main(void)
{
	printf(CLE);
	signature();
	printf(WHT);
	sm_print_str("v1.0, work in progress - type 'help' to start\n");
	menu_code(("user"),(""));
	return(0);
}