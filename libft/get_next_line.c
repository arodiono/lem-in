/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:00:37 by arodiono          #+#    #+#             */
/*   Updated: 2017/01/17 18:00:39 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_n(char **line, char **tmp)
{
	if ((*tmp = ft_strchr(*line, '\n')) == 0)
		return (0);
	**tmp = '\0';
	*tmp = ft_strdup(*tmp + 1);
	return (1);
}

int		reader(const int fd, char **line, char **tmp)
{
	char	buf[BUFF_SIZE + 1];
	int		res;

	if (check_n(line, tmp))
		return (1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((res = (int)read(fd, &buf, BUFF_SIZE)) > 0)
	{
		*tmp = *line;
		*line = ft_strjoin(*tmp, buf);
		free(*tmp);
		ft_bzero(buf, BUFF_SIZE + 1);
		if (check_n(line, tmp))
			return (1);
	}
	*tmp = ft_strdup("\0");
	if (!*line || !**line)
		return (res);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*save;
	char		*tmp;
	int			res;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strdup(!save ? "\0" : save);
	if ((res = reader(fd, line, &tmp)) < 1)
	{
		free(tmp);
		return (res);
	}
	if (save)
		free(save);
	save = ft_strdup(tmp == 0 ? "\0" : tmp);
	free(tmp);
	return (1);
}
