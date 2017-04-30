/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 04:33:36 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/30 03:06:47 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		game_loop(t_env *e)
{
	e->p->speed = (e->k->sprint ? DEF_SPEED * 2 : DEF_SPEED);
	e->p->speed = (e->k->sneak ? DEF_SPEED / 2 : e->p->speed);
	if (e->k->right)
		rotate(e, -1);
	if (e->k->left)
		rotate(e, 1);
	if (e->k->up)
		move(e, 1);
	if (e->k->down)
		move(e, -1);
	if (e->k->up || e->k->down || e->k->left || e->k->right)
	{
		ft_putchar('|');
		draw_frame(e);
		reset_img(e);
	}
	else
	{
		usleep(50000);
	}
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
		if (!e->k->sneak)
		{
			e->k->sneak = 100;
			draw_frame(e);
			reset_img(e);
		}
	}
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
		e->k->sneak = 0;
	draw_frame(e);
	reset_img(e);
	return (0);
}
