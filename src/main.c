/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:49:24 by bwach             #+#    #+#             */
/*   Updated: 2024/02/15 00:21:24 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;

	srand_(time(NULL));
	if (argc != 2)
		error_msg(ERR_ARG);
	init_game_mlx(&game, argv);
	init_sprites(&game);
	key_hooks(&game);
}