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

char *div_two(char *out)
{
	int ret;
	int retold;
	int i;
	int comma;

	retold = 0;
	comma = 0;
	ret = 0;
	i = 0;
	while (out[i])
	{
		if (out[i] == '.' && ++i) //check
			comma = 1;
		if ((out[i] - '0') % 2 == 1)
			ret = 5;
		out[i] = (out[i] - '0') / 2 + '0' + retold;
		retold = ret;
		ret = 0;
		i++;
	}
	if (retold != 0)
	{
		if (comma)
			out = ft_strjoin_free(out, "5");
		else
		{
			out = ft_strjoin_free(out, ".5");
		}
	}
	return (out);
}

char *div_two_pow(char *out, int pow)
{
	while (pow--)
		out = div_two(out);
	return (out);
}

char *nice_split(char *str)
{
	char *out;
	int i;

	i = 0;
	out = (char*)malloc(128 + 1 + 2);
	out[0] = str[0];
	out[1] = ' ';
	out[130] = '\0';
	while (i < 15)
	{
		out[2 + i] = str[1 + i];
		i++;
	}
	out[2 + i] = ' ';
	while (i < 127)
	{
		out[3 + i] = str[i + 1];
		i++;
	}
	return (out);
}

#include <math.h>
int main(void)
{

	char *one;
	char *two;

	one = ft_strdup("7777");
	two = ft_strdup("4444");
//	one = div_two_pow(one, 10000);

	//add(one, two);
//	printf("one :%s\n", one);
	free (one);
	free (two);
	//printf("two :%s\n", two);

/*

	double *full = malloc(8);
	unsigned char *parse= (unsigned char*)full;
	for (int i = 0; i < 8; i++)
		parse[i] = 255;
	//full = 3.3621031431120935062626778173217519551 / (long double)pow(10, 4932)
		//printf("%zu\n", sizeof(long double));
	long double db = (long double)*full;

	printf("%s\n", print_bits(&db, 16));
*/

	long double db =1.0;
	long double db2 = 1.0/3;
	printf("%s\n", print_bits(&db, 16));
	printf("%s\n", print_bits(&db2, 16));
/*
	print_bits(&on);
	printf("\n");
	print_bits(&small);
*/

/*
	int i = 0;
	unsigned char *cc;
	cc = (unsigned char*)&small;
	while (i < 25)
	{
		printf("%hhi ", cc[i]);
		i++;
	}
*/
	//printf("ull :%lu ld :%lu\n", sizeof(unsigned long long), sizeof(long double) );

/*
	unsigned char uc;
	uc = 255;
	printf("%s\n", print_bin(uc));
	printf("\n");
*/
}
