/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:35:46 by arodiono          #+#    #+#             */
/*   Updated: 2016/11/23 20:01:13 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char *r;

	r = (char*)str;
	while (*r)
	{
		if (*r == ch)
			return (r);
		r++;
	}
	if (*r == '\0' && ch == '\0')
		return (r);
	return (NULL);
}
