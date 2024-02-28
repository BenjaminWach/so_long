/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:11:19 by bwach             #+#    #+#             */
/*   Updated: 2024/02/28 00:19:29 by bwach            ###   ########.fr       */
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
	if (p->is_dead == true)
		return ;
	else
	{
		if (p->action == 1)
		{
			p->pos[0] -= dist_to_left(game->map, p);
		}
		else if (p->action == 2)
		{
			p->pos[0] += dist_to_right(game->map, p);
		}
		else if (p->action == 4)
		{
			p->pos[1] -= dist_to_top(game->map, p);
		}
		else if (p->action == 3)
		{
			p->pos[1] += dist_to_bot(game->map, p);
		}
	}
}
