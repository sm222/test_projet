

#include "../include.h"

void	sm_putchar(char c)
{
	write(1, &c, 1);
}

int	sm_while_space(char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return(1);

	return(-1);
}

void	sm_put_number(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		sm_put_number(nb * -1);
	}
	else if (nb > 9)
	{
		sm_put_number(nb / 10);
		sm_putchar(nb % 10 + '0');
	}
	else
		sm_putchar(nb + '0');
}

int sm_while_space_tab(int start,char *str)
{
	int i = start;
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	return(i);
}

int sm_str_size(char *input)
{
	int i = 0;
	while (input[i])
		i++;
	return i;
}

/*use to grab a str form the user
size is the number letters user can type
*/
int	sm_get_keybord_input(char *return_txt,int size)
{
    if(fgets(return_txt,size + 1,stdin))
    {
        char *p;
        if((p = strchr(return_txt, '\n')))
        {//check exist newline
            *p = 0;
        }
        else
        {
            scanf("%*[^\n]");
            scanf("%*c");
        }
    }
	return(sm_str_size(return_txt));
}
//was use to fix my code
//https://stackoverflow.com/questions/38767967/clear-input-buffer-after-fgets-in-c



//simple function printing a string
void	sm_print_str(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

//remove ' ' or 'tabs' at the end of a string
void sm_clear_str(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ' || str[i] == '\t')
		i--;
	str[i + 1] = '\0';
	
}

/*return a rendom number, the max being upper
before using the funck use that in your programe 'srand(time(0));'
*/
int		sm_r_num(int lower ,int upper)
{
	int swap;
	if (lower > upper)
	{
		swap = lower;
		lower = upper;
		upper = swap;
	}
	int numb = (rand() % (upper - lower + 1)) + lower;
	return(numb);
}

int	sm_atoi(char *str)
{
	//atn = 48 ascii to number 
	int	i = 0;
	int	num = 0;
	int	min = 1;
	//while space move one by one in the str 
	/*while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	*/
	while(sm_while_space(str,i) > 0)
		i++;
	//loop for '+' '-', make the number negative or positive
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = min * -1;
		i++;
	}
	//while there number 
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] -atn);
		i++;
	}
	//return number
	return (num * min);
}

//make noise on the screen
void noise(int loop, int size)
{
	int i = 0;
	int j = 0;
	int temp;

	while(i < loop)
	{
		while(j < size)
		{
			temp = sm_r_num(0,105) + 21;
			rd_color();
			write(1, &temp, 1);
			write(1, &RESET,5);
			j++;
		}
		write(1, "\n", 2);
		i++;
		j = sm_r_num(0,size);
	}
}

// pic a rendom color
void rd_color(void)
{
	int tem = sm_r_num(0,5);
	if (tem == 0)
		write(1, &RED, 6);
	if (tem == 1)
		write(1, &GRN, 6);
	if (tem == 2)
		write(1, &YEL, 6);
	if (tem == 3)
		write(1, &BLU, 6);
	if (tem == 4)
		write(1, &MAG, 6);
	if (tem == 5)
		write(1, &CYN, 6);
}

void signature(void)
{
	printf(BLU
	" ::::::::  ::::    ::::   ::::::::   ::::::::   :::::::: \n"
	":+:    :+: +:+:+: :+:+:+ :+:    :+: :+:    :+: :+:    :+:\n"
	"+:+        +:+ +:+:+ +:+       +:+        +:+        +:+ \n"
	"+#++:++#++ +#+  +:+  +#+     +#+        +#+        +#+   \n"
	"       +#+ +#+       +#+   +#+        +#+        +#+     \n"
	"       +#+ +#+       +#+   +#+        +#+        +#+     \n"
	"#+#    #+# #+#       #+#  #+#        #+#        #+#      \n"
	" ########  ###       ### ########## ########## ##########\n"
	WHT);
}

