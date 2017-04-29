/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 20:50:04 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/29 22:54:10 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void	calc_line_len(t_env *e, int x, int side)
{
	e->p->line_h = (int)(WIN_Y / e->p->pwd * 1.5);
	e->p->draw_start.x = x;
	e->p->draw_start.y = -e->p->line_h / 2 + WIN_Y / 2;
	e->p->draw_start.y = (e->p->draw_start.y < 0 ? 0 : e->p->draw_start.y);
	e->p->draw_end.x = x;
	e->p->draw_end.y = e->p->line_h / 2 + WIN_Y / 2;
	e->p->draw_end.y = (e->p->draw_end.y > WIN_Y ? WIN_Y : e->p->draw_end.y);
	draw_line(e, e->p->draw_start, e->p->draw_end, (side == 0 ? 0x000000FF : 0x00FF0000));
}

void	find_wall(t_env *e, int hit, int x)
{
	int		side;

	while (hit == 0)
	{
		if (e->p->sided.x < e->p->sided.y)
		{
			e->p->sided.x += e->p->deltad.x;
			e->p->map.x += e->p->step.x;
			side = 0;
		}
		else
		{
			e->p->sided.y += e->p->deltad.y;
			e->p->map.y += e->p->step.y;
			side = 1;
		}

		hit = (e->map->data[(int)e->p->map.y][(int)e->p->map.x] > 0 ? 1 : hit);
	}
	if (side == 0)
		e->p->pwd = (e->p->map.x - e->p->rayp.x + (1 - e->p->step.x) / 2) / e->p->rayd.x;
	else
		e->p->pwd = (e->p->map.y - e->p->rayp.y + (1 - e->p->step.y) / 2) / e->p->rayd.y;
	calc_line_len(e, x, side);
}

void	draw_column(t_env *e, int x)
{

	e->p->deltad.x = sqrt(1 + SQ(e->p->rayd.y) / SQ(e->p->rayd.x));
	e->p->deltad.y = sqrt(1 + SQ(e->p->rayd.x) / SQ(e->p->rayd.y));
	e->p->step.x = (e->p->rayd.x < 0 ? -1 : 1);
	e->p->step.y = (e->p->rayd.y < 0 ? -1 : 1);
	if (e->p->rayd.x < 0)
		e->p->sided.x = (e->p->rayp.x - e->p->map.x) * e->p->deltad.x;
	else
		e->p->sided.x = (e->p->map.x + 1 - e->p->rayp.x) * e->p->deltad.x;
	if (e->p->rayd.y < 0)
		e->p->sided.y = (e->p->rayp.y - e->p->map.y) * e->p->deltad.y;
	else
		e->p->sided.y = (e->p->map.y + 1 - e->p->rayp.y) * e->p->deltad.y;
	find_wall(e, 0, x);
}

void	draw_frame(t_env *e)
{
	int		x;

	x = -1;
	while (++x < WIN_X)
	{
		e->p->rat = 2 * (double)(x) / (double)(WIN_X) - 1;
		e->p->rayp.x = e->p->pos.x;
		e->p->rayp.y = e->p->pos.y;
		e->p->rayd.x = e->p->dir.x + e->p->plane.x * e->p->rat;
		e->p->rayd.y = e->p->dir.y + e->p->plane.y * e->p->rat;
		e->p->map.x = (int)e->p->rayp.x;
		e->p->map.y = (int)e->p->rayp.y;
		draw_column(e, x);
	}
}

void	start(t_env *e)
{
	e->p = (t_player *)malloc(sizeof(t_player));
	if (e->map->data[2][2])
	{
		ft_putendl("The case [2][2] must be empty");
		exit (-1);
	}
	e->p->pos.x = 2;
	e->p->pos.y = 2;
	e->p->dir.x = -0.5;
	e->p->dir.y = 0;
	e->p->plane.x = 0;
	e->p->plane.y = 0.66;
	e->p->speed = 0.3;
	e->p->r_s = 0.2;
	draw_frame(e);
	reset_img(e);
}
