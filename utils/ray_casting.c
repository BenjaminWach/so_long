/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:03:18 by bwach             #+#    #+#             */
/*   Updated: 2024/02/18 20:05:38 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	distance_right(t_data *game, t_map *m)
{
	t_play	*p;
	int		dist;

	dist = 0;
	p = game->player;
	if (m->map[(p->top_r[1] + HPX) / 64][(p->top_r[0] / 64) + 1] == '1' ||
		m->map[(p->bot_r[1] + HPX) / 64][(p->bot_r[0] / 64) + 1] == '1')
	{
		if (m->map[(p->top_l[1] + HPX) / 64][(p->top_l[0] / 64) + 1] == '1'
		|| m->map[(p->bot_l[1] + HPX) / 64][(p->bot_l[1] / 64) + 1] == '1')
			return ();
		else
			return ();
	}
	return (MVX);
}

void	mini_raycasting(t_data *game, t_map *map)
{
	t_play	*p;

	p = game->player;
	p->right = distance_right(game, map);
	p->left = distance_left(game, map);
	p->up = distance_up(game, map);
	p->down = distance_down(game, map);
}
