/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:46:24 by bwach             #+#    #+#             */
/*   Updated: 2024/02/28 01:37:25 by bwach            ###   ########.fr       */
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

static void	player_position(t_data *game)
{
	t_play	*p;
	int		hitbox_margin;

	p = game->player;
	hitbox_margin = 15;
	p->top_l[0] = p->pos[0] + hitbox_margin;
	p->top_l[1] = p->pos[1] + hitbox_margin;
	p->top_r[0] = p->pos[0] + 64 - hitbox_margin;
	p->top_r[1] = p->pos[1] + hitbox_margin;
	p->bot_l[0] = p->pos[0] + hitbox_margin;
	p->bot_l[1] = p->pos[1] + 64 - hitbox_margin;
	p->bot_r[0] = p->pos[0] + 64 - (hitbox_margin + 1);
	p->bot_r[1] = p->pos[1] + 64 - (hitbox_margin + 1);
}

static void	mov_hud(t_data *game)
{
	char	*movements;
	char	*counts;
	int		x_pos;
	int		y_pos;

	movements = ft_itoa((game->moves) / 4);
	counts = ft_strjoin("MOVEMENTS : ", movements);
	x_pos = ((game->map->width * 64) / 2) - 64;
	y_pos = (game->map->height * 64) - 20;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->env[8],
		(x_pos), (y_pos));
	mlx_string_put(game->mlx_ptr, game->win_ptr, x_pos + (128 / 2) - 50 \
		, y_pos + (20 / 2) + 5, 0x0000FF, counts);
	free(movements);
	free(counts);
}

static void	victoire_menu(t_data *game, t_map *m)
{
	char	*msg;

	msg = "QUIT(ESC) or RESTART(r)";
	mlx_string_put(game->mlx_ptr, game->win_ptr, m->width * 64 \
			/ 2 - 32, (m->height * 64) / 2, 0x00FF00, "VICTOIRE !");
	mlx_string_put(game->mlx_ptr, game->win_ptr, m->width * 64 \
			/ 2 - 80, (m->height * 64) / 2 + 32, 0xFFFFFF, msg);
}

static void	game_render(t_data *game)
{
	player_position(game);
	environment(game, game->map);
	forest(game, game->map);
	chest(game, game->map);
	castle(game, game->map);
	monster(game, game->map);
	player(game);
	mov_hud(game);
}

int	run_loop(t_data *game)
{
	long long	act_time;
	long long	diff;

	act_time = time_now();
	diff = act_time - game->last_time;
	if (diff > 31)
	{
		frame_per_second(game);
		if (game->reset == true)
		{
			reset_game(game);
		}
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		if (game->victory == 0)
		{
			game_render(game);
		}
		else
			victoire_menu(game, game->map);
	}
	return (0);
}
