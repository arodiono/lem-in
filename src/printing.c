/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 22:03:09 by arodiono          #+#    #+#             */
/*   Updated: 2017/06/09 22:03:11 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	print_step(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

void	print_map(t_farm **farm)
{
	t_map	*tmp;

	tmp = (*farm)->map;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		ft_putendl(tmp->map);
		tmp = tmp->prev;
	}
	ft_putchar('\n');
}
