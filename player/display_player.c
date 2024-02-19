/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:27:02 by bwach             #+#    #+#             */
/*   Updated: 2024/02/19 16:08:39 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	*what_sprite(t_data *game)
{
	static int	pos;
	static int	last_anim;
	static int	now_anim;

	if (now_anim == 4)
	{
		
	}
}

void	display_character(t_data *game, t_play *p)
{
	if (!p)
		close_hk(53, game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		what_sprite(game), p->pos[0], p->pos[1]);
}
