/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:57:41 by arodiono          #+#    #+#             */
/*   Updated: 2016/12/02 15:26:29 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	len(const char *s, char c)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			x++;
		i++;
	}
	return (x);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	int		l;
	int		x;
	int		y;
	char	**r;

	i = 0;
	x = 0;
	if (s == NULL || !(r = (char**)malloc(sizeof(char*) * len(s, c) + 1)))
		return (NULL);
	while (i < ft_strlen(s))
	{
		if (s[i] != c && s[i] != '\0')
		{
			y = i;
			l = 0;
			while (s[i] != c && s[i++] != '\0')
				l++;
			r[x] = ft_strsub(s, y, l);
			x++;
		}
		i++;
	}
	r[x] = 0;
	return (r);
}
