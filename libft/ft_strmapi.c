/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:30:39 by arodiono          #+#    #+#             */
/*   Updated: 2016/12/02 15:21:42 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*r;

	i = 0;
	if (s)
	{
		r = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (r != NULL && s != NULL)
		{
			while (s[i] != '\0')
			{
				r[i] = f(i, s[i]);
				i++;
			}
			r[i] = '\0';
			return (r);
		}
	}
	return (NULL);
}
