/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 16:05:46 by arodiono          #+#    #+#             */
/*   Updated: 2017/05/28 16:05:49 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	save_map(char **line, t_farm **farm)
{
	t_map	*tmp;

	tmp = (t_map *)malloc(sizeof(t_map));
	tmp->prev = NULL;
	tmp->map = (*line);
	tmp->next = (*farm)->map;
	(*farm)->map = tmp;
	if ((*farm)->map->next != NULL)
		(*farm)->map->next->prev = (*farm)->map;
}

void	error_free_exit(char **line)
{
	ft_memdel((void **)&*line);
	write(1, "ERROR\n", 6);
	exit(0);
}

void	read_numbers_of_ants(t_farm **farm)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#' && line[1] != '#')
			save_map(&line, &*farm);
		else if (!(ft_strcmp(line, "##end")) || !(ft_strcmp(line, "##start")))
			error_free_exit(&line);
		else if (check_quantity(line) > 0 && (*farm)->ants == 0)
		{
			if (((*farm)->ants = ft_atoi(line)) > 0)
			{
				save_map(&line, &*farm);
				break ;
			}
			else
				error_free_exit(&line);
		}
		else
			error_free_exit(&line);
	}
}

int		main(void)
{
	t_farm	*farm;

	farm = malloc(sizeof(t_farm));
	farm_init(&farm);
	read_numbers_of_ants(&farm);
	read_rooms_and_links(&farm);
	if (farm->start == NULL || farm->end == NULL)
		print_error();
	find_coordinate_doubles(&farm);
	find_path(&farm);
	if (farm->way == NULL)
		print_error();
	sort_ways(&farm);
	sort_first_elem(&farm);
	find_combination(&farm);
	best_comb(&farm);
	print_map(&farm);
	traffic(&farm);
	return (0);
}
