/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 03:11:12 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/28 16:59:10 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		init_img(t_env *e)
{
	e->img->ptr_img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->img->bts = mlx_get_data_addr(e->img->ptr_img, &(e->img->bpp),
			&(e->img->size_line), &(e->img->end));
}

void		print_error_code(int code)
{
	ft_putstr("An error has occured: ");
	ft_putnbr(code);
	ft_putstr("Leaving Wolf 3D ...");
	exit(-1);
}

int			red_cross(int key, t_env *e)
{
	(void)key;
	(void)*e;
	exit(0);
	return (0);
}

void		init(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		print_error_code(1);
	if (!(e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Wolf 3D")))
		print_error_code(2);
	if (!(e->img = (t_img *)malloc(sizeof(t_img))))
		print_error_code(3);
	if (!(e->p = (t_player *)malloc(sizeof(t_player))))
		print_error_code(4);
	init_img(e);
	mlx_hook(e->win, 17, (1L << 17), red_cross, e);
	mlx_hook(e->win, 2, 3, key_funct, e);
}
