/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:45:15 by bwach             #+#    #+#             */
/*   Updated: 2024/02/16 00:09:57 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//get the time at the moment
long long	time_now(void)
{
	long long		mill_sec;
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	mill_sec = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (mill_sec);
}

//tagert fps at 60 fps
void	frame_per_second(t_data *game)
{
	long long	actual_time;

	actual_time = time_now();
	if (actual_time > game->last_time)
	{
		game->fps = 60 / (actual_time - game->last_time);
		game->last_time = actual_time;
	}
}
