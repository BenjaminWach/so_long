/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:41:10 by bwach             #+#    #+#             */
/*   Updated: 2024/02/20 01:10:30 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_RST 15
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define ARROW_DW 125*/
static int	fetch_action_keys(int keycode)
{
	if (keycode == KEY_LEFT || keycode == ARROW_LEFT)
		return (1);
	else if (keycode == KEY_RIGHT || keycode == ARROW_RIGHT)
		return (2);
	else if (keycode == KEY_DOWN || keycode == ARROW_DW)
		return (3);
	else if (keycode == KEY_UP || keycode == ARROW_UP)
		return (4);
	else if (keycode == KEY_ACTION)
		return (5);
	return (0);
}

void	unset_action(int keycode, t_data *game)
{
	printf("keycode recu on release: %d\n", keycode);
	t_play	*p;

	p = game->player;
	if (p->ac[0] == fetch_action_keys(keycode))
		p->ac[0] = 0;
	if (p->ac[1] == fetch_action_keys(keycode))
		p->ac[1] = 0;
	if (p->ac[0] == 0 || p->ac[1] != 0)
	{
		p->ac[0] = p->ac[1];
		p->ac[1] = 0;
	}
	if (p->ac[2] == fetch_action_keys(keycode))
		p->ac[2] = 0;
	p->moving = false;
}

void	set_action(int keycode, t_data *game)
{
	printf("keycode recu: %d\n", keycode);
	t_play	*p;

	p = game->player;
	if (fetch_action_keys(keycode) != 5)
	{
		if (p->ac[0] == 0 || p->ac[0] == fetch_action_keys(keycode))
			p->ac[0] = fetch_action_keys(keycode);
		else if (p->ac[1] == 0 || p->ac[1] == fetch_action_keys(keycode))
			p->ac[1] = fetch_action_keys(keycode);
	}
	else
		p->ac[2] = fetch_action_keys(keycode);
	if (p->ac[0] == 1 || p->ac[1] == 1)
		p->direction = 0;
	if (p->ac[0] == 2 || p->ac[1] == 2)
		p->direction = 1;
	p->moving = true;
}
