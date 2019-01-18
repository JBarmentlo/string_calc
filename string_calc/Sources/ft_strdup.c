/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:09:33 by jbarment          #+#    #+#             */
/*   Updated: 2018/11/22 11:21:50 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strc.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*out;

	if (!(out = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		out[i] = src[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