//return 1 if false return 0 if right
int sm_look_for_word(char *str,char *word)
{
	int i = 0;
	while(word[i])
	{
		if (word[i] != str[i])
			return(1);
		i++;
	}
	if (str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
		return(0);
	return(1);
}
//calculate

float	sm_get_number(char *str)
{
	float mul = 0.1;
	float val = 0;
	int i = 0;
	int i_back = 0;

	while (str[i])
	{
		if (str[i] == '.')
			break;
		i++;
	}
	if (str[i] == '\0')
		return(sm_atoi(str));
	else
	{
		i_back = i;
		i++;
		while(str[i])
		{
			val += mul * (str[i] - '0');
			mul /= 10;
			i++;
		}
		i = i_back - 1;
		mul = 1;
		while(str[i])
		{
			val += mul * (str[i] - '0');
			mul *= 10;
			i--;
		}
	}
	return(val);
}

/*
int sm_calculate(char *str)
{
	int val1;
	int val2 = 0;
	int i = sm_while_space_tab(0,str);
	if (str[i] < '0' || str[i] > '9')
		return(0);
	
	printf("%s\n",str);
	return(0);
}
*/

/*
	p = pointer
	type, char or int
	size = size of the print
	color = set the focus on one caracter
*/
void sm_inspect_arr(void *p, char type ,int size, int color)
{
	int i = 0;
	int item = 0;

	int *d = (int *)p;
	char *c = (char *)p;
	switch (type)
	{
	//for char
	case 'c':
		do
		{
			if (item == color)
				printf(RED);
			printf("/%3d",item++);
			printf(WHT);
		} while(item < size);

		printf("\n|");
		while(i < size)
		{
			if (i % 2 == 0)
				printf(YEL);
			if (i == color)
				printf(RED);
			if (c[i] == '\0')
				printf("NUL");
			else if (c[i] == '\t')
				printf(" \\t");
			else if (c[i] == '\v')
				printf(" \\v");
			else if (c[i] <= 0)
				printf("-n ");
			else if (c[i] == 127)
				printf("DEL");
			else if (c[i] > 126)
				printf("+n ");
			else if (c[i] == 31)
				printf("US ");
			else if (c[i] == 1)
				printf("SOH");
			else
				printf(" %c " ,c[i]);
			printf(RESET "|");
			i++;
		}
		if (i < size)
			printf("NUL|\n");
		else
			printf("\n");
		break;
		
	case 'i':
		while(item < size)
			printf("/%9d",item++);
		printf("\n|");
		while(i <  size)
		{
			if (i == color)
				printf(RED);
			printf("%9d|" ,d[i++]);
			printf(WHT);
		}
		printf("\n");
		break;

	case 'p':
		printf("%p\n", &p);
		break;
	
	default:
		printf(RED"%c "RESET"not reconise\n", type);
		break;
	}
}

/*
	use to find a 'word'
	str = input
	path = pos in the str
*/
int sm_func_looking(char *str,char *word, int *path)
{
	//keep the 'path' in memory 
	int i = *path;
	int back = i;
	int j = 0;
	//skip space and tab
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	//look if the word mach with the user input
	while(word[j])
	{
		if (word[j] != str[i])
		{
			*path = back;
			return(1);
		}
		j++;	
		i++;
	}
	//look with the end if the is a end or still some caracter
	if (str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
	{
		*path = i;
		return(0);
	}
	*path = back;
	return(1);
}

/*
	look for a word with the letter in any order
		str = user input
		word = the word you are looking for in the user input
		path =  the position in the user input
*/
int sm_find_mix_str(char *str,char *word, int *path)
{
	// grab the place were it start looking in the str
	int back = *path;
	// use to copy the word 
	char look_for[14];
	// use to move in the str
	int i = back;
	// use to move in look_for
	int j = 0;
	// skip space and tab
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	// if the str end return 1
	if (str[i] == '\0')
	{
		*path = back;
		return(1);
	}
	// copy the 'word' in 'look_for' 
	while(word[j])
	{
		look_for[j] = word[j];
		j++;
	}
	// add a marker for the loop logic, and terminate it 
	look_for[j] = '\r';
	j++;
	look_for[j] = '\0';
	j = 0;
	// loop while the word don't end it the user input
	while(str[i] != '\0' && str[i] != 32 && str[i] != '\t')
	{
		// look for letter one by one
		while(look_for[j])
		{
			// if get to the marker with out finding one, return 1
			if (look_for[j] == '\r')
			{
				*path = back;
				return(1);
			}
			// if find one, change the letter so it don't compare it 2 time
			else if(look_for[j] == str[i])
			{
				look_for[j] = '\a';
				j = 0;
				break; 
			}
			j++;
		}
		i++;
	}
	j = 0;
	// look to see if all letter was found
	while(look_for[j])
	{
		if(look_for[j] != '\a' && look_for[j] != '\r')
		{
			*path = back;
			return(1);
		}
	j++;
	}
	// success
	*path = i;
	return(0);
}

/*
https://stackoverflow.com/questions/33677992/how-to-move-cursor-back-to-the-first-line-in-c
*/

/*
	input = the source
	return_v = copy pos
	start_p =  zone were the copy start in 'input'
	end_p =  set the end of the copy(number of caracter)
		(set to under zero to put no limit)
*/
int sm_copy_str_to(char *input,char *return_v,int start_p, int end_p) 
{
	int i = start_p;
	int j = 0;

	if (end_p < 0)
		end_p = 100000;
	if(input[i] == '\0' || input[i] == ' ' || input[i] == '\t' || end_p == 0)
		return(0);
	while(input[i] != '\0' && j < end_p)
	{
		return_v[j] = input[i];
		j++;
		i++;
	}
	return_v[j] = '\0';
	return(j);
}

int sm_look_for_char_p(char *str, int start_p ,int number ,char look)
{
	int i = start_p;
	int count = 0;
	
	while(str[i])
	{
		if (count == number)
			return(i);
		if (str[i] == look)
			count++;
		i++;
	}
	return(0);
}

void *sm_calloc(size_t type, int size)
{
	char *p;
	p = malloc(type * size);
	while (size >= 0)
		p[size--] = 0;
	return(void *)p;
}
