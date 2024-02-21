/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:46:24 by bwach             #+#    #+#             */
/*   Updated: 2024/02/20 22:57:23 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
		x = [0] : y = [1];
		
hg (x, y) ------------ hd (x + 64, y)
  |                           |
  |                           |
  |                           |
  |                           |
g (x, y + 64) -------- d (x + 64, y + 64)
*/

static void	update_hitbox(t_play *p)
{
	int	hitbox_margin;

	hitbox_margin = 15;
	p->top_l[0] = p->pos[0] + hitbox_margin;
	p->top_l[1] = p->pos[1] + hitbox_margin;
	p->top_r[0] = p->pos[0] + 64 - hitbox_margin;
	p->top_r[1] = p->pos[1] + hitbox_margin;
	p->bot_l[0] = p->pos[0] + hitbox_margin;
	p->bot_l[1] = p->pos[1] + 64 - hitbox_margin;
	p->bot_r[0] = p->pos[0] + 64 - hitbox_margin;
	p->bot_r[1] = p->pos[1] + 64 - hitbox_margin;
}

static void	player_position(t_data *game)
{
	t_play	*p;

	p = game->player;
	p->hg[0] = p->pos[0];
	p->hg[1] = p->pos[1];
	p->hd[0] = p->hg[0] + 64;
	p->hd[1] = p->hg[1];
	p->g[0] = p->hg[0];
	p->g[1] = p->hg[1] + 64;
	p->d[0] = p->hg[0] + 64;
	p->d[1] = p->hg[1] + 64;
	update_hitbox(p);
}

static char	**copying_map(t_map *map, char **cpy)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_memcpy(cpy[i], map->map[i], map->width * sizeof(char));
		i++;
	}
	return (cpy);
}

static void draw_hitbox(t_data *game, t_play *player)
{
    int x, y;

    // Dessiner le bord supérieur de la hitbox
    for (x = player->top_l[0]; x <= player->top_r[0]; x++)
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, player->top_l[1], 0xFFFFFF);

    // Dessiner le bord inférieur de la hitbox
    for (x = player->bot_l[0]; x <= player->bot_r[0]; x++)
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, player->bot_l[1], 0xFFFFFF);

    // Dessiner le bord gauche de la hitbox
    for (y = player->top_l[1]; y <= player->bot_l[1]; y++)
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, player->top_l[0], y, 0xFFFFFF);

    // Dessiner le bord droit de la hitbox
    for (y = player->top_r[1]; y <= player->bot_r[1]; y++)
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, player->top_r[0], y, 0xFFFFFF);
}

int	run_loop(t_data *game)
{
	long long	act_time;
	long long	diff;

	act_time = time_now();
	diff = act_time - game->last_time;
	if (diff > 31)
	{
		if (game->reset)
		{
			game->reset = false;
			copying_map(game->map, game->cpy_map);
			if (!game->map->walls_sp)
				error_msg(ERR_CPY);
		}
		frame_per_second(game);
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		player_position(game);
		environment(game, game->map);
		forest(game, game->map);
		chest(game, game->map);
		castle(game, game->map);
		player(game);
		draw_hitbox(game, game->player);
	}
	return (1);
}
