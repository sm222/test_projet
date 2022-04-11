#include <string.h>
void game_snake(char *name, int game_size);

int	ft_atoi(char *str)
{
	int	p;
	int	num;
	int	min;

	min = 1;
	p = 0;
	num = 0;
	while (str[p] == '\t' || str[p] == '\n' || str[p] == '\v'
		|| str[p] == '\f' || str[p] == '\r' || str[p] == ' ')
		p++;
	while (str[p] == '-' || str[p] == '+')
	{
		if (str[p] == '-')
			min = min * -1;
		p++;
	}
	while (str[p] >= '0' && str[p] <= '9')
	{
		num = num * 10 + (str[p] - 48);
		p++;
	}
	return (num * min);
}

void menu_code(char *str)
{
    char command[40];
    printf("%s:" , str);
    scanf("%s",command);
    if (strcmp(command, "help") == 0)
    {
        printf("help list\n");
        printf("\nhelp - give all the commands line\n");
        printf("change_user - change the name of the user\n");
        printf("clear - clear console\n");
        printf("games - game list\n");
        printf("exit - close the programe\n");
        printf("\n");
        menu_code(str);
    }
    else if (strcmp(command, "change_user") == 0)
    {
        printf("type the new user (20 characters max, null to set back to default)\n");
        scanf("%s",command);
        if (strcmp(command, "null") == 0)
            str = ("user");
        else
            str = command;
        menu_code(str);
    }
    else if (strcmp(command, "clear") == 0)
    {
        printf("\e[1;1H\e[2J");
        menu_code(str);
    }
    else if (strcmp(command, "exit") == 0)
    {
        printf("\e[1;1H\e[2J");
        return;
    }
    else if (strcmp(command, "snake") == 0)
    {
        printf("please put a number between 10 and 50\n");
        scanf("%s",command);
        if (ft_atoi(command) < 9 || ft_atoi(command) > 51)
        {
            printf("\ntoo big or small of a number\n");
            menu_code(str);
        }
        else
        {
            printf("\e[1;1H\e[2J");
            game_snake(str,ft_atoi(command));
        }
    }
    else if (strcmp(command, "games") == 0)
    {
        printf("Game list - \n");
        printf("snake\n");
        printf("\n");
        menu_code(str);
    }
    else
    {
        printf("%s : command not found, try \"help\"\n" , command);
        menu_code(str);
    }
}


void main()
{
    printf("\e[1;1H\e[2J");
    menu_code("user");
    return;
}