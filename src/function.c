

#include "../include.h"

/*use to grab a str form the user
size is the number letters user can type
*/
void    get_str(char *return_txt,int size)
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
}
//was use to fix my code
//https://stackoverflow.com/questions/38767967/clear-input-buffer-after-fgets-in-c

//simple function printing a string
void	print_str(char *str)
{
	int i = 0;
	
	while (str[i])
		write(1, &str[i++], 1);
}

//find a character of a string, select witch one you want to send back
// the potiont in the str
int		get_argP_from_str(char *str,char look_for,int arg_p)
{
	int	i = 0;
	int arg = 0;
	while(str[i])
	{
		if(str[i] == ' ' || str[i] == '\t')
			if(str[i + 1] == look_for)
			{
				arg++;
				if (arg == arg_p)
					return(i + 2);
			}
		i++;
	}
	return(0);
}

int number_arg(char *str,char look_for)
{
	int i = 0;
	int argN = 0;
	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			if (str[i + 1] == look_for)
				argN++;
		i++;
	}
	return(argN);
}

//remove ' ' or 'tabs' at the end of a string
void clear_str(char *str)
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
int		r_num(int lower ,int upper)
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

int	ft_atoi(char *str)
{
	//atn = 48 ascii to number 
	int	i = 0;
	int	num = 0;
	int	min = 1;
	//while space move one by one in the str 
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	//loop for '+' '-', make the number negatif or positif 
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
			temp = r_num(0,105) + 21;
			rd_color();
			write(1, &temp, 1);
			write(1, &RESET,5);
			j++;
		}
		write(1, "\n", 2);
		i++;
		j = r_num(0,size);
	}
}

// pic a rendom color
void rd_color(void)
{
	int tem = r_num(0,5);
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
	printf(BLU);
	printf(" ::::::::  ::::    ::::   ::::::::   ::::::::   ::::::::  \n");
	printf(":+:    :+: +:+:+: :+:+:+ :+:    :+: :+:    :+: :+:    :+: \n");
	printf("+:+        +:+ +:+:+ +:+       +:+        +:+        +:+  \n");
	printf("+#++:++#++ +#+  +:+  +#+     +#+        +#+        +#+    \n");
	printf("       +#+ +#+       +#+   +#+        +#+        +#+      \n");
	printf("       +#+ +#+       +#+   +#+        +#+        +#+      \n");
	printf("#+#    #+# #+#       #+#  #+#        #+#        #+#       \n");
	printf(" ########  ###       ### ########## ########## ########## \n");
	printf(WHT);
}

//return 1 if false return 0 if right
int look_for_func(char *str,char *word)
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

//return a str of a arg chose by get_argP_from_str
void give_arg_v(char *str,char *returnV, int p)
{
	int i = 0;
	while(str[p] == ' ')
		p++;
	while(str[p] >= 33 && str[p] <= 126)
	{
		returnV[i] = str[p];
		i++;
		p++;
	}
	returnV[i] = '\0';
}

int calculate(char *str)
{
	int i = 0;
	int temp = 0;
	int val = 0;
	char op;

	while(str[i] == ' ')
		i++;
	if (str[i] == '-')
		{
			while(str[i] >= '0' && str[i] <= '9')
				i++;
			val = get_number(str,i) *-1;
		}
		else
		{
			while(str[i] >= '0' && str[i] <= '9')
				i++;
			val = get_number(str,i);
		}
	while(str[i])
	{
		while(str[i] == ' ')
			i++;
		op = str[i++];
		while(str[i] == ' ')
			i++;
		if (str[i] == '-')
		{
			while(str[i] >= '0' && str[i] <= '9')
				i++;
			temp = get_number(str,i) *-1;
		}
		else
		{
			while(str[i] >= '0' && str[i] <= '9')
				i++;
			temp = get_number(str,i);
		}
		
		switch (op)
		{
		case '+':
			val += temp;
			break;
		
		case '-':
			val -= temp;
			break;
		
		case '*':
			val *= temp;
			break;

		case '/':
			val /= temp;
			break;
		
		case '%':
			val %= temp;
			break;
		
		default:
			if (op >= '0' && op <= '9')
				printf(RED"%c "RESET"was missing a operator\n", op);
			else
				printf(RED"%c "RESET"is invalid\n", op);
			break;
		}
	}
	return(val);
}

int get_number(char *str,int p)
{
	int i = 1;
	int val = 0;
	int temp;
	p--;
	while(str[p] >= '0' && str[p] <= '9')
	{
		temp = str[p] -atn;
		val = val + (temp * i);
		i *= 10;
		p--;
	}
	return(val);
}

void print_str2(void *p, char type ,int size, int color)
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

//use to find a 'word' 
int func_looking(char *str,char *word, int *path)
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
int mix(char *str,char *word, int *path)
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
	// look to see if all latter was found
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
