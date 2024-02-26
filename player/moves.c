/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:11:19 by bwach             #+#    #+#             */
/*   Updated: 2024/02/26 17:07:05 by bwach            ###   ########.fr       */
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

static int	is_wall(t_map *m, int x, int y)
{
	printf("on est la\n");
	if (x < 0 || x >= m->width || y < 0 || y >= m->height)
		return (1);
	if (m->map[y][x] == '1')
		return (1);
	else
	{
		return (0);
	}
}

void	character_mvt(t_data *game, t_play *p)
{
	char	**map;

	map = game->map->map;
	if (!p)
		close_hk(53, game);
	if (p->action == 1 && !is_wall(game->map, (p->top_l[0] - 4) / 64, (p->top_l[1]) / 64))
	{
		printf("left: %d\n", p->action);
		p->pos[0] -= 4;//dist_to_left(game->map, p);
	}
	else if (p->action == 2 && !is_wall(game->map, (p->top_r[0] + 4) / 64, (p->top_r[1] / 64)))
	{
		printf("right: %d\n", p->action);
		p->pos[0] += 4;//dist_to_right(game->map, p);
	}
	else if (p->action == 4)
		p->pos[1] -= 4; //mini_ray(ray, p, game->map);
	else if (p->action == 3)
		p->pos[1] += 4; //mini_ray(ray, p, game->map);
}
