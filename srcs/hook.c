/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 04:33:36 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/30 01:42:40 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		game_loop(t_env *e)
{
	int static		frames = 0;
	if (e->k->right)
		rotate(e, -1);
	if (e->k->left)
		rotate(e, 1);
	if (e->k->up)
		move(e, 1);
	if (e->k->down)
		move(e, -1);
	e->p->speed = (e->k->sprint ? 0.6 : 0.3);
	printf("Frame : %d\n", frames);
	printf("pos :   [%f][%f]\n", e->p->pos.x, e->p->pos.y);
	printf("dir :   [%f][%f]\n", e->p->dir.x, e->p->dir.y);
	printf("plane : [%f][%f]\n", e->p->plane.x, e->p->plane.y);
	ft_putchar('\n');
	usleep(1000000 / MAX_FPS);
	if (e->k->up == 1 || e->k->down == 1 || e->k->left == 1 || e->k->right == 1)
	{
		frames++;
		draw_frame(e);
		reset_img(e);
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
	else if (k == KEY_CTRL_LEFT)
		e->k->sneak = 1;
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
	else if (k == KEY_CTRL_LEFT)
		e->k->sneak = 0;
	return (0);
}
