/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:49:24 by bwach             #+#    #+#             */
/*   Updated: 2024/02/28 11:37:43 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	is_ber(char *ber)
{
	int	len;

	len = ft_strlen(ber);
	if (len < 4)
		return (-1);
	if (ft_strncmp(&ber[len - 4], ".ber", 4) == 0)
		return (0);
	else
		return (-1);
}
//print_map(game.map->map, game.map);
int	main(int argc, char **argv)
{
	t_data	game;

	srand(time(NULL));
	if (argc != 2)
		error_msg(ERR_ARG, &game);
	if (is_ber(argv[1]) != 0)
		error_msg(ERR_BER, &game);
	init_game_mlx(&game, argv);
	init_sprites(&game);
	key_hooks(&game);
	mlx_loop_hook(game.mlx_ptr, run_loop, &game);
	mlx_loop(game.mlx_ptr);
	return (EXIT_SUCCESS);
}
