/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 22:05:38 by arodiono          #+#    #+#             */
/*   Updated: 2017/06/09 22:05:39 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			is_room(t_farm **farm, char *room)
{
	t_room	*tmp_room;

	tmp_room = (*farm)->room;
	while (tmp_room)
	{
		if (ft_strcmp(tmp_room->name, room) == 0)
			return (TRUE);
		tmp_room = tmp_room->next;
	}
	return (FALSE);
}

int			count_rooms(t_path *path)
{
	t_path	*tmp;
	int		count;

	tmp = path;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int			count_ways(t_way *way)
{
	int		i;
	t_way	*tmp;

	tmp = way;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_best_p	**path_list_to_array(t_path *path)
{
	int			count;
	t_path		*tmp;
	t_best_p	**new;

	tmp = path;
	count = 0;
	new = (t_best_p **)malloc(sizeof(t_best_p *) * 50);
	while (tmp)
	{
		new[count] = (t_best_p *)malloc(sizeof(t_best_p));
		new[count]->room = tmp->room;
		new[count]->ant = 0;
		tmp = tmp->next;
		count++;
	}
	return (new);
}

t_best_w	**way_list_to_array(t_way *way)
{
	int			count;
	t_way		*tmp;
	t_best_w	**new;

	tmp = way;
	count = 0;
	new = (t_best_w **)malloc(sizeof(t_best_w *) * count_ways(tmp));
	while (tmp)
	{
		new[count] = (t_best_w *)malloc(sizeof(t_best_w));
		new[count]->lenght = tmp->length;
		new[count]->path = path_list_to_array(tmp->path);
		tmp = tmp->next;
		count++;
	}
	return (new);
}
