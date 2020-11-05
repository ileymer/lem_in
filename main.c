/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:29:52 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/01 18:29:59 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_empty(char *s)
{
	int i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

static t_map	*map_init_2(t_map *m)
{
	int i;
	int j;

	i = -1;
	m->init_2 = 1;
	m->path = (int*)ft_memalloc(sizeof(int) * 1000);
	m->tab = (int**)ft_memalloc(sizeof(int*) * m->q_links);
	m->rooms = (char**)ft_memalloc(sizeof(char*) * (m->q_rooms + 1));
	while (++i < m->q_links)
	{
		m->path[i] = -1;
		m->rooms[i] = NULL;
		m->tab[i] = (int*)ft_memalloc(sizeof(int) * 2);
		j = -1;
		while (m->tab[i][++j])
			m->tab[i][j] = 0;
	}
	m->rooms[i] = NULL;
	m->path[0] = 0;
	return (m);
}

static void		read_map(t_map *m)
{
	char *line;

	while (get_next_line(STDIN_FILENO, &line) > 0 && line[0] != '(') {
        if (m->ants == 0)
            count_ants(m, line);
        else if (ft_strchr(line, '-') || m->started == 3) {
            links(m, line);
            if (ft_strchr(line, '-'))
                m->q_links++;
        }
        else if ((m->started == 1 || m->started == 2) && !is_empty(line))
            rooms(m, line);
        else
            exit_func(m, 1);
    }

	if (!m->ants || !m->links[0])
		exit_func(m, 1);
	m = map_init_2(m);
}

static t_map	*map_init(void)
{
	t_map *m;

	m = (t_map*)ft_memalloc(sizeof(t_map));
	m->links = ft_strnew(1);
	m->ants_str = ft_strnew(1);
	m->rooms_list = ft_strnew(1);
	m->q_rooms = 0;
	m->q_links = 0;
	m->ants = 0;
	m->started = 0;
	m->p_ind = 0;
	m->init_2 = 0;
	m->good[0] = 0;
	m->good[1] = 0;
	m->rooms = NULL;
	m->tab = NULL;
	m->path = NULL;
	return (m);
}

int				main(void)
{
	t_map *m;
	m = map_init();
	read_map(m);
	add_rooms(m);
	if (!m->good[0] || !m->good[1])
		exit_func(m, 1);
	create_tab(m, 0);

	//dell after
	write(1, "\ncomnati \n", 7);
	ft_putnbr(m->q_rooms);
    write(1, "\npyti \n", 4);
    ft_putnbr(m->q_links);
    //code of dgeonosi;
    start_alg(m);



    int i;
    int j;

    j = 0;
    i = 0;
	printf("\n");
    while (i < m->q_rooms)
	{
    	j = 1;
		printf("%d - ", i);
    	while (j <= m->pow_room[i][0])
    		printf("%10d", m->pow_room[i][j++]);
		printf("\n");
		i++;
	}

	exit_func(m, 0);
}
