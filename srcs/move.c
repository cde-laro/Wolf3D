/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 05:05:54 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/30 07:35:48 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	rotate(t_env *e, int dir)
{
	double		olddir;
	double		oldplane;

	olddir = e->p->dir.x;
	oldplane = e->p->plane.x;
	e->p->dir.x = e->p->dir.x * cos(e->p->r_s * dir) - e->p->dir.y *
		sin(e->p->r_s * dir);
	e->p->dir.y = olddir * sin(e->p->r_s * dir) + e->p->dir.y *
		cos(e->p->r_s * dir);
	e->p->plane.x = e->p->plane.x * cos(e->p->r_s * dir) - e->p->plane.y *
		sin(e->p->r_s * dir);
	e->p->plane.y = oldplane * sin(e->p->r_s * dir) + e->p->plane.y *
		cos(e->p->r_s * dir);
	e->k->dec.x -= 30 * dir;
}

void	move(t_env *e, int dir)
{
	if (!(e->map->data[(int)(e->p->pos.y + (dir * e->p->dir.y * e->p->speed))]
			[(int)e->p->pos.x]))
		e->p->pos.y += (e->p->dir.y * e->p->speed) * dir;
	if (!(e->map->data[(int)e->p->pos.y]
			[(int)(e->p->pos.x + (dir * e->p->dir.x * e->p->speed))]))
		e->p->pos.x += (e->p->dir.x * e->p->speed) * dir;
}
