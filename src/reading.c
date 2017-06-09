/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 21:56:28 by arodiono          #+#    #+#             */
/*   Updated: 2017/06/09 21:56:29 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	get_room(t_farm **farm, char **line)
{
	size_t	i;
	t_room	*tmp_room;
	char	*tmp;

	i = 0;
	tmp_room = (t_room *)malloc(sizeof(t_room));
	while ((*line)[i] != ' ')
		i++;
	if (find_room_doubles(&*farm, tmp = ft_strsub(*line, 0, i++)) == FALSE)
		print_error();
	tmp_room->name = tmp;
	tmp_room->y = coordinate_validation(&(*line)[i++]);
	tmp_room->x = coordinate_validation(&(*line)[++i]);
	tmp_room->next = (*farm)->room;
	(*farm)->room = tmp_room;
	save_map(&*line, &*farm);
}

void	get_start_room(t_farm **farm)
{
	char	*line;

	if (get_next_line(0, &line) > 0 && validate_room(line))
	{
		get_room(&*farm, &line);
		(*farm)->start = (*farm)->room->name;
	}
	else
		error_free_exit(&line);
}

void	get_end_room(t_farm **farm)
{
	char	*line;

	if (get_next_line(0, &line) > 0 && validate_room(line))
	{
		get_room(&*farm, &line);
		(*farm)->end = (*farm)->room->name;
	}
	else
		error_free_exit(&line);
}

void	hash_validation(char *line, t_farm **farm)
{
	if (line[0] == '#' && line[1] != '#')
		save_map(&line, &*farm);
	else if (ft_strcmp(line, "##start") == 0)
	{
		if ((*farm)->end == NULL && (*farm)->start == NULL)
		{
			save_map(&line, &*farm);
			get_start_room(&*farm);
		}
		else
			error_free_exit(&line);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if ((*farm)->end == NULL)
		{
			save_map(&line, &*farm);
			get_end_room(&*farm);
		}
		else
			error_free_exit(&line);
	}
	else
		save_map(&line, &*farm);
}

void	read_rooms_and_links(t_farm **farm)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
			hash_validation(line, &*farm);
		else if (validate_room(line))
		{
			if ((*farm)->link == NULL)
				get_room(&*farm, &line);
			else
				break ;
		}
		else if (validate_link(&*farm, line))
			save_map(&line, &*farm);
		else
			break ;
	}
	ft_memdel((void **)&line);
}
