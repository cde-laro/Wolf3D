/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 05:30:32 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/08 17:45:09 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_intp	int_to_intp(int x, int y)
{
	t_intp		a;

	a.x = x;
	a.y = y;
	return (a);
}

void	free_txt(t_env *e)
{
	mlx_destroy_image(e->mlx, e->txt->txt_1->img);
	mlx_destroy_image(e->mlx, e->txt->txt_2->img);
	mlx_destroy_image(e->mlx, e->txt->txt_3->img);
	mlx_destroy_image(e->mlx, e->txt->txt_4->img);
	mlx_destroy_image(e->mlx, e->txt->txt_5->img);
	mlx_destroy_image(e->mlx, e->txt->txt_6->img);
	mlx_destroy_image(e->mlx, e->txt->txt_7->img);
	mlx_destroy_image(e->mlx, e->txt->txt_8->img);
	mlx_destroy_image(e->mlx, e->txt->txt_9->img);
	free(e->txt->txt_1);
	free(e->txt->txt_2);
	free(e->txt->txt_3);
	free(e->txt->txt_4);
	free(e->txt->txt_5);
	free(e->txt->txt_6);
	free(e->txt->txt_7);
	free(e->txt->txt_8);
	free(e->txt->txt_9);
}

int		red_cross(int key, t_env *e)
{
	(void)key;
	(void)*e;
	exit(0);
	return (0);
}

void	reprint(t_env *e)
{
	mlx_paste_img(e, e->sky, int_to_intp(0, 0), 1);
	draw_frame(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->ptr_img, 0, 0);
	if (e->p->ammo_tick == 0)
	{
		mlx_put_image_to_window(e->mlx, e->win, e->gun->img->ptr_img, WIN_X / 2
			+ 100, WIN_Y - e->gun->a.y);
		mlx_put_image_to_window(e->mlx, e->win, e->cross->img->ptr_img,
			WIN_X / 2 +	e->cross->a.x / 2, WIN_Y / 2 + e->cross->a.y / 2 -
			e->p->crossy);
	}
	if (e->ui)
	{
		print_ammo(e);
		print_music_name(e);
		print_texture_name(e);
	}
}
