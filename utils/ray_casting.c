/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:03:18 by bwach             #+#    #+#             */
/*   Updated: 2024/02/26 23:36:17 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	dist_to_right(t_map *m, t_play *p)
{
	int	dist_to_wall;

	dist_to_wall = 4;
	if (m->map[(p->top_r[1]) / 64][(p->top_r[0] + 4) / 64] == '1' &&
		m->map[(p->bot_r[1]) / 64][(p->bot_r[0] + 4) / 64] != '1')
	{
		if (m->map[(p->bot_r[1]) / 64][(p->bot_r[0] + 5) / 64] == '1')
			return (-4);
		else
			return (4);
	}
	if (m->map[(p->bot_r[1] / 64)][(p->bot_r[0] + 4) / 64] == '1' ||
		m->map[(p->top_r[1] / 64)][(p->top_r[0] + 4) / 64] == '1')
	{
		dist_to_wall = (p->bot_r[0] + 4) / 64 - (p->bot_r[0] / 64);
		if (m->map[(p->top_r[1] / 64)][(p->top_r[0] + 4) / 64] == '1' ||
			m->map[(p->bot_r[1] / 64)][(p->bot_r[0] + 4) / 64] == '1')
			return (dist_to_wall);
		else if (dist_to_wall > 4)
			return (4);
	}
	return (4);
}

int	dist_to_left(t_map *m, t_play *p)
{
	int	dist_to_wall;

	dist_to_wall = 4;
	if (m->map[(p->top_l[1]) / 64][(p->top_l[0] - 4) / 64] == '1'
		&& m->map[(p->bot_l[1]) / 64][(p->bot_l[0] - 4) / 64] != '1')
	{
		if (m->map[(p->bot_l[1]) / 64][(p->bot_l[0] - 4) / 64] == '1')
			return (-4);
		else
			return (4);
	}
	if (m->map[(p->bot_l[1] / 64)][(p->bot_l[0] - 4) / 64] == '1' ||
		m->map[(p->top_l[1] / 64)][(p->top_l[0] - 4) / 64] == '1')
	{
		dist_to_wall = (p->bot_l[0] - 4) / 64 - (p->bot_l[0] / 64);
		if (m->map[(p->top_l[1] / 64)][(p->top_l[0] + 4) / 64] == '1' ||
			m->map[(p->bot_l[1] / 64)][(p->bot_l[0] + 4) / 64] == '1')
			return (dist_to_wall);
		else if (dist_to_wall > 4)
			return (4);
	}
	return (4);
}

int	dist_to_top(t_map *m, t_play *p)
{
	int	dist_to_wall;

	dist_to_wall = 4;
	if (m->map[(p->bot_r[1] - 12) / 64][(p->bot_r[0]) / 64] == '1' ||
		m->map[(p->bot_l[1] - 12) / 64][(p->bot_l[0]) / 64] == '1')
	{
		dist_to_wall = ((p->top_l[1] - 4) / 64) - (p->top_l[1] / 64);
		if (m->map[(p->top_l[1] - 4) / 64][(p->top_l[0]) / 64] == '1' ||
			m->map[(p->top_r[1] - 4) / 64][(p->top_r[0]) / 64] == '1')
			return (dist_to_wall);
		else if (dist_to_wall > 4)
			return (4);
	}
	return (4);
}

int	dist_to_bot(t_map *m, t_play *p)
{
	int	dist_to_wall;

	dist_to_wall = 4;
	if (m->map[(p->top_r[1]) / 64][(p->top_r[0]) / 64] == '1' &&
		m->map[(p->bot_r[1]) / 64][(p->bot_r[0]) / 64] != '1')
	{
		return (4);
	}
	if (m->map[(p->bot_r[1] + 4) / 64][(p->bot_r[0]) / 64] == '1' ||
		m->map[(p->bot_l[1] + 4) / 64][(p->bot_l[0]) / 64] == '1')
	{
		dist_to_wall = (p->bot_l[1] + 4) / 64 - (p->bot_l[1] / 64);
		if (m->map[(p->bot_l[1] + 4) / 64][(p->bot_l[0]) / 64] == '1' ||
			m->map[(p->bot_r[1] + 4) / 64][(p->bot_r[0]) / 64] == '1')
			return (dist_to_wall);
		else if (dist_to_wall > 4)
			return (4);
	}
	return (4);
}
