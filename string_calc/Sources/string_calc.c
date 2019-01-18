#include <stdio.h> //LIUAHGFKHSDBFKJSDGH
#include <string.h>
#include <libc.h>
#include "strc.h"

int get(char *str, int i)
{
	if (i < 0)
		return (0);
	return (str[i] - '0');
}


void 	retenues(char *str) //doesnt't handle negatives
{
	int i;

	i = ft_strlen(str);
	i = i - (i != 0);
	while (i != -1)
	{
		while (get(str, i) >= 10)
		{
			str[i] -= 10;
			if (i == 0)
			{
				strgrow(str);
				i++;
			}
			str[i - 1] = str[i - 1] + 1;
		}
		while (get(str, i) < 0)
		{
			str[i] = str[i] + 10;
			if (i != 0)							//BULLSHIT FOR NEGATIVES
				str[i - 1] = str[i - 1] - 1;
			else
				str[0] = '-';					//visibility
		}
		i--;
	}
}

void 	add(char *out, char *add) //OPTIMISE IF ADD < OUT
{
	char 	*tmp;
	int 	i;
	int 	size;

	i = 1;
	size = max(ft_strlen(out), ft_strlen(add));
	tmp = ft_strdup(out);
	free (out);
	out = str_alloc(size , '0');

	while (i <= size)
	{
		out[size - i] = get(tmp, ft_strlen(tmp) - i) + get(add, ft_strlen(add) - i) + '0';
		i++;
	}
	free (tmp);
	retenues(out);
}

void multiply(char *out, int nb)
{
	int 	i;

	i = 0;
	while (out[i])
	{
		out[i] = (out[i] - '0') * nb + '0';
		i++;
	}
//	printf("out :%s\n", out );
	retenues(out);
}

char *pow_two(int pow) //OPTIMIZE THE MULTIPLY NOT 2 BY 2 BUT 2^4
{
	char *out;
	int i;

	i = 0;
	out = str_alloc(1, '1');
	while (i < pow)
	{
		multiply(out, 2);
		i++;
	}
	return (out);
}

void div_two(char *out)
{
	int ret;
	int retold;
	int i;

	retold = 0;
	ret = 0;
	i = 0;
	while (out[i])
	{
		if ((out[i] - '0') % 2 == 1)
			ret = 5;
		out[i] = (out[i] - '0') / 2 + '0' + retold;
		retold = ret;
		ret = 0;
		i++;
	}
}

int main(void)
{

	char *one;
	char *two;
	t_str_nb *john;

	john = NULL;
	one = ft_strdup("7777");
	two = ft_strdup("4444");
	div_two(one);
	printf("one :%s\n", pow_two(50));
}
