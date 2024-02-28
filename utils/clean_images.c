/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:35:18 by bwach             #+#    #+#             */
/*   Updated: 2024/02/27 23:27:54 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	clear_env(t_data *game, int i)
{
	while (i < 10)
	{
		mlx_destroy_image(game->mlx_ptr, game->env[i]);
		i++;
	}
}

static void	clear_obj(t_data *game, int i)
{
	while (i < 2)
	{
		mlx_destroy_image(game->mlx_ptr, game->obj[i]);
		mlx_destroy_image(game->mlx_ptr, game->door[i]);
		i++;
	}
}

static void	clear_char(t_data *game, int i)
{
	while (i < 12)
	{
		mlx_destroy_image(game->mlx_ptr, game->p[i]);
		i++;
	}
	i = 0;
	while (i < 22)
	{
		mlx_destroy_image(game->mlx_ptr, game->death[i]);
		i++;
	}
}

static void	clear_moves(t_data *game, int i)
{
	while (i < 22)
	{
		mlx_destroy_image(game->mlx_ptr, game->p_mv[i]);
		i++;
	}
}

void	clear_sprites(t_data *game)
{
	clear_env(game, 0);
	clear_obj(game, 0);
	clear_char(game, 0);
	clear_moves(game, 0);
}
