

#include "../include.h"
//UI, use to take input and navigate all the program
void menu_code(char *str)
{
	int size = 40;
	char command[size];
	char arg;// use to look at arg int the function
	int agr_number = 0;
	int arp_p;
	char arg_v[21];
	int i = 0;
	while(arg_v[i])
		arg_v[i++] = ' ';
	
	printf(RESET);
	print_str(str);
	write(1 , ":" , 1);

	get_str(command, size);
	clear_str(command);
	
	if (look_for_func(command,("help")) == 1)
	{
		agr_number = number_arg(command,'-');
		if (get_argP_from_str(command,'-', 1) == 0)
		{
			printf("help list\n\n");
			printf("change user - change the name of the user\n");
			printf("help - give all the commands line\n");
			printf("clear - clear console\n");
			printf("games - game list\n");
			printf("signature - show the sm222\n");
			printf("exit - close the programe\n");
			printf("\n");
		}
		else
		{
			while (agr_number > 0)
			{
				arp_p = get_argP_from_str(command, '-',agr_number);
				arg = command[arp_p];
				give_arg_v(command, arg_v, arp_p + 2);
				agr_number--;
				switch (arg)
				{
				case 'a':
					printf("help list -a\n");
					printf("help -a give all information\n");
					printf("change user -u change the name of the user directely\n");
					printf("clear - clear console\n");
					printf("games - game list\n");
					printf("signature - show the sm222\n");
					printf("exit - close the programe\n");
					printf("\n");
					break;

				default:
					printf(YEL "help " RESET"-" RED "%c " RESET "is not a valid argumant\n",arg);
					break;
				}
			}
		}
		menu_code(str);
		return;
	}

	if (look_for_func(command,("change user")) == 1)
	{
		agr_number = number_arg(command,'-');
		if (get_argP_from_str(command,'-', 1) == 0)
		{
			printf("type the new user (20 characters max, null to set back to default)\n");
			get_str(command, 21);
			clear_str(command);
			if (strcmp(command, "null") == 0)
				str = ("user");
			else
				str = command;
			menu_code(str);
			return;
		}
		else
		{
			while (agr_number > 0)
			{
				arp_p = get_argP_from_str(command, '-',agr_number);
				arg = command[arp_p];
				give_arg_v(command, arg_v, arp_p + 2);
				agr_number--;
				switch (arg)
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
					printf(YEL "change user " RESET"-" RED "%c " RESET "is not a valid argumant\n",arg);
					break;
				}
			}
		}
		menu_code(str);
		return;
	}

	else if (strcmp(command, "clear") == 0)
	{
		printf(CLE);
		menu_code(str);
		return;
	}

	else if (look_for_func(command,("exit")) == 1)
	{
		printf("\e[1;1H\e[2J");
		return;
	}
//snake
if (look_for_func(command,("snake")) == 1)
	{
		agr_number = number_arg(command,'-');
		if (get_argP_from_str(command,'-', 1) == 0)
		{
			printf("please put a number between 7 and 45\n");
			get_str(command, 21);
			clear_str(command);
			if (ft_atoi(command) < 7 || ft_atoi(command) > 45)
			{
				printf(RED"%s "RESET" is not a valid input\n", command);
				menu_code(str);
				return;
			}
			game_snake(str,ft_atoi(command));
			return;
		}
		else
		{
			while (agr_number > 0)
			{
				arp_p = get_argP_from_str(command, '-',agr_number);
				arg = command[arp_p];
				give_arg_v(command, arg_v, arp_p + 2);
				agr_number--;
				switch (arg)
				{
				case 's':
					if (ft_atoi(arg_v) < 7 || ft_atoi(arg_v) > 45)
						printf(YEL "snake -s "RESET RED "%d" RESET "is not a valid size\n", ft_atoi(arg_v));
					else
					{
						game_snake(str,ft_atoi(arg_v));
						return;
					}
					break;
				default:
					printf(YEL "snake " RESET"-" RED "%c " RESET "is not a valid argumant\n",arg);
					break;
				}
			}
		}
		menu_code(str);
		return;
	}

	else if (strcmp(command, "games") == 0)
	{
		printf("Game list - \n");
		printf("snake\n");
		printf("\n");
		menu_code(str);
		return;
	}

	else if (strcmp(command, "signature") == 0)
	{
		signature();
		menu_code(str);
		return;
	}
	
	else if (strcmp(command, "math game") == 0)
	{
		math_game(str);
	}

	else if (strcmp(command, "noise") == 0)
	{
		noise(1000,130);
		menu_code(str);
		return;
	}
	//default
	else
	{
		printf(RED"%s "RESET": command not found, try "YEL"\"help\"\n"RESET, command);
		menu_code(str);
		return;
	}
	
}

int main(void)
{
	printf(CLE);
	signature();
	print_str("v1.0, work in progress - type 'help' to start\n");
	menu_code("user");
	return(0);
}