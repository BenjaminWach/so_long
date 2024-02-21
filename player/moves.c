/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:11:19 by bwach             #+#    #+#             */
/*   Updated: 2024/02/21 11:55:47 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mvt_count(t_data *game)
{
	if (game->player->lpos[0] != game->player->pos[0])
	{
		game->moves++;
		return ;
	}
	if (game->player->lpos[1] != game->player->pos[1])
	{
		game->moves++;
		return ;
	}
}

void	character_mvt(t_data *game, t_play *p)
{
	char	**map;

	map = game->map->map;
	if (!p)
		close_hk(53, game);
	if (p->ac[0] == 1)
		p->pos[0] -= 4;
	else if (p->ac[0] == 2)
		p->pos[0] += 4;
	else if (p->ac[0] == 4)
		p->pos[1] -= 4;
	else if (p->ac[0] == 3)
		p->pos[1] += 4;
}
