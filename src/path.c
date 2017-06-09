/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 21:16:26 by arodiono          #+#    #+#             */
/*   Updated: 2017/05/31 21:16:27 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

char	*get_next(t_farm **farm, char *name)
{
	t_room *tmp_room;

	tmp_room = (*farm)->room;
	while (tmp_room)
	{
		if (ft_strequ(tmp_room->name, name) == TRUE)
			break ;
		tmp_room = tmp_room->next;
	}
	return (tmp_room->name);
}

int		path_cmp(char *room, t_path *path_tmp)
{
	t_path	*path;

	path = path_tmp;
	while (path)
	{
		if (ft_strequ(path->room, room) == TRUE)
			return (TRUE);
		path = path->next;
	}
	return (FALSE);
}

int		next_step(t_farm **farm, t_path **tmp_path, t_path *path, char *room)
{
	t_link	*tmp;
	int		rooms_passed;
	int		i;

	i = 0;
	rooms_passed = 0;
	tmp = (*farm)->link;
	while (tmp)
	{
		if (ft_strequ(tmp->first, room) && path_cmp(tmp->second, path) == 0)
		{
			if (find_next_room(&*farm, get_next(&*farm, tmp->second), path))
				i++;
		}
		if (ft_strequ(tmp->second, room) && path_cmp(tmp->first, path) == 0)
		{
			if (find_next_room(&*farm, get_next(&*farm, tmp->first), path))
				i++;
		}
		rooms_passed++;
		tmp = tmp->next;
	}
	if (rooms_passed == 0 || i == 0)
		free(*tmp_path);
	return (i);
}

int		find_next_room(t_farm **farm, char *room, t_path *path)
{
	t_path	*tmp_path;
	t_way	*tmp_way;
	int		i;

	tmp_path = (t_path *)malloc(sizeof(t_path));
	tmp_path->room = room;
	tmp_path->next = path;
	path = tmp_path;
	if (ft_strequ(room, (*farm)->end) == 1)
	{
		tmp_way = (t_way *)malloc(sizeof(t_way));
		tmp_way->path = path;
		tmp_way->length = count_rooms(tmp_way->path);
		tmp_way->next = (*farm)->way;
		(*farm)->way = tmp_way;
		return (1);
	}
	i = next_step(&*farm, &tmp_path, path, room);
	return (i > 0 ? 1 : 0);
}

void	find_path(t_farm **farm)
{
	t_room	*tmp_room;
	t_path	*path;

	tmp_room = (*farm)->room;
	while (ft_strequ(tmp_room->name, (*farm)->start) == FALSE)
		tmp_room = tmp_room->next;
	path = NULL;
	find_next_room(&*farm, tmp_room->name, path);
}
