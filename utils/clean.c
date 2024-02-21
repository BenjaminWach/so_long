/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:44:49 by bwach             #+#    #+#             */
/*   Updated: 2024/02/22 00:25:40 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	clear_map(t_map *m)
{
	free(m->str);
	m->str = NULL;
	if (m->map)
	{
		free_array(m->map, m->height);
		m->map = NULL;
	}
	if (m->walls_sp)
	{
		free_array_ints(m->walls_sp, m->height);
		m->walls_sp = NULL;
	}
	if (m->taken)
	{
		free_array_ints(m->taken, m->height);
		m->taken = NULL;
	}
	if (m->exit)
	{
		free(m->exit);
		m->exit = NULL;
	}
}

int	free_array_ints(int **clean, int hgt)
{
	int	x;

	x = 0;
	while (x < hgt)
	{
		free(clean[x]);
		x++;
	}
	free(clean);
	return (0);
}

int	free_array(char **clean, int hgt)
{
	int	x;

	x = 0;
	if (hgt == 0)
	{
		while (clean[x])
		{
			free(clean[x]);
			x++;
		}
	}
	else
	{
		while (x < hgt)
		{
			free(clean[x]);
			x++;
		}
	}
	free(clean);
	return (0);
}

void	free_und_exit(t_data *game, t_map *m)
{
	int	i;

	i = 0;
	free_array(game->cpy_map, m->height);
	clear_sprites(game);
	if (m != NULL)
	{
		clear_map(m);
		free(m);
		m = NULL;
	}
	if (game->player)
	{
		free(game->player);
		game->player = NULL;
	}
}
