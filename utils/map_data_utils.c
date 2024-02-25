/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:12:55 by bwach             #+#    #+#             */
/*   Updated: 2024/02/24 16:11:03 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(char **str, t_map *m)
{
	int	y;
	int	x;

	ft_printf("\n");
	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			ft_printf("%c", str[y][x]);
			x++;
		}
		y++;
		ft_printf("\n");
	}
	ft_printf("\n");
}

int	**allocate_tab_memset(t_map *map)
{
	int	**array;
	int	i;

	array = (int **)malloc(sizeof(int *) * map->height);
	if (!array)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		array[i] = malloc(sizeof(int) * map->width);
		if (!array[i])
			return (NULL);
		ft_memset(array[i], 0, map->width * sizeof(int));
		i++;
	}
	return (array);
}
