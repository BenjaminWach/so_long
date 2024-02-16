/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 23:15:03 by bwach             #+#    #+#             */
/*   Updated: 2024/02/16 01:20:32 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_pic(int x, int y, void *sprite, t_data *game)
{
	if (!game || !game->mlx_ptr || !game->win_ptr || !game->map
		|| !sprite)
		return ;
	if (x < -64 || y < -64 || x > ((game->map->width) * 64)
		|| y > ((game->map->height) * 64))
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite,
		x, y);
}
