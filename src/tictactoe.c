#include "../include.h"

typedef struct tic {
    int game[3][3];
	int x;
	int y;
    int player;
    int loop;
}tic;

void print_image(tic info)
{
    printf(CLE);
    int x = 0, y = 0;
    write(1," ",2);
    while(x < 3)
    {
        printf(" %d  ", x);
        x++;
    }
    printf("\n");
    x = 0;
    while(y < 3)
    {
        x = 0;
        if (y == 0)
            write(1,"a",2);
        if (y == 1)
            write(1,"b",2);
        if (y == 2)
            write(1,"c",2);
        while(x < 3)
        {
            if (info.game[x][y] == 1)
                write(1," X ", 4);
            else if (info.game[x][y] == 2)
                write(1," O ",4);
            else
                write(1,"   ",4);
            if (x != 2)
                write(1,"|",2);
            x++;
        }
        if(y != 2)
            printf("\n -----------\n");
        y++;
    }
    write(1,"\n",2);
    if(info.loop == 1)
    {
        if (info.player == 1)
            printf(YEL"x "WHT"turn:");
        else
            printf(YEL"o "WHT"turn:");
    }
}

int ask_input(int *x, int *y)
{
    char input[3];
    get_str(input,2);
    //exit code
    if(look_for_func(input,"xx") == 0)
        return(-1);
    //look the 2 char input
    if (input[0] >= 'a' && input[0] <= 'c')
    {
        *y = input[0] - 97;
        if(input[1] >= '0' && input[1] <= '2')
            *x = input[1] -atn;
        else
            return(1);
    }
    else if (input[0] >= '0' && input[0] <= '2')
    {
        *x = input[0] - atn;
        if (input[1] >= 'a' && input[1] <= 'c')
            *y = input[1] -97;
        else
            return(1);
    }
    return(0);
}

int place_pawn(tic *info)
{
    info->x = 0;
    info->y = 0;
    int safe = 1;
    //-1 exit code, 1 is fail, other pass
    do
    {
        safe = ask_input(&info->x , &info->y);
        if (safe == -1)
        {
            info->loop = 0;
            break;
        }
        //
        if (safe == 1)
        {
            printf(CLE);
            print_image(*info);
            printf("invalid input, try again.\"xx\" to exit.\n");
        }
    } while (safe != 0);
    //if case is use return 1
    if (info->game[info->x][info->y] != 0)
        return(1);
    //else put the x or o in the case
    info->game[info->x][info->y] = info->player;
    //swich user at the end of the turn
    if(info->player == 1)
        info->player = 2;
    else
        info->player = 1;
    return(0);
}

int number_chek(int value, int *loop)
{
    //6 mean player 2 win
    if (value == 6)
    {
        *loop = 0;
        return(2);
    }
    //3 mean player 1 win
    else if (value == 3)
    {
        *loop = 0;
        return(1);
    }
    else
        return(0);
}

int win_con(tic *value)
{
    int winner = 0;
    int look = 0;
    int x = 0, y = 0;
    //look left to rigth 
    while(x < 3)
    {
        look = 0;
        y = 0;
        while(y < 3)
        {
            if(value->game[x][y] == 0)
                look -= 10;
            look += value->game[x][y];
            y++;
        }
        winner = number_chek(look,&value->loop);
        if (winner != 0)
            return(winner);
        x++;
    }
    //up and down
    x = 0,y = 0;
    while(y < 3)
    {
        look = 0;
        x = 0;
        while(x < 3)
        {
            if (value->game[x][y] == 0)
                look -= 10;
            look += value->game[x][y];
            x++;
        }
        winner = number_chek(look,&value->loop);
        if (winner != 0)
            return(winner);
        y++;
    }
    //0,0 to 2,2
    x = 0,y = 0;
    look = 0;
    while(x < 3)
    {
        if (value->game[x][y] == 0)
            look -= 10;
        look += value->game[x][y];
        x++ , y++;
    }
        winner = number_chek(look,&value->loop);
        if (winner != 0)
            return(winner);
    //2,0 to 0,2
    x = 2,y = 0;
    look = 0;
    while(x >= 0)
    {
        if (value->game[x][y] == 0)
            look -= 10;
        look += value->game[x][y];
        x-- , y++;
    }
        winner = number_chek(look,&value->loop);
        if (winner != 0)
            return(winner);

    return(0);
}

void look_draw(tic *game)
{
    int x = 0, y = 0;
    int draw = 0;
    while(x < 3)
    {
        y = 0;
        while(y < 3)
        {
            draw += game->game[x][y];
            y++;
        }
        x++;
    }
    if (draw >= 13)
        game->loop = 0;
}

void tictactoe(char *user)
{
    
    tic game_info;
    srand(time(0));
    int player_win = 0;
    //setup bord
    game_info.loop = 1;
    game_info.x = 0, game_info.y = 0;
    while (game_info.x < 3)
    {
        game_info.y = 0;
        while(game_info.y < 3)
        {
            game_info.game[game_info.x][game_info.y] = 0;
            game_info.y++;
        }
        game_info.x++;
    }
    //player x start
    game_info.player = 1;
    //
    while(game_info.loop == 1)
    {
        print_image(game_info);
        place_pawn(&game_info);
        player_win =  win_con(&game_info);
        look_draw(&game_info);
    }
    print_image(game_info);
    if (player_win == 2)
        printf("Player O win\n");
    if (player_win == 1)
        printf("Player X win\n");
    if (player_win == 0)
        printf("-- Draw --\n");
    menu_code(user,"");
}