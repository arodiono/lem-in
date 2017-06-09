/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:28:22 by arodiono          #+#    #+#             */
/*   Updated: 2016/12/02 15:23:43 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

const char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t i;
	size_t n;

	i = 0;
	if ((str1[i] == '\0' && str2[i] == '\0') || str2[i] == '\0')
		return (str1);
	while (i < len && str1[i])
	{
		n = 0;
		if (str1[i] == str2[n])
		{
			while ((n + i) < len && str1[i + n] && str2[n])
			{
				if (str2[n] != str1[i + n])
					break ;
				if (str2[n + 1] == '\0')
					return (str1 + i);
				n++;
			}
		}
		i++;
	}
	return (NULL);
}
