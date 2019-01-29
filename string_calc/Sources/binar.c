#include <libc.h>
#include <string.h>
#include "strc.h"

static char	*malloc_out(int size)
{
	char	*out;
	int		i;

	i = 0;
	if(!(out = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size - 1)
	{
		out[i] = '+';
		i++;
	}
	out[size - 1] = '\0';
	return (out);
}

char	*print_binary(unsigned char nb, int iter) // UNPROTECTED !!!!! needs if (out) everywhere
{
	char	*out;
	char 	*str;
	int		i;

	str = "01";
	i = 0;
	if (iter == 7)
	{
		out = malloc_out(iter + 2);
		out[0] = str[nb % ft_strlen(str)];
	}
	else
	{
		out = print_binary(nb / ft_strlen(str), iter + 1);
		out[ft_strlen(out) - iter - 1] = str[nb % ft_strlen(str)];
	}
	return (out);
}

char	*print_bin(unsigned char nb)
{
	return (print_binary(nb, 0));
}

char *print_bits(void *nb, int octets)
{
	unsigned char *db;
	char *out;
	int i;
	int j;

	j = 0;
	i = 0;
	db = (unsigned char*)nb;
	out = (char*)malloc(8 * octets + 1);
	out[8 * octets] = '\0';
	while (i < octets)
	{
		j = 0;
		while (j < 8)
		{
			out[8 * i + j] = print_bin(db[octets - i - 1])[j];
			j++;
		}
		i++;
	}
	return (out);
}

char *print_spaced_bits(void *nb, int octets)
{
	unsigned char *db;
	char *out;
	int i;
	int j;

	j = 0;
	i = 0;
	db = (unsigned char*)nb;
	out = (char*)malloc(9 * octets + 1);
	out[9 * octets] = '\0';
	while (i < octets)
	{
		j = 0;
		while (j < 8)
		{
			out[9 * i + j] = print_bin(db[octets - i - 1])[j];
			j++;
		}
		out[9 * i + j] = ' ';
		i++;
	}
	return (out);
}
