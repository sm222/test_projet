

#include "../include.h"

static int size_screen;

void lost(int point, char *str)
{
	write(1, "\e[1;1H\e[2J", 10);
	printf("the bord was %d, you lose at %d points\n",size_screen , point);
	menu_code(str,"");
	return;
}

/*print the game on the terminal
the size = length of the snake
*/
void image(int (*scr)[size_screen], int size)
{
	int x = 0;
	int y = 0;
	write(1,"\e[1;1H\e[2J", 10);
	
	while(y < size_screen)
	{
		while (x < size_screen)
		{
			if (scr[x][y] == size)
				write(1, "\x1B[32mH\x1B[0m", 11);	//head of the snake(H)
			else if (scr[x][y] > 0 && scr[x][y] != size)
				write(1, "\x1B[32mo\x1B[0m" , 11); //body of the snake(o)
			else if (scr[x][y] == -1)
				write(1 , "\x1B[31mA\x1B[0m" , 11);	//apple (A)
			else if (x == 0 || x == size_screen -1 || y == 0 || y == size_screen -1)
				write(1, "\x1B[35mX\x1B[0m", 11);	//wall(X)
			else if (scr[x][y] == 0)
				write(1, " ", 1);
			write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
}

void move(int (*game)[size_screen], char key, int dir,struct snake *info,struct apple *fruit)
{
	int x = 0;
	int y = 0;
	if (key == 'w' || key == 's')
		info->y = info->y + dir;
	else
		info->x = info->x + dir;
	if (game[info->x][info->y] > 0 || info->x == 0 || info->x == size_screen -1 || info->y == 0 || info->y == size_screen -1) //look for obstacle
		info->gameOn = 0;
	else if (game[info->x][info->y] == -1) //if get an apple add 5 points
		{
			fruit->onOff = 0;
			info->snakeSize++;
			info->score = info->score + 5;
		}
	else
	{}
	game[info->x][info->y] = info->snakeSize +1;
	while (y < size_screen) //clean the array
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

void apples(struct apple *pomme ,int gamebord[size_screen][size_screen])
{
	pomme->x = r_num(0, size_screen);
	pomme->y = r_num(0, size_screen);
	if (gamebord[pomme->x][pomme->y] == 0) //look if it can be fit
		if (pomme->x != 0 && pomme->y != 0)
			if(pomme->x < size_screen -1 && pomme->y < size_screen -1) 
			{
				gamebord[pomme->x][pomme->y] = -1;
				pomme->onOff = 1;
			}
}

void game_snake(char *name, int game_size)
{
	size_screen = game_size;//don't move that one 
	int scr[size_screen][size_screen];
	snake snakeInfo;
	apple appleInfo;
	char str[5];
	char chr;

	appleInfo.x = 0 , appleInfo.y = 0;
	appleInfo.onOff = 0;
	srand(time(0));

	snakeInfo.score = 0;
	snakeInfo.snakeSize = size_screen /2;//snake size start at 2/ of the game board 
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
		while (appleInfo.onOff == 0) //try to fit a apple on the map
			apples(&appleInfo, scr);
		image(scr, snakeInfo.snakeSize);
		printf("___________________\nscore = %d\n", snakeInfo.score);
		write(1,"\x1B[33maswd\x1B[0m to \x1B[32mmove\x1B[0m, \x1B[31mx to exit\x1B[0m\n", 52);
		get_str(str,1);
		chr = str[0];
		switch (chr)
		{
		case 'w':
			move(scr ,'w', -1 , &snakeInfo, &appleInfo);
			break;

		case 's':
			move(scr ,'s', 1 , &snakeInfo, &appleInfo);
			break;

		case 'a':
			move(scr ,'a', -1 , &snakeInfo, &appleInfo);
			break;

		case 'd':
			move(scr ,'d', 1 , &snakeInfo, &appleInfo);
			break;

		case 'x':
			snakeInfo.gameOn = 0;
			break;
		
		default:
			break;
		}
	}
	lost(snakeInfo.score, name);
	return;
}
//hi