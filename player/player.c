/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:42:47 by bwach             #+#    #+#             */
/*   Updated: 2024/02/20 13:16:55 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player(t_data *game)
{
	t_play	*p;

	p = game->player;
	p->lpos[0] = p->pos[0];
	p->lpos[1] = p->pos[1];
	//mini_raycasting(game, game->map);
	character_mvt(game, p);
	mvt_count(game);
	display_character(game, p);
}
