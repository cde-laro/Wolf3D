/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 05:30:32 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/30 06:59:04 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"



int			red_cross(int key, t_env *e)
{
	(void)key;
	(void)*e;
	exit(0);
	return (0);
}



void 	reprint(t_env *e)
{
	mlx_clr_img(e);
	draw_frame(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr_img, 0, 0);
}
