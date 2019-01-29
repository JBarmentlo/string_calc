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

char *div_two_pow(char *out, long long pow)
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

long long get_pow(long double nb)
{
	char *bits;
	long long out;
	int i;

	i = 0;
	out = 0;
	bits = print_bits(&nb, 16);
	while (i < 15)
	{
		out = 2 * out + (bits[6 * 8 + 1 + i] == '1');
		i++;
	}
	free (bits);
	return (out - 16383);
}

long long get_mantissa(long double nb)
{
	char *bits;
	long long out;
	int i;

	i = 0;
	out = 0;
	bits = print_bits(&nb, 16);
	while (i < 52)
	{
		out = 2 * out + (bits[8 * 8 + i] == '1');
		i++;
	}
	free (bits);
	return (out);
}

char	*rm_0(char *str)
{
	int zeroes;
	int k;
	char *out;

	k = 0;
	zeroes = 0;
	while (str && str[zeroes] == '0')
		zeroes++;
	out = (char*)malloc(ft_strlen(str) - zeroes);
	while (str[zeroes])
	{
		out[k++] = str[zeroes++];
	}
	out[k] = '\0';
	free(str);
	return (out);
}
int main(void)
{


	long double db =18.9;
	char *out;
	int i;

	i = get_pow(db);
	out = malloc(30);
	out = ft_strdup("2659938529915699");
	out = div_two_pow(out, 51 - i);
	printf("%s\n", print_spaced_bits(&db, 16));
//	printf("%lld\n",get_mantissa(db));
//	printf("%d\n", i);
	printf("%s\n",out);
	printf("%s\n",rm_0(out));
	printf("%.47Lf\n", db);
}
