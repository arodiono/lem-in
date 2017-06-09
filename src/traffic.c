/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traffic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:02:20 by arodiono          #+#    #+#             */
/*   Updated: 2017/06/08 16:02:22 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	best_comb(t_farm **farm)
{
	t_comb	*tmp_comb;

	tmp_comb = (*farm)->comb;
	while (tmp_comb->next)
		tmp_comb = tmp_comb->next;
	(*farm)->star = (t_best_c *)malloc(sizeof(t_best_c));
	BEST = way_list_to_array(tmp_comb->way);
	(*farm)->star->way_qty = count_ways(tmp_comb->way);
}

void	move_ants(t_farm **farm, int w, int r, int *fin)
{
	if (BEST[w]->path[r]->ant > 0)
	{
		if (ft_strcmp(BEST[w]->path[r - 1]->room, (*farm)->end) == 0)
		{
			print_step(BEST[w]->path[r]->ant, BEST[w]->path[r - 1]->room);
			BEST[w]->path[r]->ant = 0;
			(*fin)++;
		}
		else
		{
			BEST[w]->path[r - 1]->ant = BEST[w]->path[r]->ant;
			print_step(BEST[w]->path[r - 1]->ant, BEST[w]->path[r - 1]->room);
			BEST[w]->path[r]->ant = 0;
		}
	}
}

int		from_room_to_room(t_farm **farm)
{
	int	w;
	int	r;
	int	fin;
	int	ways;
	int	rooms;

	w = 0;
	fin = 0;
	ways = (*farm)->star->way_qty;
	while (w < ways)
	{
		rooms = BEST[w]->lenght;
		r = 0;
		while (r < rooms)
		{
			move_ants(&*farm, w, r, &fin);
			r++;
		}
		w++;
	}
	return (fin);
}

int		to_first_room(t_farm **farm, int *ant)
{
	int	w;
	int	fin;
	int	ways;
	int	rooms;

	w = 0;
	fin = 0;
	ways = (*farm)->star->way_qty - 1;
	while (w <= ways && *ant <= (*farm)->ants)
	{
		rooms = BEST[w]->lenght - 1;
		if (ft_strcmp(BEST[w]->path[rooms - 1]->room, (*farm)->end) == 0)
			while (*ant <= (*farm)->ants)
			{
				print_step((*ant)++, BEST[w]->path[rooms - 1]->room);
				fin++;
			}
		else
		{
			BEST[w]->path[rooms - 1]->ant = *ant;
			print_step((*ant)++, BEST[w++]->path[rooms - 1]->room);
		}
	}
	ft_putchar('\n');
	return (fin);
}

void	traffic(t_farm **farm)
{
	int	fin;
	int	ant;

	fin = 1;
	ant = 1;
	while (fin <= (*farm)->ants)
	{
		fin += from_room_to_room(&*farm);
		fin += to_first_room(&*farm, &ant);
	}
}
