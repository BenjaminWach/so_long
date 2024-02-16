/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:53:40 by bwach             #+#    #+#             */
/*   Updated: 2024/02/16 02:59:01 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_not_surrended(t_map *m, size_t len)
{
	int	count;
	int	x;
	int	y;

	x = len % m->width;
	y = len / m->width;
	count = 0;
	if (x > 0 && m->map[y][x - 1] == '1')
		count++;
	if (x < m->width - 1 && m->map[y][x + 1] == '1')
		count++;
	if (y > 0 && m->map[y - 1][x] == '1')
		count++;
	if (y < m->height - 1 && m->map[y + 1][x] == '1')
		count++;
	return (count == 0);
}

static void	display_pond(t_data *game, t_map *map, size_t len)
{
	int	x;
	int	y;

	x = len % map->width;
	y = len / map->width;
	if (is_not_surrended(map, len) && x < map->width - 1 && y < map->height - 1
		&& map->map[y][x + 1] == '0' && map->map[y + 1][x] == '0'
		&& map->map[y + 1][x + 1] == '0')
	{
		draw_pic(x * 64, y * 64, game->env[2], game);
		draw_pic((x + 1) * 64, y * 64, game->env[3], game);
		draw_pic(x * 64, (y + 1) * 64, game->env[4], game);
		draw_pic((x + 1) * 64, (y + 1) * 64, game->env[5], game);
	}
}

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

void	forest(t_data *game, t_map *m)
{
	size_t	len;

	len = 0;
	while (m->map[len / m->width])
	{
		if (m->map[len / m->width][len % m->width] == '1')
		{
			if (is_not_surrended(m, len))
				display_pond(game, m, len);
			else
				random_walls(game, m, len);
		}
		len++;
	}
}
