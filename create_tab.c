/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:39:59 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/01 18:40:03 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	validate_link(t_map *m, char *link)
{
	char **l;

	l = ft_strsplit(link, '-');
	if (l[2] != NULL)
		free_array(l, m, 1);
	free_array(l, m, 0);
}

void		create_tab(t_map *m, int count)
{
	int		i;
	int		r_1;
	int		r_2;
	char	**l;
	char	**links;

	i = -1;
	links = ft_strsplit(m->links, '\n');
	while (links[++i])
	{
		if (links[i][0] == '#') {
            continue;
        }
		validate_link(m, links[i]);
		l = ft_strsplit(links[i], '-');
		if ((r_1 = room_index(m, l[0], 1)) >= m->q_rooms || (r_2 = room_index(m, l[1], 1)) >= m->q_rooms)
		{
			free_array(l, m, 0);
			free_array(links, m, 1);
		}
		(r_2) ? (m->tab[count][1] = r_2) : 0;
		(r_1) ? (m->tab[count][0] = r_1) : 0;
        ft_putnbr(m->tab[count][0]);
        write(1, "\n", 1);
		ft_putnbr(m->tab[count][1]);
        write(1, "\n", 1);
		free_array(l, m, 0);
        count++;
	}
	free_array(links, m, 0);

}
