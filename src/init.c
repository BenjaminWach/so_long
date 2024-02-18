/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:54:00 by bwach             #+#    #+#             */
/*   Updated: 2024/02/17 01:08:57 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	**random_trees_sprites(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->walls_sp = malloc(map->height * sizeof(int *));
	while (y < map->height)
	{
		map->walls_sp[y] = malloc(map->width * sizeof(int));
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				map->walls_sp[y][x] = rand() % 2;
			else
				map->walls_sp[y][x] = -1;
			x++;
		}
		y++;
	}
	return (map->walls_sp);
}

static void	init_map(t_map *map, t_data *game)
{
	ssize_t	bytes_rd;

	map->fd = open(game->path, O_RDONLY);
	if (map->fd < 0)
		error_msg(ERR_FILE);
	map->str = malloc(sizeof(char) * 10000);
	if (!map->str)
		free_and_alloc(map->str);
	bytes_rd = read(map->fd, map->str, 10000);
	if (bytes_rd < 1)
		error_msg(ERR_FILE);
	map->str[bytes_rd] = '\0';
	map->map = ft_split(map->str, '\n');
	game->cpy_map = ft_split(map->str, '\n');
	if (!map->map || !game->cpy_map)
		error_msg(ERR_INIT);
	map->width = get_width(map);
	map->height = get_height(map);
	map->total_obj = 0;
	if (valid_map(map) != 0)
	{
		//free_map(map->map);
		exit (-1);
	}
	map->walls_sp = random_trees_sprites(map);
}

static int	init_player(t_data *game, t_map *map)
{
	size_t	len;

	len = 0;
	game->player->direction = 1;
	game->player->moving = false;
	while (map->map[len / map->width])
	{
		if (map->map[len / map->width][len % map->width] == 'P')
		{
			game->player->pos[0] = (len % map->width) * 64;
			game->player->pos[1] = (len / map->width) * 64 - 1;
		}
		len++;
	}
	return (0);
}

void	init_game_mlx(t_data *game, char **argv)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_msg(ERR_INIT);
	game->moves = 0;
	game->anim_idx = 0;
	game->path = argv[1];
	game->map = malloc(sizeof(t_map));
	game->player = malloc(sizeof(t_play));
	game->reset = false;
	game->last_time = 0;
	init_map(game->map, game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->map->width * 64),
			(game->map->height * 64), "So_Long");
	if (!game->win_ptr)
		error_msg(ERR_WIN);
	init_player(game, game->map);
}
