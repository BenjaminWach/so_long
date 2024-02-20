/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:27:02 by bwach             #+#    #+#             */
/*   Updated: 2024/02/20 04:29:17 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	actual_player_sprite(int *last, t_data *game)
{
	if ((game->player->ac[0] == 2 || game->player->ac[1] == 2) ||
		game->player->ac[0] == 1 || game->player->ac[1] == 1)
			return (get_walk_sprite(last, game));
	//else if (atk > 0)
		//return (get_atk_sprite(last, game));
}

//static variable are initialized at 0 when not atributted
static int	*get_player_sprite(t_data *game)
{
	static int	now;
	static int	inter;
	static int	last;
	//static int	atk;

	//if (game->player->ac[2] == 5)
		//atk = 5;
	if (inter == 40)
	{
		inter = 0;
		//if (atk > 0)
		//	atk--;
		now = actual_player_sprite(&last, game);
	}
	else
		inter++;
	return (game->p_mv[now]);
}

void	display_character(t_data *game, t_play *p)
{
	if (!p)
		close_hk(53, game);
	//if (p->ac[2] == 5)
	//	get_player_sprite(game);
	if (p->moving)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			get_player_sprite(game), p->pos[0], p->pos[1]);
	else		
		display_idle(game, p);
}
