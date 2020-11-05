/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:38:13 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/01 18:38:33 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <limits.h>
# include <stdio.h>

typedef struct	s_map
{
	char		**rooms;		// array of room names
	char		*rooms_list;	// list of rooms that was passed at the beginning
	char		*ants_str;		// list of ants that was passed at the beginning
	char		*links;			// list of links that was passed at the beginning
	int			q_rooms;		// quantity of rooms
	int			ants;			// quantity of ant
	int         q_links;        // quantity of links
	int			started;		// a part of validation
	int			p_ind;			// last path index, current size of path
	int			*path;			// path
	int			**tab;			// edge table
	int			*room;
	int 		**pow_room;
	int 		*s;
	int			*bl;
	int			sl;
	int			good[2];		// a part of validation
	int			new_line;		// a part of validation
	int			init_2;			// a part of validation
}				t_map;

typedef struct s_queue
{
	int v;
	int p;
	struct s_queue *next;
} 				t_queue;

typedef struct s_par
{
	int previous;
	int current;
	struct s_par *next;
} t_par;

typedef struct s_way
{
	int value;
	int k;
	struct s_way *next;
	t_par *par;
} t_way;


void			count_ants(t_map *m, char *line);
void			rooms(t_map *m, char *line);
void			links(t_map *m, char *line);

void			add_rooms(t_map *m);
void			create_tab(t_map *m, int count);
int				start_alg(t_map *p);

char			*join_str(char *s1, char *s2, int clean);
void			free_array(char **array, t_map *m, int error);
int				room_index(t_map *m, char *room_name, int start);

void			exit_func(t_map *m, int error);

#endif
