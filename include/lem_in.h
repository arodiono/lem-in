/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodiono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 16:13:58 by arodiono          #+#    #+#             */
/*   Updated: 2017/05/28 16:14:00 by arodiono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define TRUE 1
# define FALSE 0
# define BEST (*farm)->star->best_w

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_best_c
{
	struct s_best_w	**best_w;
	int				way_qty;
}					t_best_c;

typedef struct		s_best_w
{
	int				lenght;
	struct s_best_p	**path;
}					t_best_w;

typedef struct		s_best_p
{
	char			*room;
	int				ant;
}					t_best_p;

typedef struct		s_comb
{
	struct s_way	*way;
	struct s_comb	*next;
}					t_comb;

typedef struct		s_path
{
	char			*room;
	struct s_path	*next;
}					t_path;

typedef struct		s_way
{
	int				length;
	struct s_path	*path;
	struct s_way	*next;
}					t_way;

typedef struct		s_link
{
	char			*first;
	char			*second;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				y;
	int				x;
	struct s_room	*next;
}					t_room;

typedef struct		s_map
{
	char			*map;
	struct s_map	*prev;
	struct s_map	*next;
}					t_map;

typedef struct		s_farm
{
	int				ants;
	char			*start;
	char			*end;
	struct s_map	*map;
	struct s_room	*room;
	struct s_link	*link;
	struct s_way	*way;
	struct s_comb	*comb;
	struct s_comb	*best;
	struct s_best_c	*star;
}					t_farm;

void				farm_init(t_farm **farm);
void				read_numbers_of_ants(t_farm **farm);
void				read_rooms_and_links(t_farm **farm);
void				hash_validation(char *line, t_farm **farm);
void				get_end_room(t_farm **farm);
void				get_start_room(t_farm **farm);
void				get_room(t_farm **farm, char **line);
void				error_free_exit(char **line);
void				print_error();
int					count_spaces(char *string);
int					check_quantity(char *line);
int					check_dash(char *line);
int					find_room_doubles(t_farm **farm, char *room);
int					is_room(t_farm **farm, char *room);
int					validate_link(t_farm **farm, char *line);
int					validate_room(char *line);
int					coordinate_validation(char *str);
void				find_coordinate_doubles(t_farm **farm);
void				get_room(t_farm **farm, char **line);
int					count_rooms(t_path *path);
char				*get_next(t_farm **farm, char *name);
int					path_cmp(char *room, t_path *path_tmp);
int					find_next_room(t_farm **farm, char *room, t_path *path);
void				sort_ways(t_farm **farm);
void				sort_first_elem(t_farm **farm);
int					count_ways(t_way *way);
void				find_path(t_farm **farm);
void				find_combination(t_farm **farm);
int					path_compare(t_path *f, t_way *s, char *start, char *end);
void				pass_insert(t_comb **tmp_comb, t_path *path, t_farm **farm);
t_best_p			**path_list_to_array(t_path *path);
t_best_w			**way_list_to_array(t_way *way);
void				best_comb(t_farm **farm);
void				traffic(t_farm **farm);
int					from_room_to_room(t_farm **farm);
int					to_first_room(t_farm **farm, int *ant);
void				move_ants(t_farm **farm, int w, int r, int *fin);
void				save_map(char **line, t_farm **farm);
void				print_map(t_farm **farm);
void				print_step(int ant, char *room);

#endif
