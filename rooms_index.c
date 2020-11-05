/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:37:06 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/01 18:37:14 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	room_index(t_map *m, char *room_name, int start)
{
	int index;

	index = (start) ? -1 : 0;
	while (m->rooms[++index] && index < m->q_rooms)
	{
		if (ft_strcmp(m->rooms[index], room_name) == 0)
			return (index);
	}
	return (index);
}
