/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:44:34 by arodiono          #+#    #+#             */
/*   Updated: 2016/12/02 15:24:19 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

const char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if ((str1[i] == '\0' && str2[i] == '\0') || str2[i] == '\0')
		return (str1);
	while (str1[i] != '\0')
	{
		n = 0;
		if (str1[i] == str2[n])
		{
			while (str2[n] != '\0')
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
