/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:11:19 by bwach             #+#    #+#             */
/*   Updated: 2024/02/20 13:16:47 by bwach            ###   ########.fr       */
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
	int		i;
	int		j;

	map = game->map->map;
	j = p->pos[0] / 64;
	i = p->pos[1] / 64;
	if (!p)
		close_hk(53, game);
	if (p->ac[0] == 1 && map[i][j + 1] != '1')
		p->pos[0] -= MVX;
	else if (p->ac[0] == 2 && map[i][j - 1] != '1')
		p->pos[0] += MVX;
	else if (p->ac[0] == 4 && map[i - 1][j] != '1')
		p->pos[1] -= MVX;
	else if (p->ac[0] == 3 && map[i + 1][j] != '1')
		p->pos[1] += MVX;
}
