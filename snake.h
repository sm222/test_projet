


#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RED		"\x1B[31m"
#define GRN		"\x1B[32m"
#define YEL		"\x1B[33m"
#define BLU		"\x1B[34m"
#define MAG		"\x1B[35m"
#define CYN		"\x1B[36m"
#define WHT		"\x1B[37m"
#define RESET	"\x1B[0m"
#define CLE "\e[1;1H\e[2J"

typedef struct snake {
	int x;
	int y;
	int snakeSize;
	int score;
	int gameOn;
} snake;

typedef struct apple {
	int x;
	int y;
	int onOff;
} apple;

static int size_screen;

int		num(void);
void	lost(int point, char *str);
void	image(int (*scr)[size_screen], int size);
void	move(int (*game)[size_screen], char key, int dir, snake *info, apple *fruit);
void	apples(apple *pomme, int gameboard[size_screen][size_screen]);
void	game_snake(char *name, int game_size);
void	signature(void);
int		ft_atoi(char *str);
void	menu_code(char *str);

#endif