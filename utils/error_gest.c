/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_gest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:47:07 by bwach             #+#    #+#             */
/*   Updated: 2024/02/28 01:53:32 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return ;
}

void	error_msg(char *msg, t_data *game)
{
	write(2, msg, ft_strlen(msg));
	if (game->map->str)
		free(game->map->str);
	exit (EXIT_FAILURE);
}

void	error_map(char *msg, int err)
{
	if (err == 1)
		msg = ERR_MAP_SIZE;
	if (err == 2)
		msg = ERR_BASE_MAP;
	if (err == 3)
		msg = ERR_NO_END;
	write(2, msg, ft_strlen(msg));
	exit (EXIT_FAILURE);
}
