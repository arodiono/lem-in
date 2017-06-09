/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:41:30 by arodiono          #+#    #+#             */
/*   Updated: 2016/12/02 15:13:32 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *str, int val, size_t len)
{
	unsigned char a;
	unsigned char *b;

	a = (unsigned char)val;
	b = (unsigned char*)str;
	while (len--)
	{
		b[len] = a;
	}
	return (b);
}
