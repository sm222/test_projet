


#ifndef include_H
#define include_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

#define RED		"\x1B[31m"
#define GRN		"\x1B[32m"
#define YEL		"\x1B[33m"
#define BLU		"\x1B[34m"
#define MAG		"\x1B[35m"
#define CYN		"\x1B[36m"
#define WHT		"\x1B[37m"
#define RESET	"\x1B[0m"
#define CLE "\e[1;1H\e[2J"

//ascii to number
#define atn 48

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


//menu function
void	tictactoe(char *user);
void	menu_code(char *str,char *input_loop);
int		calculate(char *str);
int		get_number(char *str,int p);

//simple functions

void	signature(void);
void	print_str(char *str);
void 	rd_color(void);
int		r_num(int lower ,int upper);
int		ft_atoi(char *str);
void	noise(int loop, int size);

//snake game

static int size_screen;
void	lost(int point, char *str);
void	image(int (*scr)[size_screen], int size);
void	move(int (*game)[size_screen], char key, int dir, snake *info, apple *fruit);
void	apples(apple *pomme, int gameboard[size_screen][size_screen]);
void	game_snake(char *name, int game_size);

//other

void	math_game(char *str);
void print_str2(void *p, char type ,int size, int color);

//text functions

void	give_arg_v(char *str,char *returnV, int p);
int		get_argP_from_str(char *str,char look_for,int arg_p);
int		look_for_func(char *str,char *word);
int 	number_arg(char *str,char look_for);
void	clear_str(char *str);
void	get_str(char *return_txt,int size);

//new menu test code

void menu_loop(char *name);
int func_looking(char *str,char *word, int *path);
int mix(char *str,char *word, int *path);

//new game



#endif