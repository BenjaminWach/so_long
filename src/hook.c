/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:35:50 by bwach             #+#    #+#             */
/*   Updated: 2024/02/24 16:06:03 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	print_loose(void)
{
	ft_printf(RED"\n\
█████████████████████████████████████████████████████████████████████\n\
██                                                                 ██\n\
██  ███  ███  ██████  ██    ██     ██      ██████   ██████ ██████  ██\n\
██   ██  ██  ██    ██ ██    ██     ██     ██    ██ ██      ██      ██\n\
██    ████   █      █ ██    ██     ██     █      █   ████  █████   ██\n\
██     ██    ██    ██ ██    ██     ██     ██    ██      ██ ██      ██\n\
██     ██     ██████    ████       ██████  ██████  ██████  ██████  ██\n\
██                                                                 ██\n\
█████████████████████████████████████████████████████████████████████\n\n\
"RESET);
}

//close the window
int	close_hk(int keycode, t_data *game)
{
	if (keycode == 53)
	{
		free_und_exit(game, game->map);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		print_loose();
		exit (EXIT_FAILURE);
	}
	print_loose();
	exit (EXIT_SUCCESS);
	return (0);
}

//on pressure
static int	key_press(int keycode, t_data *game)
{
	set_action(keycode, game);
	return (0);
}

//on release
static int	key_up(int keycode, t_data *game)
{
	if (keycode == 53)
		close_hk(keycode, game);
	else if (keycode == 15)
		game->reset = true;
	else
		unset_action(keycode, game);
	return (0);
}

//handle the pression on the keyboard
void	key_hooks(t_data *game)
{
	mlx_hook(game->win_ptr, 17, (1L << 17), close_hk, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, key_up, game);
}
