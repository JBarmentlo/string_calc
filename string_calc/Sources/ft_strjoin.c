/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:36:09 by jbarment          #+#    #+#             */
/*   Updated: 2018/11/22 11:31:11 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <string.h>
#include "printf.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dstore;

	dstore = dst;
	while (n--)
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
	}
	return (dstore);
}

char	*ft_strnew(size_t size)
{
	char	*out;

	out = (char*)malloc(size + 1);
	out[size] = '\0';
	return(out);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2 == NULL)
	{
		while (s1[i])
			i++;
		if (!(out = ft_strnew(i)))
			return (NULL);
		ft_memcpy((void*)out, (void*)s1, i + 1);
		return (out);

	}
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(out = (char*)malloc(i + j + 1)))
		return (NULL);
	ft_memcpy((void*)out, (void*)s1, i);
	ft_memcpy((void*)(out + i), (void*)s2, j + 1);
	return (out);
}

char 	*ft_strjoin_free(char *out, char *add)
{
	char *tmp;

	tmp = out;
	out = ft_strjoin(tmp, add);
	free(tmp);
	return (out);
//	free(add);
}
