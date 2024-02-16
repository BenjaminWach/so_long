/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:31:50 by bwach             #+#    #+#             */
/*   Updated: 2024/02/16 14:37:22 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	can_enter(t_data *game, t_map *m)
{
	t_play	*p;

	p = game->player;
	if (m->nb_obj > 0)
		return (false);
	else if (m->map[(m->exit->y + 1)][m->exit->x] == 'P')
	{
		return (true);
	}
	return (false);
}

void	castle(t_data *game, t_map *m)
{
	if (can_enter(game, m))
	{
		if (m->nb_obj == 0)
		{
			draw_pic(m->exit->x * 64, m->exit->y * 64, game->door[1], game);
			m->map[(m->exit->y)][m->exit->x] = '0';
		}
	}
	else
		draw_pic(m->exit->x * 64, m->exit->y * 64, game->door[0], game);
}
