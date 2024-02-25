/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:31:50 by bwach             #+#    #+#             */
/*   Updated: 2024/02/24 02:37:03 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_victory(t_data *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	ft_printf(GREEN"\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
"RESET);
	ft_printf("\nESC ou R(restart)\n");
}

static int	collision_door(t_play *p, t_map *m)
{
	if (m->map[(p->top_r[1]) / 64][(p->top_r[0] + 3) / 64] == 'E')
		return (0);
	if (m->map[(p->top_l[1]) / 64][(p->top_l[0] - 2) / 64] == 'E')
		return (0);
	if (m->map[(p->bot_l[1] - 5) / 64][(p->bot_l[0]) / 64] == 'E')
		return (0);
	if (m->map[(p->bot_r[1] - 5) / 64][(p->bot_r[0]) / 64] == 'E')
		return (0);
	else
		return (1);
}

void	castle(t_data *game, t_map *m)
{
	t_play	*p;

	p = game->player;
	if (m->nb_obj == 0)
	{
		draw_pic(m->exit->x * 64, m->exit->y * 64, game->door[1], game);
		if (collision_door(p, m) == 0 && game->victory == 0)
		{
			game->victory = 1;
			ft_victory(game);
		}
	}
	else if (m->nb_obj != 0)
	{
		draw_pic(m->exit->x * 64, m->exit->y * 64, game->door[0], game);
	}
}
