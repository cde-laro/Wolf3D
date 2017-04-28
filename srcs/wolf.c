/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 21:53:03 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/26 20:49:22 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void	hit(t_env *e, int i)
{
	int			hit;
	int			side;
	double		w;
	t_intp		a;
	t_intp		b;
	int			line_height;

	hit = 0;
	while (hit == 0)
	{
		if (e->p->side.x < e->p->side.y)
		{
			e->p->side.x += e->p->delta.x;
			e->p->map.x += e->p->step.x;
			side = 0;
		}
		else
		{
			e->p->side.y += e->p->delta.y;
			e->p->map.y += e->p->step.y;
			side = 1;
		}
		if (e->map->data[(int)e->p->map.y][(int)e->p->map.x] != 0)
			hit = 1;
	}
	if (side == 0)
		w = (e->p->map.x - e->p->pos.x + (1 - e->p->step.x / 2)) / e->p->dir.x;
	else
		w = (e->p->map.y - e->p->pos.y + (1 - e->p->step.y / 2)) / e->p->dir.y;
	line_height = (int)(WIN_Y/w);
	a.x = i;
	a.y = -line_height / 2 + WIN_Y / 2;
	b.x = i;
	b.y = line_height / 2 + WIN_Y / 2;
	printf("side =[%f][%f] dir = [%f][%f]\n", e->p->side.x, e->p->side.y, e->p->dir.x, e->p->dir.y);
	printf("a = [%d][%d] b = [%d][%d] w = %f\n", a.x, a.y, b.x, b.y, w);
	draw_line(e, a, b, 0x00FFFFFF);
}

void	draw_column(t_env *e, int i)
{
	int			rat;

	rat = 2 * i / (double)WIN_X - 1;
	e->p->dir.x = cos(RAD(e->p->angle))/2 + cos(RAD(e->p->angle - 0.25)) * rat;
	e->p->dir.y = sin(RAD(e->p->angle))/2 + sin(RAD(e->p->angle - 0.25)) * rat;
	e->p->delta.x = sqrt(1 + SQ(e->p->dir.y) / SQ(e->p->dir.x));
	e->p->delta.y = sqrt(1 + SQ(e->p->dir.x) / SQ(e->p->dir.y));
	e->p->step.x = (e->p->dir.x < 0 ? -1 : 1);
	e->p->step.y = (e->p->dir.y < 0 ? -1 : 1);
	e->p->map.x = (int)e->p->pos.x;
	e->p->map.y = (int)e->p->pos.y;
	if (e->p->dir.x < 0)
		e->p->side.x = (e->p->pos.x - e->p->map.x) * e->p->delta.x;
	else
		e->p->side.x = ((e->p->map.x + 1 - e->p->pos.x) * e->p->delta.x);
	if (e->p->dir.y < 0)
		e->p->side.y = (e->p->pos.y - e->p->map.y) * e->p->delta.y;
	else
		e->p->side.y = ((e->p->map.y + 1 - e->p->pos.y) * e->p->delta.y);
	hit(e, i);
}

void	draw_walls(t_env *e)
{
	int			i;

	i = 0;
	while (i < WIN_X)
	{
		draw_column(e, i);
		i++;
	}
}

void	draw(t_env *e)
{
	draw_walls(e);
	reset_img(e);
}

void	start(t_env *e)
{
	draw(e);
}
