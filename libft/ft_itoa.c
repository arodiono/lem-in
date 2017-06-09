/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:23:49 by arodiono          #+#    #+#             */
/*   Updated: 2016/12/02 15:19:16 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int	ft_diglen(int n)
{
	int		i;

	i = 0;
	while (n >= 10 || n <= -10)
	{
		i++;
		n /= 10;
	}
	if (n < 0)
		return (i + 1);
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		f;
	char	*r;

	i = ft_diglen(n);
	f = 1;
	if (!(r = (char*)malloc(sizeof(char) * i + 2)))
		return (NULL);
	if (n < 0)
	{
		f = -1;
		r[0] = '-';
	}
	if (r != NULL)
	{
		r[i + 1] = '\0';
		while (n >= 10 || n <= -10)
		{
			r[i] = n % 10 * f + '0';
			n /= 10;
			i--;
		}
		r[i] = n * f + '0';
	}
	return (r);
}
