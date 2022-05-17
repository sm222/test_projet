

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
	{
		write(1, &str[i], 1);
		i++;
	}
	
}

//find a character of a string, select witch one you want to send back
// the potiont in the str
int		get_argP_from_str(char *str,char look_for,int arg_p)
{
	int	i = 0;
	int arg = 0;
	while(str[i])
	{
		if(str[i] == ' ')
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
		if (str[i] == ' ')
			if (str[i + 1] == look_for)
				argN++;
		i++;
	}
	return(argN);
}

//remove ' ' at the end of a string
void clear_str(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	i = i -1;
	while (str[i] == ' ')
		i--;
	str[i + 1] = '\0';
	
}

//return a rendom number, the max being upper
int		rNum(int upper)
{
	int lower = 0;
	int numb = (rand() % (upper - lower + 1)) + lower;
	return(numb);
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	num = 0;
	int	min = 1;

	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = min * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] -atn);
		i++;
	}
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
			temp = rNum(105) + 21;
			rd_color();
			write(1, &temp, 1);
			write(1, &RESET,5);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = rNum(size);
	}
}

// pic a rendom color
void rd_color(void)
{
	int tem = rNum(5);
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
	printf(RESET);
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
	return(0);
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
	while(str[i] >= '0' && str[i] <= '9')
		i++;
	val = get_number(str,i);
	while(str[i])
	{
		while(str[i] == ' ')
			i++;
		op = str[i++];
		while(str[i] == ' ')
			i++;
		while(str[i] >= '0' && str[i] <= '9')
			i++;
		temp = get_number(str,i);
		switch (op)
		{
		case '+':
			val = val + temp;
			break;
		
		case '-':
			val = val - temp;
			break;
		
		case '*':
			val = val * temp;
			break;

		case '/':
			val = val / temp;
			break;
		
		case '%':
			val = val % temp;
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
		i = i * 10;
		p--;
	}
	return(val);
}