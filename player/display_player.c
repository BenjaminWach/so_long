/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:27:02 by bwach             #+#    #+#             */
/*   Updated: 2024/02/28 00:22:00 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	actual_player_sprite(t_data *game)
{
	if (game->player->action == 2 || game->player->action == 1)
		return (get_walk_sprite(game));
	else
		return (up_down(game));
}

//static variable are initialized at 0 when not atributted
static int	*get_player_sprite(t_data *game)
{
	static int	inter;

	if (inter == 5)
	{
		inter = 0;
		game->anim_idx = actual_player_sprite(game);
	}
	else
		inter++;
	return (game->p_mv[game->anim_idx]);
}

void	display_character(t_data *game, t_play *p)
{
	if (!p)
		close_hk(53, game);
	if (p->is_dead == true)
	{
		display_death(game, p);
		is_dead(p, game);
	}
	if (p->moving && p->is_dead == false)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			get_player_sprite(game), p->pos[0], p->pos[1]);
	else
	{
		if (p->is_dead == false)
			display_idle(game, p);
	}
}
