/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:13:16 by arodiono          #+#    #+#             */
/*   Updated: 2016/12/02 15:26:06 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		x;
	int		y;
	char	*r;

	i = 0;
	y = 0;
	if (!s)
		return (NULL);
	x = ft_strlen(s);
	while (s[i] < 33)
		i++;
	while (s[x] < 33)
		x--;
	if (x - i < 0)
		r = (char*)malloc(sizeof(char) * 1);
	else
		r = (char*)malloc(sizeof(char) * (x - i) + 2);
	if (r == NULL)
		return (NULL);
	while (x + 1 > i)
		r[y++] = s[i++];
	r[y] = '\0';
	return (r);
}
