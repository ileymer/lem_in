/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:37:28 by dyoung            #+#    #+#             */
/*   Updated: 2020/11/01 18:37:40 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	links(t_map *m, char *line)
{
	if (m->started == 2)
		m->started = 3;
	if (m->started != 3)
		exit_func(m, 1);
	m->links = join_str(m->links, line, 0);
}