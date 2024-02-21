/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:20:15 by bwach             #+#    #+#             */
/*   Updated: 2024/02/21 00:38:11 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	interaction(t_map *map, int x, int y)
{
	if (map->nb_obj > 0 && map->taken[y][x] == 0)
	{
		map->nb_obj--;
		map->taken[y][x] = 1;
	}
}

static void	interaction_chest(t_data *game, t_map *m)
{
	t_play	*p;

	p = game->player;
	if (m->map[(p->top_l[1]) / 64][(p->top_l[0]) / 64] == 'C')
		interaction(m, (p->top_l[0] / 64), (p->top_l[1] / 64));
	else if (m->map[(p->top_r[1]) / 64][(p->top_r[0]) / 64] == 'C')
		interaction(m, (p->top_r[0] / 64), (p->top_r[1] / 64));
	else if (m->map[(p->bot_l[1]) / 64][(p->bot_l[0] - 15) / 64] == 'C')
		interaction(m, (p->bot_l[0] / 64), (p->bot_l[1] / 64));
	else if (m->map[(p->bot_r[1]) / 64][(p->bot_r[0]) / 64] == 'C')
		interaction(m, (p->bot_r[0] / 64), (p->bot_r[1] / 64));
}

static void	draw_items(t_data *game, t_map *m, int len)
{
	while (m->map[len / m->width])
	{
		if (m->map[len / m->width][len % m->width] == 'C' &&
			m->taken[len / m->width][len % m->width] == 0)
		{
			draw_pic((len % m->width) * 64, (len / m->width) * 64,
				game->obj[0], game);
		}
		else if (m->map[len / m->width][len % m->width] == 'C' &&
				m->taken[len / m->width][len % m->width] == 1)
		{
			draw_pic((len % m->width) * 64, (len / m->width) * 64,
				game->obj[1], game);
		}
		len++;
	}
}

void	chest(t_data *game, t_map *m)
{
	size_t	len;

	len = 0;
	interaction_chest(game, m);
	draw_items(game, m, len);
	//if (m->nb_obj == 0)
		//free_array(m->taken);
}
