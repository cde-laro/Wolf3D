/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 04:27:31 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/01 22:48:54 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void		pix_put_img(t_env *e, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < WIN_Y && x < WIN_X)
	{
		e->img->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x) + 2] = r;
		e->img->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x) + 1] = g;
		e->img->bts[(y * e->img->size_line) + ((e->img->bpp / 8) * x)] = b;
	}
}

void		draw_line(t_env *e, t_intp a, t_intp b, int z)
{
	t_intp		d;
	t_intp		s;
	int			e1;
	int			e2;

	d.x = ABS(b.x - a.x);
	d.y = ABS(b.y - a.y);
	s.x = (a.x > b.x ? 1 : -1);
	s.y = (a.y > b.y ? 1 : -1);
	e1 = (d.x > d.y ? d.x : -d.y) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		pix_put_img(e, a.x, a.y, z);
		e2 = e1;
		if (e2 > -d.x)
		{
			e1 -= d.y;
			a.x += s.x;
		}
		if (e2 < d.y)
		{
			e1 += d.x;
			a.y -= s.y;
		}
	}
}
