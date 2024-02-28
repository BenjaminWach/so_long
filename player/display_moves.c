/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:35:44 by bwach             #+#    #+#             */
/*   Updated: 2024/02/28 02:08:10 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_death(t_data *game, t_play *p)
{
	if (game->death_anim <= 10)
	{
		if (p->direction_death == 1 || p->direction_death == 3)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->death[game->death_anim], p->pos[0], p->pos[1]);
		}
		else if (p->direction_death == 0 || p->direction_death == 4)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->death[game->death_anim + 11], p->pos[0], p->pos[1]);
		}
		if (game->death_anim < 10)
			game->death_anim++;
	}
}

void	display_idle(t_data *game, t_play *p)
{
	static int	i;
	static int	counter;

	if (counter == 10)
	{
		if (p->direction)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->p[i], p->pos[0], p->pos[1]);
		}
		else if (p->direction == 0)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->p[i + 6], p->pos[0], p->pos[1]);
		}
		i = (i + 1) % 6;
	}
	else
		counter++;
}

int	get_walk_sprite(t_data *game)
{
	static int	i;

	if (game->player->direction == 1)
	{
		if (i < 0 || i >= 8)
			i = 0;
		else
			i = ((i - 0 + 1) % 8) + 0;
	}
	if (game->player->direction == 0)
	{
		if (i < 8 || i >= 16)
			i = 8;
		else
			i = ((i - 8 + 1) % 8) + 8;
	}
	return (i);
}

int	up_down(t_data *game)
{
	static int	i;

	if (game->player->direction == 4)
	{
		if (i < 16 || i >= 19)
			i = 16;
		else
			i = ((i - 16 + 1) % 3) + 16;
	}
	else if (game->player->direction == 3)
	{
		if (i < 19 || i >= 22)
			i = 19;
		else
			i = ((i - 19 + 1) % 3) + 19;
	}
	else
	{
		if (game->player->direction == 1)
			return (0);
		else if (game->player->direction == 2)
			return (8);
	}
	return (i);
}
