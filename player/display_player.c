/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:27:02 by bwach             #+#    #+#             */
/*   Updated: 2024/02/21 01:57:21 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	actual_player_sprite(t_data *game)
{
	if ((game->player->ac[0] == 2 || game->player->ac[1] == 2)
		|| game->player->ac[0] == 1 || game->player->ac[1] == 1)
		return (get_walk_sprite(game));
	else
		return (up_down(game));
}

//static variable are initialized at 0 when not atributted
static int	*get_player_sprite(t_data *game)
{
	static int	now;
	static int	inter;

	if (inter == 10)
	{
		inter = 0;
		now = actual_player_sprite(game);
	}
	else
		inter++;
	return (game->p_mv[now]);
}

void	display_character(t_data *game, t_play *p)
{
	if (!p)
		close_hk(53, game);
	if (p->moving)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			get_player_sprite(game), p->pos[0], p->pos[1]);
	else
		display_idle(game, p);
}
