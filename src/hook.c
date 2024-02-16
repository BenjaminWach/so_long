/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:35:50 by bwach             #+#    #+#             */
/*   Updated: 2024/02/16 13:56:01 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//close the window
static int	close_hk(int keycode, t_data *game)
{
	if (keycode == 53)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit (EXIT_SUCCESS);
	return (0);
}

//on pressure
static int	key_press(int keycode, t_data *game)
{
	printf("keycode envoye: %d\n", keycode);
	set_action(keycode, game);
	return (0);
}

//on release
static int	key_up(int keycode, t_data *game)
{
	printf("keycode envoye dans key_up: %d\n", keycode);
	if (keycode == 53)
		close_hk(keycode, game);
	//else if (keycode == 15)
		//reset_game(game);
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
