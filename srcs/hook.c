/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 04:33:36 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/28 19:23:17 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		key_funct(int k, t_env *e)
{
	if (k == KEY_RIGHT || k == KEY_D)
		rotate(e, -1);
	else if (k == KEY_LEFT || k == KEY_A)
		rotate(e, 1);
	else if (k == KEY_UP || k == KEY_W)
		move(e, 1);
	else if (k == KEY_DOWN || k == KEY_S)
		move(e, -1);
	else if (k == KEY_Q)
		move(e, 3);
	else if (k == KEY_E)
		move(e, 4);
	else if (k == KEY_SHIFT_LEFT)
		e->p->speed = (e->p->speed == 0.3 ? 0.6 : 0.3);
	else if (k == KEY_ESCAPE)
		exit(0);
	printf("pos :   [%f][%f]\n", e->p->pos.x, e->p->pos.y);
	printf("dir :   [%f][%f]\n", e->p->dir.x, e->p->dir.y);
	printf("plane : [%f][%f]\n", e->p->plane.x, e->p->plane.y);
	ft_putchar('\n');
	draw_frame(e);
	reset_img(e);
	return (0);
}
