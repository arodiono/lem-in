/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:57:37 by arodiono          #+#    #+#             */
/*   Updated: 2016/12/02 15:29:06 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	size_t	y;
	char	*r;

	x = 0;
	y = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(r = (char*)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[x] != '\0')
	{
		r[x] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
	{
		r[x++] = s2[y];
		y++;
	}
	r[x] = '\0';
	return (r);
}
