/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:42:47 by bwach             #+#    #+#             */
/*   Updated: 2024/02/16 15:09:28 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	character_mvt(t_data *game, t_play *p)
{
	move_right(game, p);
	move_left(game, p);
	move_up(game, p);
	move_dwn(game, p);
}

void	player(t_data *game)
{
	t_play	*p;

	p = game->player;
	p->lpos[0] = p->pos[0];
	p->lpos[1] = p->pos[1];
	character_mvt(game, p);
	mvt_count(game);
	display_character(game, p);
}
