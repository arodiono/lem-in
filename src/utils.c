/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:46:57 by arodiono          #+#    #+#             */
/*   Updated: 2017/05/29 14:46:58 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		count_spaces(char *string)
{
	int	count;

	count = 0;
	while (*string)
	{
		if (*string == ' ')
			count++;
		string++;
	}
	return (count);
}

void	print_error(void)
{
	write(1, "ERROR\n", 6);
	exit(0);
}

void	farm_init(t_farm **farm)
{
	(*farm)->ants = 0;
	(*farm)->start = NULL;
	(*farm)->end = NULL;
	(*farm)->room = NULL;
	(*farm)->link = NULL;
	(*farm)->way = NULL;
	(*farm)->comb = NULL;
	(*farm)->map = NULL;
}

int		check_quantity(char *line)
{
	if (!(*line))
		return (FALSE);
	while (*line)
	{
		if (ft_isdigit(*line) == 0)
			return (FALSE);
		line++;
	}
	return (TRUE);
}

int		check_dash(char *line)
{
	int dash;

	dash = 0;
	while (*line)
	{
		if (*line == '-')
			dash++;
		line++;
	}
	return (dash);
}
