/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_pond.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:06:59 by bwach             #+#    #+#             */
/*   Updated: 2024/02/15 11:15:00 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_surrended(t_map *map, size_t len)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = len % map->width;
	y = len / map->width;
	if (x > 0 && map->map[y][x - 1] == '1')
		count++;
	if (x < map->width - 1 && map->map[y][x + 1] == '1')
		count++;
	if (y > 0 && map->map[y - 1][x] == '1')
		count++;
	if (y < map->height - 1 && map->map[y + 1][x] == '1')
		count++;
	return (count == 0);
}

void	display_pond(t_data *game, t_map *map, size_t len)
{
	int	x;
	int	y;

	x = len % map->width;
	y = len / map->width;
	if (is_surrended(map, len) && x < map->width - 1 && y < map->height - 1
		&& map->map[y][x + 1] == '0' && map->map[y + 1][x] == '0'
		&& map->map[y + 1][x + 1] == '0')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->env[2], x * 64, y * 64);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->env[3], (x + 1) * 64, y * 64);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->env[4], x * 64, (y + 1) * 64);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->env[5], (x + 1) * 64, (y + 1) * 64);
	}
}
