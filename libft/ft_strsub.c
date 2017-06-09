/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:34:35 by arodiono          #+#    #+#             */
/*   Updated: 2016/12/02 15:24:43 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*r;

	i = 0;
	if (s)
	{
		r = (char*)malloc(sizeof(char) * len + 1);
		if (r != NULL)
		{
			while (len-- > 0)
			{
				r[i++] = s[start];
				start++;
			}
			r[i] = '\0';
			return (r);
		}
	}
	return (NULL);
}
