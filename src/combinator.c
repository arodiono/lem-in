/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:26:59 by arodiono          #+#    #+#             */
/*   Updated: 2017/06/06 20:27:01 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	sort_first_elem(t_farm **farm)
{
	t_way	*list;
	t_way	*tmp;

	list = (*farm)->way;
	while (list->next && list->length > list->next->length)
	{
		tmp = list->next;
		list->next = tmp->next;
		tmp->next = list;
		list = tmp;
	}
	(*farm)->way = list;
}

void	sort_ways(t_farm **farm)
{
	t_way	*backup;
	t_way	*list;
	t_way	*tmp;
	int		sort;

	sort = 1;
	list = (*farm)->way;
	while (sort)
	{
		sort = 0;
		backup = list;
		while (list->next && list->next->next)
			if (list->next->length > list->next->next->length)
			{
				tmp = list->next->next;
				list->next->next = tmp->next;
				tmp->next = list->next;
				list->next = tmp;
				sort = 1;
				list = backup;
			}
			else
				list = list->next;
	}
}

int		path_compare(t_path *f, t_way *s, char *start, char *end)
{
	t_path	*first;
	t_path	*second;

	while (s)
	{
		second = s->path;
		while (second)
		{
			first = f;
			while (first)
			{
				if (ft_strcmp(first->room, start) != 0 \
					&& ft_strcmp(first->room, end) != 0)
					if (ft_strcmp(first->room, second->room) == 0)
						return (FALSE);
				first = first->next;
			}
			second = second->next;
		}
		s = s->next;
	}
	return (TRUE);
}

void	pass_insert(t_comb **tmp_comb, t_path *path, t_farm **farm)
{
	t_way	*all_ways;
	t_way	*tmp;

	all_ways = (*farm)->way;
	tmp = (t_way *)malloc(sizeof(t_way));
	tmp->path = path;
	tmp->length = count_rooms(path);
	tmp->next = (*tmp_comb)->way;
	(*tmp_comb)->way = tmp;
	while (all_ways)
	{
		if (path_compare(all_ways->path, (*tmp_comb)->way, \
			(*farm)->start, (*farm)->end))
		{
			tmp = (t_way *)malloc(sizeof(t_way));
			tmp->path = all_ways->path;
			tmp->length = all_ways->length;
			tmp->next = (*tmp_comb)->way;
			(*tmp_comb)->way = tmp;
		}
		all_ways = all_ways->next;
	}
}

void	find_combination(t_farm **farm)
{
	t_way	*tmp_way;
	t_comb	*tmp_comb;

	tmp_way = (*farm)->way;
	while (tmp_way)
	{
		tmp_comb = (t_comb *)malloc(sizeof(t_comb));
		tmp_comb->way = NULL;
		pass_insert(&tmp_comb, tmp_way->path, &*farm);
		tmp_comb->next = (*farm)->comb;
		(*farm)->comb = tmp_comb;
		tmp_way = tmp_way->next;
	}
}
