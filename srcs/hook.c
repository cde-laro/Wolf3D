/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 04:33:36 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/02 06:37:04 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		game_loop(t_env *e)
{
	ft_putendl("start loop");
	print_map(e, e->map->data, e->map->maxx, e->map->maxy);
	static int	ticks = 0;

	e->p->speed = (e->k->sprint ? DEF_SPEED * 2 : DEF_SPEED);
	e->p->speed = (e->k->sneak ? DEF_SPEED / 2 : e->p->speed);
	if (e->k->right)
		rotate(e, -1);
	if (e->k->left)
		rotate(e, 1);
	if (e->k->up && e->k->jump_state == 0)
		move(e, 1);
	if (e->k->down && e->k->jump_state == 0)
		move(e, -1);
	jump_dec(e);
	ticks++;
	if (ticks % 2 == 0 && e->k->rotation)
		e->k->dec.x--;
	reprint(e);
	return (0);
}

int		key_press(int k, t_env *e)
{
	if (k == KEY_RIGHT || k == KEY_D)
		e->k->right = 1;
	else if (k == KEY_LEFT || k == KEY_A)
		e->k->left = 1;
	else if (k == KEY_UP || k == KEY_W)
		e->k->up = 1;
	else if (k == KEY_DOWN || k == KEY_S)
		e->k->down = 1;
	else if (k == KEY_SHIFT_LEFT)
		e->k->sprint = 1;
	else if (k == KEY_Z)
	{
		e->k->sneak = 100;
		reprint(e);
	}
	else if (k == KEY_SPACEBAR)
		e->k->jump_state = (!e->k->jump_state ? 1 : e->k->jump_state);
	else if (k == KEY_R)
		e->k->rotation = (e->k->rotation ? 0 : 1);
	else if (k == KEY_ESCAPE)
		exit(0);
	return (0);
}

int		key_release(int k, t_env *e)
{
	if (k == KEY_RIGHT || k == KEY_D)
		e->k->right = 0;
	else if (k == KEY_LEFT || k == KEY_A)
		e->k->left = 0;
	else if (k == KEY_UP || k == KEY_W)
		e->k->up = 0;
	else if (k == KEY_DOWN || k == KEY_S)
		e->k->down = 0;
	else if (k == KEY_SHIFT_LEFT)
		e->k->sprint = 0;
	else if (k == KEY_Z)
	{
		e->k->sneak = 0;
		reprint(e);
	}
	return (0);
}
