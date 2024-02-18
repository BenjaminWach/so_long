/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:12:55 by bwach             #+#    #+#             */
/*   Updated: 2024/02/17 01:15:34 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_map *map)
{
	int	y;
	int	x;

	printf("\n");
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			printf("%c", map->map[y][x]);
			x++;
		}
		y++;
		printf("\n");
	}
	printf("\n");
}

void	print_visited(int **visited, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			printf("%d ", visited[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
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
	//print_visited(array, map->height, map->width);
	return (array);
}
