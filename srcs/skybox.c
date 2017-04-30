/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 06:57:06 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/30 07:25:10 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	mlx_img_copy(t_env *e, int x, int y, t_intp dec)
{
	if (y >= 0 && x >= 0 && y < WIN_Y && x < WIN_X)
	{
		e->img->bts[((y *e->img->size_line) + (e->img->bpp / 8) * x) + 2] =
			e->s->img->bts[((y + dec.y) * e->s->img->size_line) +
			((e->s->img->bpp / 8) * (x + dec.x)) + 2];
		e->img->bts[((y *e->img->size_line) + (e->img->bpp / 8) * x) + 1] =
			e->s->img->bts[((y + dec.y) * e->s->img->size_line) +
			((e->s->img->bpp / 8) * (x + dec.x)) + 1];
		e->img->bts[((y *e->img->size_line) + (e->img->bpp / 8) * x)] =
			e->s->img->bts[((y + dec.y) * e->s->img->size_line) +
			((e->s->img->bpp / 8) * (x + dec.x))];
	}
}

void	mlx_clr_img(t_env *e)
{
	int		x;
	int		y;
	t_intp	dec;

	dec.x = e->k->dec.x % e->s->a.x;
	dec.y = e->k->dec.y; //- (ptr->key->crouch * ptr->crouch);
	x = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < 0.6 * WIN_Y)
		{
			mlx_img_copy(e, x, y, dec);
			y++;
		}
		x++;
	}
}
