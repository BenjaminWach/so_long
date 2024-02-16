/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:20:15 by bwach             #+#    #+#             */
/*   Updated: 2024/02/16 13:09:01 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	interaction(t_map *map, bool *picked)
{
	map->nb_obj--;
	*picked = true;
}

static void	interaction_chest(t_data *game, t_map *m, bool *picked)
{
	t_play	*p;

	p = game->player;
	if (m->map[(p->hg[1] + 15) / 64][(p->hg[0] + 15) / 64] == 'C')
	{
		m->map[(p->hg[1] + 15) / 64][(p->hg[0] + 15) / 64] = '0';
		interaction(m, picked);
	}
	else if (m->map[(p->hd[1] + 15) / 64][(p->hd[0] + 15) / 64] == 'C')
	{
		m->map[(p->hd[1] + 15) / 64][(p->hd[0] + 15) / 64] = '0';
		interaction(m, picked);
	}
	else if (m->map[(p->hg[1] + 15) / 64][(p->g[0] - 15) / 64] == 'C')
	{
		m->map[(p->hg[1] + 15) / 64][(p->g[0] - 15) / 64] = '0';
		interaction(m, picked);
	}
	else if (m->map[(p->hg[1] - 15) / 64][(p->g[0] - 15) / 64] == 'C')
	{
		m->map[(p->hg[1] - 15) / 64][(p->g[0] - 15) / 64] = '0';
		interaction(m, picked);
	}
}

static void	draw_items(t_data *game, t_map *m, int len, bool picked)
{
	while (m->map[len / m->width])
	{
		if (m->map[len / m->width][len % m->width] == 'C' && !picked)
		{
			draw_pic((len % m->width) * 64, (len / m->width) * 64,
				game->obj[0], game);
		}
		else if (m->map[len / m->width][len % m->width] == 'C' && picked)
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
	bool	picked;

	len = 0;
	picked = false;
	interaction_chest(game, m, &picked);
	draw_items(game, m, len, picked);
}
