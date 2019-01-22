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

char	*print_bin(unsigned char nb, int iter) // UNPROTECTED !!!!! needs if (out) everywhere
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
		out = print_bin(nb / ft_strlen(str), iter + 1);
		out[ft_strlen(out) - iter - 1] = str[nb % ft_strlen(str)];
	}
	return (out);
}

#include <stdio.h>
int print_bits(long double *nb)
{
	unsigned char *db;
	int i;

	i = 0;
	db = (unsigned char*)nb;
	while (i < 8)
		printf("%s ", print_bin(db[i++], 0));
	return (1);
}
