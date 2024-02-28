/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:53:40 by bwach             #+#    #+#             */
/*   Updated: 2024/02/28 01:31:51 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	random_walls(t_data *game, t_map *m, size_t len)
{
	if (m->walls_sp[len / m->width][len % m->width] == 0)
	{
		draw_pic((len % m->width) * 64, (len / m->width) * 64,
			game->env[0], game);
	}
	if (m->walls_sp[len / m->width][len % m->width] == 1)
	{
		draw_pic((len % m->width) * 64, (len / m->width) * 64,
			game->env[1], game);
	}
}

static void	draw_monster(t_data *game, t_map *m, size_t len)
{
	static int	i = 2;
	static int	count = 0;

	if (m->map[len / m->width][len % m->width] == 'M')
	{
		draw_pic((len % m->width) * 64, (len / m->width) * 64,
			game->env[i], game);
		count++;
		if (count % 41 == 0)
		{
			i = (i % 6) + 2;
		}
	}
}

void	forest(t_data *game, t_map *m)
{
	size_t		len;

	len = 0;
	while (m->map[len / m->width])
	{
		if (m->map[len / m->width][len % m->width] == '1')
		{
			random_walls(game, m, len);
		}
		len++;
	}
}

void	monster(t_data *game, t_map *m)
{
	size_t		len;

	len = 0;
	while (m->map[len / m->width])
	{
		if (m->map[len / m->width][len % m->width] == 'M' &&
			game->player->is_dead == false)
		{
			draw_monster(game, m, len);
			if (collision_death(m, game->player) == 1)
				is_dead(game->player, game);
		}
		len++;
	}
}
