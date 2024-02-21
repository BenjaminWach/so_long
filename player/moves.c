/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:11:19 by bwach             #+#    #+#             */
/*   Updated: 2024/02/21 02:13:36 by bwach            ###   ########.fr       */
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
	int		xg;
	int		yg;
	int		xd;
	int		yd;

	map = game->map->map;
	xg = p->bot_l[0] / 64;
	yg = p->bot_l[1] / 64;
	xd = p->bot_r[0] / 64;
	yd = p->bot_r[1] / 64;
	if (!p)
		close_hk(53, game);
	if (p->ac[0] == 1 && map[yd][xd + 1] != '1' && map[yg][xg + 1] != '1')
		p->pos[0] -= 4;
	else if (p->ac[0] == 2 && map[yg][xg - 1] != '1' && map[yd][xd - 1] != '1')
		p->pos[0] += 4;
	else if (p->ac[0] == 4 && map[yg - 1][xg] != '1' && map[yg - 1][xd] != '1')
		p->pos[1] -= 4;
	else if (p->ac[0] == 3 && map[yg + 1][xg] != '1' && map[yd + 1][xd] != '1')
		p->pos[1] += 4;
}
