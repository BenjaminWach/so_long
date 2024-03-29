/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:27:39 by bwach             #+#    #+#             */
/*   Updated: 2024/02/27 21:17:40 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	environment(t_data *game, t_map *m)
{
	size_t	len;

	len = 0;
	while (m->map[len / m->width])
	{
		if (m->map[len / m->width][len % m->width] == '0' ||
			m->map[len / m->width][len % m->width] == 'P' ||
			m->map[len / m->width][len % m->width] == 'C' ||
			m->map[len / m->width][len % m->width] == 'M')
			draw_pic((len % m->width) * 64, (len / m->width) * 64,
				game->env[9], game);
		len++;
	}
}
