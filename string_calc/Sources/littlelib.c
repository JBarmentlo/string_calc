#include <libc.h>
#include "strc.h"


void 	strgrow(char *src)
{
	int		i;
	char    *tmp;

	tmp = ft_strdup(src);
	free(src);
	if (!(src = malloc(sizeof(char) * (ft_strlen(tmp) + 2))))
		return ;
	i = 0;
	src[0] = '0';
	while ((tmp)[i])
	{
		src[i + 1] = tmp[i];
		i++;
	}
	src[i + 1] = '\0';
	free(tmp);
}

int 	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

char	*str_alloc(int size, char c)
{
	char	*out;
	int		i;

	if (!(out = (char*)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		out[i++] = c;
	out[i] = '\0';
	return (out);
}
