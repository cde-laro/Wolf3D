/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:02:12 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/08 17:35:26 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	reload(t_env *e)
{
	if (e->p->ammo_tick == 0)
	{
		system("afplay resources/sounds/reload.mp3 &");
		e->p->ammo_tick = 40;
	}
}

void	sneak(t_env *e)
{
	e->p->crossy = 100;
	e->k->sneak = 100;
	reprint(e);
}
