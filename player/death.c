/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:39:31 by bwach             #+#    #+#             */
/*   Updated: 2024/02/27 15:06:53 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	print_death(void)
{
	ft_printf(RED"\n\
█████████████████████████████████████████████████████████████████████\n\
██                                                                 ██\n\
██    ██    ██  ██████  ██    ██     ██████  ██ ███████ ██████     ██\n\
██     ██  ██  ██    ██ ██    ██     ██   ██ ██ ██      ██   ██    ██\n\
██      ████   ██    ██ ██    ██     ██   ██ ██ █████   ██   ██    ██\n\
██       ██    ██    ██ ██    ██     ██   ██ ██ ██      ██   ██    ██\n\
██       ██     ██████   ██████      ██████  ██ ███████ ██████     ██\n\
██                                                                 ██\n\
█████████████████████████████████████████████████████████████████████\n\n\
"RESET);
}

void	is_dead(t_play *p, t_data *game)
{
	char	*msg;
	t_map	*m;

	m = game->map;
	if (p->life <= 0)
	{
		msg = "QUIT(ESC) or RESTART(r)";
		mlx_string_put(game->mlx_ptr, game->win_ptr, m->width * 64 \
			/ 2 - 32, (m->height * 64) / 2, 0xFF0000, "YOU DIED !");
		mlx_string_put(game->mlx_ptr, game->win_ptr, m->width * 64 \
			/ 2 - 80, (m->height * 64) / 2 + 32, 0xFFFFFF, msg);
		print_death();
	}
}

int	collision_death(t_map *m, t_play *p)
{
	int	collision;

	collision = 0;
	if (m->map[(p->top_l[1] + 32) / 64][(p->top_l[0] + 32) / 64] == 'M')
	{
		p->life--;
		collision = 1;
	}
	if (m->map[(p->top_r[1] + 32) / 64][(p->top_r[0] - 32) / 64] == 'M')
	{
		p->life--;
		collision = 1;
	}
	if (m->map[(p->bot_l[1] - 32) / 64][(p->top_l[0] + 32) / 64] == 'M')
	{
		p->life--;
		collision = 1;
	}
	if (m->map[(p->bot_r[1] - 32) / 64][(p->top_l[0] - 32) / 64] == 'M')
	{
		p->life--;
		collision = 1;
	}
	return (collision);
}
