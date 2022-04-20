#include <stdio.h>
#include <unistd.h>
static int size_screen;
struct snake
{
    int x;
    int y;
    int snakeSize;
    int score;
    int gameOn;
};

void menu_code(char *str);

void lose(int point, char *str)
{
	write(1, "\e[1;1H\e[2J", 10);
	printf("the bord was %d, you lose at %d points\n",size_screen , point);
    menu_code(str);
}

void image(int scr[size_screen][size_screen], int size)
{
	int x;
	int y;
	write(1, "\e[1;1H\e[2J", 10);
	x = 0;
	y = 0;
	while(y < size_screen)
	{
		while (x < size_screen)
		{
			if (scr[x][y] == size)
				write(1, "H", 1);
			else if (scr[x][y] > 0 && scr[x][y] != size)
				write(1, "o" , 1);
			else if (x == 0 || x == size_screen -1 || y == 0 || y == size_screen -1)
				write(1, "x", 1);
			else if (scr[x][y] == 0)
				write(1, " ", 1);
			write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
	write(1,"aswd to move, x to exit\n", 25);
}

void mouve(int game[size_screen][size_screen], char key, int dir,struct snake *info)
{
	int x;
	int y;
	if (key == 'w' || key == 's')
		info->y = info->y + dir;
	else
		info->x = info->x + dir;
	if (game[info->x][info->y] > 0 || info->x == 0 || info->x == size_screen -1 || info->y == 0 || info->y == size_screen -1) 
		info->gameOn = 0;
	else
		info->score++;
	game[info->x][info->y] = info->snakeSize +1;
	while (y < size_screen)
	{
		while (x < size_screen)
		{
			if (game[x][y] > 0)
				game[x][y]--;
			x++;
		}
		x = 0;
		y++;
	}
	
}

void game_snake(char *name, int game_size)
{
	size_screen = game_size;//don't move that one 
	int scr[size_screen][size_screen];
    struct snake snakeInfo;
	char chr;
	snakeInfo.score = 0;
	snakeInfo.snakeSize = 5;
	snakeInfo.x = 0, snakeInfo.y = 0;
    printf("\e[1;1H\e[2J");
	while (snakeInfo.y < size_screen)
	{
		while (snakeInfo.x < size_screen)
		{
			scr[snakeInfo.x][snakeInfo.y] = 0;		
			snakeInfo.x++;
		}
		snakeInfo.x = 0;	
		snakeInfo.y++;
	}
	scr[size_screen / 2][size_screen / 2] = snakeInfo.snakeSize;
	snakeInfo.x = size_screen / 2;
	snakeInfo.y = size_screen / 2;
	snakeInfo.gameOn = 1;
	while (snakeInfo.gameOn == 1)
	{
		image(scr, snakeInfo.snakeSize);
		scanf("%1c", &chr);
		switch (chr)
		{
		case 'w':
			mouve(scr ,'w', -1 , &snakeInfo);
			break;

		case 's':
			mouve(scr ,'s', 1 , &snakeInfo);
			break;

		case 'a':
			mouve(scr ,'a', -1 , &snakeInfo);
			break;

		case 'd':
			mouve(scr ,'d', 1 , &snakeInfo);
			break;

		case 'x':
			snakeInfo.gameOn = 0;
			break;
		
		default:
			break;
		}
	}
	lose(snakeInfo.score, name);
	return;
}