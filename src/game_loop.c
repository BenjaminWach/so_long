/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:46:24 by bwach             #+#    #+#             */
/*   Updated: 2024/02/26 16:14:33 by bwach            ###   ########.fr       */
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

static void	draw_hitbox(t_data *game, t_play *player)
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

/*static void	draw_wall_hitboxes(t_data *game, t_map *map)
{
    int x, y, i, j;

    // Loop through each tile in the map
    for (y = 0; y < map->height; y++)
    {
        for (x = 0; x < map->width; x++)
        {
            // If the tile is a wall
            if (map->map[y][x] == '1')
            {
                // Convert map coordinates to pixel coordinates
                int pixel_x = x * 64;
                int pixel_y = y * 64;

                // Draw the top border of the hitbox
                for (i = pixel_x; i <= pixel_x + 64; i++)
                    mlx_pixel_put(game->mlx_ptr, game->win_ptr, i, pixel_y, 0xFFFFFF);

                // Draw the bottom border of the hitbox
                for (i = pixel_x; i <= pixel_x + 64; i++)
                    mlx_pixel_put(game->mlx_ptr, game->win_ptr, i, pixel_y + 64, 0xFFFFFF);

                // Draw the left border of the hitbox
                for (j = pixel_y; j <= pixel_y + 64; j++)
                    mlx_pixel_put(game->mlx_ptr, game->win_ptr, pixel_x, j, 0xFFFFFF);

                // Draw the right border of the hitbox
                for (j = pixel_y; j <= pixel_y + 64; j++)
                    mlx_pixel_put(game->mlx_ptr, game->win_ptr, pixel_x + 64, j, 0xFFFFFF);
            }
        }
    }
}*/

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
	player(game);
	//draw_wall_hitboxes(game, game->map);
	draw_hitbox(game, game->player);
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
