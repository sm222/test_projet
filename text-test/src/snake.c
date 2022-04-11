#include <stdio.h>
#include <unistd.h>
static int size_screen = 10;

void menu_code(char *str);

void printMap(int st[size_screen][size_screen], int x , int y,int snakeInfo)
{
	x = 0, y = 0;
	write(1, "\e[1;1H\e[2J", 10);
	while (y < size_screen)
	{
		while (x < size_screen)
		{
			if (st[x][y] +1 == snakeInfo)
				write(1, "H", 1);
			else if (y == 0 || y == size_screen -1) 
				write(1, "-", 1);
			else if (x == 0 || x == size_screen -1)
				write(1, "|", 1);
			else if (st[x][y] > 0)
				write(1, "O", 1);
			else if (st[x][y] == 0)
				write(1, " ", 1);
			write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
	write(1, "wasd to move, x to leave\n", 26);
}

void clean(int st[size_screen][size_screen], int x , int y)
{
	x = 0; 
	y = 0;
	while (y < size_screen)
	{
		while (x < size_screen)
		{
			if (st[x][y] > 0)
				st[x][y]--;
			x++;
		}
		x = 0;
		y++;
	}
}

void lose(int *point, char *str)
{
	write(1, "\e[1;1H\e[2J", 10);
	printf("the bord was %d, you lose at %d points\n",size_screen , point[3]);
    menu_code(str);
}



void game_snake(char *name, int game_size)
{
	size_screen = game_size; 
	int scr[size_screen][size_screen];
	int gameOn;
	int snakeInfo[5]; //0 is size,1 is x 2 is y, 3 is score 
	char chr;

    printf("\e[1;1H\e[2J");
	snakeInfo[3] = 4;
	snakeInfo[0] = 4;
	snakeInfo[1] = 0, snakeInfo[2] = 0;
	while (snakeInfo[2] < size_screen)
	{
		while (snakeInfo[1] < size_screen)
		{
			scr[snakeInfo[1]][snakeInfo[2]] = 0;		
			snakeInfo[1]++;
		}
		snakeInfo[1] = 0;	
		snakeInfo[2]++;
	}
	scr[size_screen / 2][size_screen / 2] = snakeInfo[0];
	snakeInfo[1] = size_screen / 2; //x
	snakeInfo[2] = size_screen / 2; //y
	gameOn = 1;
	
	while (gameOn == 1)
	{
		write(1, "\n", 1);
		printMap(scr, snakeInfo[1], snakeInfo[2], snakeInfo[0]);
		scanf("%c", &chr);
		switch(chr)
		{
			case 'w':
				snakeInfo[2]--;
				if (scr[snakeInfo[1]][snakeInfo[2]] > 0 || snakeInfo[2] == 0 || snakeInfo[2] == size_screen -1)
					gameOn = 0;
				clean(*scr, 0 ,0);
				scr[snakeInfo[1]][snakeInfo[2]] = snakeInfo[0];
				snakeInfo[0]++;
				snakeInfo[3]++;
				break;

			case 'a':
				snakeInfo[1]--;
				if (scr[snakeInfo[1]][snakeInfo[2]] > 0 || snakeInfo[1] == 0 || snakeInfo[1] == size_screen -1)
					gameOn = 0;
				clean(*scr, 0 ,0);
				scr[snakeInfo[1]][snakeInfo[2]] = snakeInfo[0];
				snakeInfo[0]++;
				snakeInfo[3]++;
				break;

			case 'd':
				snakeInfo[1]++;
				if (scr[snakeInfo[1]][snakeInfo[2]] > 0 || snakeInfo[1] == 0 || snakeInfo[1] == size_screen -1)
					gameOn = 0;
				clean(*scr, 0 ,0);
				scr[snakeInfo[1]][snakeInfo[2]] = snakeInfo[0];
				snakeInfo[0]++;
				snakeInfo[3]++;
				break;

			case 's':
				snakeInfo[2]++;
				if (scr[snakeInfo[1]][snakeInfo[2]] > 0 || snakeInfo[2] == 0 || snakeInfo[2] == size_screen -1)
					gameOn = 0;
				clean(*scr, 0 ,0);
				scr[snakeInfo[1]][snakeInfo[2]] = snakeInfo[0];
				snakeInfo[0]++;
				snakeInfo[3]++;
				break;
				
			case 'x':
				gameOn = 0;
				break;

			default:
				break;
		}
		
	}
	lose(snakeInfo, name);
	return (0);
}