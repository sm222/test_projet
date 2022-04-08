#include <string.h>
void game_snake(char *name);

void menu_code(char *str)
{
    printf("%s:" , str);
    char command[40];
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
        printf("\e[1;1H\e[2J");
        game_snake(str);
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
    char user[21] = {"user"};
    printf("\e[1;1H\e[2J");
    menu_code(user);
    return;
}