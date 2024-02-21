/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:35:44 by bwach             #+#    #+#             */
/*   Updated: 2024/02/21 01:57:11 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_idle(t_data *game, t_play *p)
{
	static int	i;
	static int	counter;

	if (counter == 3)
	{
		if (p->direction)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->p[i], p->pos[0], p->pos[1]);
		}
		else
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
		if (i >= 0 && i < 7)
			i++;
		else
			i = 0;
	}
	else if (game->player->direction == 0)
	{
		i = 8;
		if (i >= 8 && i < 15)
			i++;
		else
			i = 8;
	}
	return (i);
}

int	up_down(t_data *game)
{
	if (game->player->direction == 1)
		return (0);
	else
		return (8);
}
