/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:24:15 by bwach             #+#    #+#             */
/*   Updated: 2024/02/21 17:57:28 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	size_map(t_map *map)
{
	size_t	len;
	size_t	high;

	len = map->width;
	high = 0;
	while (high < map->height)
	{
		if (len != ft_strlen(map->map[high]))
			return (-1);
		if (map->map[high][0] != '1' || map->map[high][len - 1] != '1')
			return (-1);
		high++;
	}
	if (map->map[0][0] != '1' || map->map[0][len - 1] != '1')
		return (-1);
	return (0);
}

static int	basic_map(t_map *map)
{
	size_t	charac;
	size_t	end;
	size_t	len;

	map->nb_obj = 0;
	charac = 0;
	end = 0;
	len = 0;
	while (map->map[len / map->width])
	{
		if (!ft_strchr("CEP01", map->map[len / map->width][len % map->width]))
			error_map(ERR_CAR, 0);
		if (map->map[len / map->width][len % map->width] == 'E')
			end++;
		if (map->map[len / map->width][len % map->width] == 'C')
			map->nb_obj++;
		if (map->map[len / map->width][len % map->width] == 'P')
			charac++;
		len++;
	}
	if (charac < 1 || map->nb_obj < 1 || end != 1)
		return (-1);
	return (0);
}

static int	can_finish(t_map *map)
{
	map->exit = malloc(sizeof(t_pos));
	map->exit->x = 0;
	map->exit->y = 0;
	exit_pos(map);
	printf("coordonnees sortie:\nx: %d y: %d\n", map->exit->x, map->exit->y);
	if (check_fill(map, map->exit) != 0)
		return (-1);
	return (0);
}

int	valid_map(t_map *map)
{
	if (size_map(map) != 0)
	{
		error_map(ERR_MAP, 1);
		return (-1);
	}
	if (basic_map(map) != 0)
	{
		error_map(ERR_MAP, 2);
		return (-1);
	}
	if (can_finish(map) != 0)
	{
		error_map(ERR_MAP, 3);
	}
	return (0);
}
