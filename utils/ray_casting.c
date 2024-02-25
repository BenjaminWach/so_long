/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:03:18 by bwach             #+#    #+#             */
/*   Updated: 2024/02/24 23:17:05 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	dist_to_bot(t_map *m, t_play *p)
{
	int	dist_to_wall;

	dist_to_wall = 0;
	if (m->map[(p->bot_r[1] / 64) + 1][(p->bot_r[0] / 64)] == '1' &&
		m->map[(p->top_r[1] / 64)][(p->top_r[0] / 64) + 1] == '1')
	{
		if (m->map[(p->top_l[1] / 64)][() / 64 + 1] == '1')
			return (dist_to_wall);
	}
}
