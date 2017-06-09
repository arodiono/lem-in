/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:50:34 by arodiono          #+#    #+#             */
/*   Updated: 2016/11/21 18:34:29 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dst, char *src, size_t num)
{
	size_t i;
	size_t a;

	i = ft_strlen(dst);
	a = 0;
	while (a < num && src[a] != '\0')
	{
		dst[i] = src[a];
		a++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
