/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:27:39 by bwach             #+#    #+#             */
/*   Updated: 2024/02/15 14:53:15 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	environment(t_data *game, t_map *m)
{
	size_t	len;

	len = 0;
	while (m->map[len / m->width])
	{
		if (m->map[len / m->width][len % m->width] == '0' ||
			m->map[len / m->width][len % m->width] == 'P' ||
			m->map[len / m->width][len % m->width] == 'C')
			draw_pic((len % m->width) * 64, (len / m->width) * 64,
				game->env[0], game);
	}
	len++;
}

/*
static void	set_wall(t_data *game, t_map *map)
{
	size_t	len;

	len = 0;
	while (map->map[len / map->width])
	{
		if (map->map[len / map->width][len % map->width] == '1')
		{
			if (is_surrended(map, len))
				display_pond(game, map, len);
			//else if (rand() % 2 == 0)
			//	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			//		game->env[6],
			//		(len % map->width) * 64, (len / map->width) * 64);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->env[7],
					(len % map->width) * 64, (len / map->width) * 64);
		}
		len++;
	}
}
*/