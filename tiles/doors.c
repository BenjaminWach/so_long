/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:31:50 by bwach             #+#    #+#             */
/*   Updated: 2024/02/21 01:07:43 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	castle(t_data *game, t_map *m)
{
	if (m->nb_obj == 0)
	{
		draw_pic(m->exit->x * 64, m->exit->y * 64, game->door[1], game);
	}
	else
		draw_pic(m->exit->x * 64, m->exit->y * 64, game->door[0], game);
}
