/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 21:01:08 by arodiono          #+#    #+#             */
/*   Updated: 2017/05/31 21:01:10 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	find_coordinate_doubles(t_farm **farm)
{
	t_room	*tmp;
	t_room	*room;

	room = (*farm)->room;
	while (room)
	{
		tmp = (*farm)->room;
		while (tmp)
		{
			if (ft_strcmp(room->name, tmp->name) != 0)
				if (room->x == tmp->x && room->y == tmp->y)
					print_error();
			tmp = tmp->next;
		}
		room = room->next;
	}
}

int		find_room_doubles(t_farm **farm, char *room)
{
	t_room	*tmp_room;

	tmp_room = (*farm)->room;
	while (tmp_room)
	{
		if (ft_strcmp(tmp_room->name, room) == 0)
			return (FALSE);
		tmp_room = tmp_room->next;
	}
	return (TRUE);
}

int		validate_link(t_farm **farm, char *line)
{
	size_t	i;
	size_t	j;
	t_link	*tmp_link;
	char	*tmp;

	i = 0;
	if (check_dash(line) != 1 || line[0] == '-')
		return (FALSE);
	tmp_link = (t_link *)malloc(sizeof(t_link));
	while (line[i] && line[i] != '-')
		i++;
	if (is_room(&*farm, tmp = ft_strsub(line, 0, i)) == TRUE)
		tmp_link->first = tmp;
	else
		print_error();
	j = i + 1;
	while (line[j])
		j++;
	if (is_room(&*farm, tmp = ft_strsub(line, ++i, j)) == TRUE)
		tmp_link->second = tmp;
	else
		print_error();
	tmp_link->next = (*farm)->link;
	(*farm)->link = tmp_link;
	return (TRUE);
}

int		validate_room(char *line)
{
	if (line[0] == 'L' || line[0] == ' ' || count_spaces(line) != 2)
		return (FALSE);
	while (*line && *line != ' ')
		line++;
	line++;
	while (*line && *line != ' ')
	{
		if (ft_isdigit(*line) || *line == '-')
			line++;
		else
			return (FALSE);
	}
	line++;
	if (*line == '\0')
		return (FALSE);
	while (*line && *line != ' ')
	{
		if (ft_isdigit(*line) || *line == '-')
			line++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int		coordinate_validation(char *str)
{
	int				i;
	int				f;
	long long int	r;

	r = 0;
	i = 0;
	f = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		f = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		r = (r * 10) + (str[i++] - '0');
	r *= f;
	if (r < -2147483648 || r > 2147483647)
		print_error();
	return ((int)r);
}
