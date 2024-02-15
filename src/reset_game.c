/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:05:38 by bwach             #+#    #+#             */
/*   Updated: 2024/02/15 11:44:17 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	reset_game(t_data *game)
{
	game->reset = true;
	return (0);
}

/*
/// @brief fonction pour reset le jeu dans la boucle
/// @param game 
void hard_reset(t_game *game)
{

}*/