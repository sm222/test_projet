#include <string.h>
void game_snake(char *name, int game_size);

void art(void)
{
    printf("                                                                                                    \n");
    printf("                                                     ..........                                     \n");
    printf("                                 !5GGBBBBB#Y:    .?GB#####&BG##BBBBBBG?                             \n");
    printf("                              .?B@@@@@@@@&?.     ^@@@@@@@&Y:7@@@@@@@@@J                             \n");
    printf("                             ^B@@@@@@@@&J.       !@@@@@G?:  7@@@@@@@@@J                             \n");
    printf("                            ?@@@@@@@@&5:         !@@&P~     :&@@@@@@@@G                             \n");
    printf("                          ~G@@@@@@@@P:           :Y!:       :&@@@@@@@@G                             \n");
    printf("                        ~P@@@@@@@@5^                       ^B@@@@@@@@G:                             \n");
    printf("                     .7G@@@@@@@#Y^        ..............:7P&@@@@@@#Y~                               \n");
    printf("                   :J#@@@@@@@#Y~:^^~~~!!!!!!777777777!?P&@@@@@@@&Y7~~~~^^:..                        \n");
    printf("                 ~P&@@@@@@@BY777????????????????????JP&@@@@@@@&PJ????????77!!~^^:.                  \n");
    printf("            ..:7G@@@@@@@@BY?JJJJJYYYYYJJJJJ??!~~~~~Y&@@@@@@@@5!!!!!7777????????77!!~^:.             \n");
    printf("         .^~!7?&@@@@@@@@@##&&&&&@@@@@@@@@@@@@?~!!!!B@@@@@@@@&!~~~~~~^!57~!!!7????????7!~            \n");
    printf("        .!!!77J&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y7????#@@@@@@@@&?777!!75&@Y~~~~~~~!77?7!!!!.           \n");
    printf("        :!!~^~?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P7???J&@@@@@@@@#??77?G&@@@P77777!!~~!~^~!!!.           \n");
    printf("        ~!!~^!7&@@@@@@@@@@@@@&&@&@@@@@@@@@@@@G?JJJP@@@@@@@@@G??JP&@@@@@Y7????7!!!!!^~!!!.           \n");
    printf("        ~!!^~!!?J?7JYJYYJJJ??JJYYYYG@@@@@@@@@PJJJJG@@@@@@@@@G5G&@@&&&&#J?777!!^~!!!^~!!!.           \n");
    printf("       .!!!^~!!!!^^!!!!!!!^^!!!7777G@@@@@@@@@5JJJJJYYY5555555YYYYYYYJJ?!!!!!!!~^~!!~~!!!.           \n");
    printf("       .!!!^~!!!!^~!!!!!!!~~!!!!!!!P@@@@@@@@@5?JJJJ??????????????777!!~^!!!!!!!^~!!~^!!!.           \n");
    printf("       .!!!^~!!!~^!!!!!!!!^~!!!!!!!B@@@@@@@@@J!!!!!!!!!!~^!!!!!!!!!!!!~^~!!!!!!^~!!~^!!~            \n");
    printf("       .!!!^~!!!~^!!!!!!!~^~!!!!!!!P##&###&##J!!!!?!!!!!~^~!!!77!!!!!!~^7!!!!!!^~!!~^!!~            \n");
    printf("       .!!!^~!!!~~!!!!!!!~^~!!!!!!!!!!!~~!!!!!!!!?#7!!!!!^~!77J?!!77!!!!??!!!!!~~!!~^!!~            \n");
    printf("        !!~^~!!!^~!!!!!!!~^!!!!!!!!!!!!~^!!!!!!!!7B7!!!YJ??!5J??!JY?Y!YJ7?!?Y?Y~~!!~^!!^            \n");
    printf("        ~!~^!!!!^~!!!!!!!~^!!!!!!!!!!!!~^!!!!!!!!!BJ!!!5B?^~GJ??!Y5YP!PJ!7!?#Y!^~!!~^!!:            \n");
    printf("        :~~~!!!!^~!!!!!!!~^!!!!!!!!!!!!~^!!!!!!!!!GY!!!J7J?~YJJ?!YY?Y7JJ??!???Y!~!!!^:              \n");
    printf("          ..:^~~^~!!!!!!!~^!!!!!!!!!!!!~^~!!!!!!!!B?!!!!!!~^!!7!!!!!!!!!~!!!!!!~~!~:                \n");
    printf("                 ..:^~~!!~^!!!!!!!!!!!!~^~!!!!!!!!7!!!!!!!~^!!!!!!!!!!!!^~!!!!!^^:                  \n");
    printf("                        ..:^~~!!!!!!!!!!^~!!!!!!!!!!!!!!!!~^~!!!!!!!!!!!^~!~~^:.                    \n");
    printf("                               ..::^^~~~^~!!!!!!!!!!!!!!!!~^~!!!~~~~~^^:...                         \n");
    printf("                                          ......:::::::::.....                                      \n");
    printf("                                                                                                    \n");
}

void signature(void)
{
    printf("\e[1;1H\e[2J");
    printf(" ::::::::  ::::    ::::   ::::::::   ::::::::   ::::::::  \n");
    printf(":+:    :+: +:+:+: :+:+:+ :+:    :+: :+:    :+: :+:    :+: \n");
    printf("+:+        +:+ +:+:+ +:+       +:+        +:+        +:+  \n");
    printf("+#++:++#++ +#+  +:+  +#+     +#+        +#+        +#+    \n");
    printf("       +#+ +#+       +#+   +#+        +#+        +#+      \n");
    printf("       +#+ +#+       +#+   +#+        +#+        +#+      \n");
    printf("#+#    #+# #+#       #+#  #+#        #+#        #+#       \n");
    printf(" ########  ###       ### ########## ########## ########## \n");
}

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
        printf("art - show art of the 42\n");
        printf("clear - clear console\n");
        printf("loading - test\n");
        printf("games - game list\n");
        printf("signature - show the sm222\n");
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
        if (ft_atoi(command) < 4 || ft_atoi(command) > 51)
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
    else if (strcmp(command, "art") == 0)
    {
        art();
        printf("site use : https://www.text-image.com/convert/\n\n");
        menu_code(str);
    }
    else if (strcmp(command, "signature") == 0)
    {
        signature();
        menu_code(str);
    }
    else if (strcmp(command, "loading") == 0)
    {
        for (size_t i = 0; i <= 100; i++)
        {
            printf("loading %d", i);
            sleep(1);
            i = i + 4;
            printf("\r");
        }
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
    signature();
    menu_code("user");
    return;
}