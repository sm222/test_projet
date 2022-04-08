#include <stdio.h>
#include <unistd.h>
#define M 40
#define N 40
void menu_code(char *str);

void printMap(int st[40][40], int x , int y,int snakeInfo)
{
	x = 0, y = 0;
	write(1, "\e[1;1H\e[2J", 10);
	while (y < 40)
	{
		while (x < 40)
		{
			if (st[x][y] +1 == snakeInfo)
				write(1, "H", 1);
			else if (y == 0 || y == 39) 
				write(1, "-", 1);
			else if (x == 0 || x == 39)
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
}

void clean(int st[40][40], int x , int y)
{
	x = 0; 
	y = 0;
	while (y < 40)
	{
		while (x < 40)
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
	printf("points %d\n", point[3]);
    menu_code(str);
}

void	test(char *str[M][N])
{
	str[4][5] = 10;
}

void game_snake(char *name)
{
	int scr[40][40];
	int gameOn;
	int snakeInfo[5]; //0 is size,1 is x 2 is y, 3 is score 
	char chr;

    printf("\e[1;1H\e[2J");
	snakeInfo[3] = 4;
	snakeInfo[0] = 4;
	snakeInfo[1] = 0, snakeInfo[2] = 0;
	while (snakeInfo[2] < 40)
	{
		while (snakeInfo[1] < 40)
		{
			scr[snakeInfo[1]][snakeInfo[2]] = 0;		
			snakeInfo[1]++;
		}
		snakeInfo[1] = 0;	
		snakeInfo[2]++;
	}

	test(&scr);


	scr[20][20] = snakeInfo[0];
	snakeInfo[1] = 20; //x
	snakeInfo[2] = 20; //y
	gameOn = 1;
	
	while (gameOn == 1)
	{
		write(1, "\n", 1);
		printMap(scr, snakeInfo[1], snakeInfo[2], snakeInfo[0]);
		scanf("%c", &chr);
		if (chr == 'w')
		{
			snakeInfo[2]--;
			if (scr[snakeInfo[1]][snakeInfo[2]] > 0 || snakeInfo[2] == 0 || snakeInfo[2] == 39)
				gameOn = 0;
			clean(*scr, 0 ,0);
			scr[snakeInfo[1]][snakeInfo[2]] = snakeInfo[0];
			snakeInfo[0]++;
			snakeInfo[3]++;
		}
		if (chr == 'a')
		{
			snakeInfo[1]--;
			if (scr[snakeInfo[1]][snakeInfo[2]] > 0 || snakeInfo[1] == 0 || snakeInfo[1] == 39)
				gameOn = 0;
			clean(*scr, 0 ,0);
			scr[snakeInfo[1]][snakeInfo[2]] = snakeInfo[0];
			snakeInfo[0]++;
			snakeInfo[3]++;
		}
		if (chr == 'd')
		{
			snakeInfo[1]++;
			if (scr[snakeInfo[1]][snakeInfo[2]] > 0 || snakeInfo[1] == 0 || snakeInfo[1] == 39)
				gameOn = 0;
			clean(*scr, 0 ,0);
			scr[snakeInfo[1]][snakeInfo[2]] = snakeInfo[0];
			snakeInfo[0]++;
			snakeInfo[3]++;
		}
		if (chr == 's')
		{
			snakeInfo[2]++;
			if (scr[snakeInfo[1]][snakeInfo[2]] > 0 || snakeInfo[2] == 0 || snakeInfo[2] == 39)
				gameOn = 0;
			clean(*scr, 0 ,0);
			scr[snakeInfo[1]][snakeInfo[2]] = snakeInfo[0];
			snakeInfo[0]++;
			snakeInfo[3]++;
		}
	}
	lose(snakeInfo, name);
	return (0);
}