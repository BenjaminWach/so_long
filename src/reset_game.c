/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:05:38 by bwach             #+#    #+#             */
/*   Updated: 2024/02/27 14:36:49 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	chest_state(t_data *game, t_map *m)
{
	int	len;

	len = 0;
	while (m->map[len / m->width])
	{
		if (m->map[len / m->width][len % m->width] == 'C')
		{
			if (game->reset)
			{
				draw_pic((len % m->width) * 64, (len / m->width) * 64,
					game->obj[0], game);
			}
			else if (m->taken[len / m->width][len % m->width] == 1)
			{
				draw_pic((len % m->width) * 64, (len / m->width) * 64,
					game->obj[1], game);
			}
		}
		len++;
	}
}

static void	character_pos(t_data *game, t_play *p, t_map *m)
{
	int	len;

	len = 0;
	while (m->map[len / m->width])
	{
		if (m->map[len / m->width][len % m->width] == 'P')
		{
			p->pos[0] = (len % m->width) * 64;
			p->pos[1] = (len / m->width) * 64 - 1;
			if (m->map[len / m->width][(len % m->width) - 1] == '1')
				game->player->direction = 0;
			else
				game->player->direction = 1;
		}
		if (m->map[len / m->width][len % m->width] == 'C')
		{
			m->nb_obj++;
		}
		len++;
	}
}

void	reset_game(t_data *game)
{
	game->reset = false;
	game->anim_idx = 0;
	game->player->life = 4;
	game->player->action = 0;
	game->player->moving = false;
	free_array_ints(game->map->taken, game->map->height);
	game->map->taken = NULL;
	copying_map(game->map, game->cpy_map);
	game->victory = 0;
	game->moves = 0;
	game->map->taken = allocate_tab_memset(game->map);
	character_pos(game, game->player, game->map);
	chest_state(game, game->map);
}
