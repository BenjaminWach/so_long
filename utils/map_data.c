/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:51:18 by bwach             #+#    #+#             */
/*   Updated: 2024/02/21 17:59:05 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_height(t_map *map)
{
	int	y;

	y = 0;
	while (map->map[y])
	{
		y++;
	}
	return (y);
}

int	get_width(t_map *map)
{
	int	x;

	x = 0;
	while (map->map[0][x])
	{
		x++;
	}
	return (x);
}

void	exit_pos(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'E')
			{
				map->exit->x = x;
				map->exit->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	error_msg(POS_NOT_FOUND);
	map->exit->x = -1;
	map->exit->y = -1;
}

static void	dfs(t_map *map, t_pos node, int **visited, int *total_player)
{
	if (node.x < 0 || node.x >= map->width || node.y < 0
		|| node.y >= map->height)
		return ;
	if (visited[node.y][node.x] || map->map[node.y][node.x] == '1')
		return ;
	visited[node.y][node.x] = 1;
	if (map->map[node.y][node.x] == 'C')
		map->total_obj++;
	if (map->map[node.y][node.x] == 'P')
		(*total_player)++;
	dfs(map, (t_pos){node.x, node.y - 1}, visited, total_player);
	dfs(map, (t_pos){node.x, node.y + 1}, visited, total_player);
	dfs(map, (t_pos){node.x - 1, node.y}, visited, total_player);
	dfs(map, (t_pos){node.x + 1, node.y}, visited, total_player);
}

int	check_fill(t_map *map, t_pos *exit)
{
	int		**visited;
	int		y;
	int		x;
	int		total_player;

	y = 0;
	total_player = 0;
	visited = allocate_tab_memset(map);
	dfs(map, *exit, visited, &total_player);
	printf("objets trouves: %d / %d\n", map->total_obj, map->nb_obj);
	if (map->nb_obj != map->total_obj || total_player < 1)
		return (-1);
	//free_array_ints(visited, map->height);
	return (0);
}
