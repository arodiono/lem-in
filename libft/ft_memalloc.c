/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:54:13 by arodiono          #+#    #+#             */
/*   Updated: 2016/12/02 15:16:47 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char *a;

	a = (unsigned char*)malloc(size);
	if (a == NULL)
		return (NULL);
	while (size-- > 0)
		a[size] = '\0';
	return (a);
}
