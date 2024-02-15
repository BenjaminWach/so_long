/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:59:06 by bwach             #+#    #+#             */
/*   Updated: 2024/02/15 11:39:35 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	xpm_file(int i, char *path, int category, t_data *game)
{
	int	b;

	b = 64;
	if (category == 1)
		game->env[i - 1] = mlx_xpm_file_to_image(game->mlx_ptr, path, &b, &b);
	else if (category == 2)
		game->door[i - 1] = mlx_xpm_file_to_image(game->mlx_ptr, path, &b, &b);
	else if (category == 3)
		game->obj[i - 1] = mlx_xpm_file_to_image(game->mlx_ptr, path, &b, &b);
	else if (category == 4)
		game->p[i - 1] = mlx_xpm_file_to_image(game->mlx_ptr, path, &b, &b);
	else if (category == 5)
		game->p_mv[i - 1] = mlx_xpm_file_to_image(game->mlx_ptr, path, &b, &b);
}

static char	*path_to(char *category_sprite, int nb)
{
	char	*num;
	char	*str;
	char	*str1;

	num = ft_itoa(nb);
	str = ft_strjoin("xpm/", category_sprite);
	str1 = ft_strjoin(str, "/");
	free(str);
	str = ft_strjoin(str1, category_sprite);
	free(str1);
	str1 = ft_strjoin(str, "_");
	free(str);
	str = ft_strjoin(str1, num);
	free(str1);
	str1 = ft_strjoin(str, ".xpm");
	free(str);
	free(num);
	return (str1);
}

static void	fetch_sprite(char *name, int nb_sprites, int category, t_data *game)
{
	char	*path_to_sprite;
	int		i;
	int		fd;

	i = 0;
	while (i++ < nb_sprites)
	{
		path_to_sprite = path_to(name, i - 1);
		fd = open(path_to_sprite, O_RDONLY);
		if (fd < 0)
			error_msg(ERR_SPRITE_FILE);
		close(fd);
		xpm_file(i, path_to_sprite, category, game);
		free(path_to_sprite);
	}
}

void	init_sprites(t_data *game)
{
	fetch_sprite("env", 8, 1, game);
	fetch_sprite("exit", 2, 2, game);
	fetch_sprite("obj", 2, 3, game);
	fetch_sprite("idle", 12, 4, game);
	fetch_sprite("mvt", 16, 5, game);
}
