/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:49:24 by bwach             #+#    #+#             */
/*   Updated: 2024/02/16 02:15:57 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;

	srand(time(NULL));
	if (argc != 2)
		error_msg(ERR_ARG);
	init_game_mlx(&game, argv);
	init_sprites(&game);
	print_map(game.map);
	key_hooks(&game);
	mlx_loop_hook(game.mlx_ptr, run_loop, &game);
	mlx_loop(game.mlx_ptr);
	return (EXIT_SUCCESS);
}
