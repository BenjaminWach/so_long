/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:41:10 by bwach             #+#    #+#             */
/*   Updated: 2024/02/15 00:21:38 by bwach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	fetch_action_keys(int keycode)
{
	printf("on donne le code\n");
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

void	unset_action(t_data *game, int keycode)
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