#include<unistd.h>

void    print_top(char *input, char *str_list)
{
    int pos;
    int i;
    int find;

    pos = 0;
    while(input[pos])
    {
        i = 0;
        find = 0;
        while(str_list[i])
        {
            if (str_list[i] == input[pos])
            {
                write(1," _ ", 3);
                find = 1;
                break;
            }
            i++;
        }
        if(find == 0)
            write(1,"   ",3);
        pos++;
    }
}

void    print_case(char input, char *str_list,char char_i)
{
    int i;
    int find;

    i = 0;
    find = 0;
    while (str_list[i])
    {
        if(str_list[i] == input)
        {
            find = 1;
            write(1,&char_i,1);
            break;
        }
        i++;
    }
    if(find == 0)
        write(1," ",1);
}

void    print_middle(char *input, char *left, char *mid,char *rig)
{
    int pos;

    pos = 0;
    while(input[pos])
    {
        print_case(input[pos],left,'|');
        print_case(input[pos],mid,'_');
        print_case(input[pos],rig,'|');
        pos++;
    }
}
void    defi(char *text)
{
    print_top(text,"78956230acefgkmnopqrsz");
    write(1,"\n",1);

    print_middle(text,
    "894560abcefghiklnopqrstuvwxy",
    "8945623abdefhkpqstxzy",
    "78941230adjnopqruvwxzy");
    write(1,"\n",1);
    
    print_middle(text,
    "8620abcdefghijklmnoprtux",
    "8956230bcdegjlostuvwyz",
    "789456130abdghjkmnoqsuvxy");
    write(1,"\n",1);
}
/*
print_topop
print_middleiddle
print_bottom
*/