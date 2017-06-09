/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:50:30 by arodiono          #+#    #+#             */
/*   Updated: 2016/11/22 15:06:39 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 || *s2)
		{
			if (*s1 == *s2 && s1 && s2)
			{
				s1++;
				s2++;
			}
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
