/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:10:22 by bwach             #+#    #+#             */
/*   Updated: 2024/02/24 01:12:07 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**copying_map(t_map *map, char **cpy)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_memcpy(cpy[i], map->map[i], map->width * sizeof(char));
		i++;
	}
	return (cpy);
}
