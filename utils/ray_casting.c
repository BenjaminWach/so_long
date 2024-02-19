/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:03:18 by bwach             #+#    #+#             */
/*   Updated: 2024/02/19 13:54:24 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	distance_right(t_data *game, t_map *m)
{
	t_play	*p;
	char	**mp;
	int		dist;
	int		i;

	dist = 0;
	i = 0;
	p = game->player;
	mp = m->map;
	while (i < MVX)
	{
		if (mp[(p->top_r[1] + HPX + i) / 64][(p->top_r[0] / 64) + 1] == '1' ||
			mp[(p->bot_r[1] + HPX + i) / 64][(p->bot_r[0] / 64) + 1] == '1')
		{
			return (-(i + 10));
		}
		dist = (((p->bot_r[0] / 64 + 1) * 64) - p->bot_r[0]);
		if (dist > i)
			return (i);
		i++;
	}
	return (MVX);
}

static int	distance_left(t_data *game, t_map *m)
{
	t_play	*p;
	char	**mp;
	int		dist;
	int		i;

	dist = 0;
	i = 0;
	p = game->player;
	mp = m->map;
	while (i < MVX)
	{
		if (mp[(p->top_l[1] + HPX + i) / 64][(p->top_l[0] / 64) - 1] == '1' ||
			mp[(p->bot_l[1] + HPX + i) / 64][(p->bot_l[0] / 64) - 1] == '1')
		{
			return (-(i + 10));
		}
		dist = (((p->bot_l[0] / 64 - 1) * 64) - p->bot_l[0]);
		if (dist > i)
			return (i);
		i++;
	}
	return (MVX);
}

static int	distance_up(t_data *game, t_map *m)
{
	t_play	*p;
	char	**mp;
	int		dist;
	int		i;

	dist = 0;
	i = 0;
	p = game->player;
	mp = m->map;
	while (i < MVX)
	{
		if (mp[(p->top_l[1] / 64) - 1][(p->top_l[0] + HPX + i) / 64] == '1' ||
			mp[(p->top_r[1] / 64) - 1][(p->top_r[0] + HPX + i) / 64] == '1')
		{
			return (-(i + 10));
		}
		dist = (((p->top_l[1] / 64 - 1) * 64) - p->top_l[1]);
		if (dist > i)
			return (i);
		i++;
	}
	return (MVX);
}

static int	distance_down(t_data *game, t_map *m)
{
	t_play	*p;
	char	**mp;
	int		dist;
	int		i;

	dist = 0;
	i = 0;
	p = game->player;
	mp = m->map;
	while (i < MVX)
	{
		if (mp[(p->bot_l[1] / 64) + 1][(p->bot_l[0] + HPX + i) / 64] == '1' ||
			mp[(p->bot_r[1] / 64) + 1][(p->bot_r[0] + HPX + i) / 64] == '1')
		{
			return (-(i + 10));
		}
		dist = (((p->bot_l[1] / 64 + 1) * 64) - p->bot_l[1]);
		if (dist > i)
			return (i);
		i++;
	}
	return (MVX);
}

void	mini_raycasting(t_data *game, t_map *map)
{
	t_play	*p;

	p = game->player;
	p->right = distance_right(game, map);
	p->left = distance_left(game, map);
	p->up = distance_up(game, map);
	p->down = distance_down(game, map);
}
