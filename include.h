


#ifndef include_H
#define include_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
//test
#include <fcntl.h>

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
//int		sm_calculate(char *str);
float	sm_get_number(char *str);

//simple functions

void	signature(void);
void	sm_print_str(const char *str);
void 	rd_color(void);
int		sm_r_num(int lower ,int upper);
int		sm_atoi(char *str);
void	noise(int loop, int size);
int	sm_while_space_tab(int start,char *str);

//snake game

static int size_screen;
void	lost(int point, char *str);
void	image(int (*scr)[size_screen], int size);
void	move(int (*game)[size_screen], char key, int dir, snake *info, apple *fruit);
void	apples(apple *pomme, int gameboard[size_screen][size_screen]);
void	game_snake(char *name, int game_size);

//other

void	sm_inspect_arr(void *p, char type ,int size, int color);

//text functions

void	sm_putchar(char c);
void	sm_put_number(int nb);
int	sm_str_size(char *input);
void	give_arg_v(char *str,char *returnV, int p);
int		get_argP_from_str(char *str,char look_for,int arg_p);
int		sm_look_for_word(char *str,char *word);
int 	number_arg(char *str,char look_for);
void	sm_clear_str(char *str);
int	sm_get_keybord_input(char *return_txt,int size);

//new menu test code

void menu_loop(char *name,char *call_back);
int sm_func_looking(char *str,char *word, int *path);
int sm_find_mix_str(char *str,char *word, int *path);
int sm_copy_str_to(char *input,char *return_v,int start_p, int end_p);
int sm_look_for_char_p(char *str,int start_p ,int number ,char look);
//new game
void defi(char *text);
void ft_print_comb2(void);
//
void *sm_calloc(size_t type, int size);
//test funk
int print_file(char *name);

#endif