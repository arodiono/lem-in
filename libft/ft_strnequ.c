/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:08:15 by arodiono          #+#    #+#             */
/*   Updated: 2016/12/02 15:23:13 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (i == n)
		return (1);
	if (s1 != NULL && s2 != NULL)
	{
		while (i < n)
		{
			if (*s1 == *s2 && s1 && s2)
			{
				s1++;
				s2++;
				i++;
			}
			else
				return (0);
			if (i == n)
				return (1);
		}
	}
	return (0);
}
