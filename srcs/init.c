/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 03:11:12 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/02 07:00:52 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void	init_img(t_env *e)
{
	if (!(e->img->ptr_img = mlx_new_image(e->mlx, WIN_X, WIN_Y)))
		print_error_code(10);
	if (!(e->img->bts = mlx_get_data_addr(e->img->ptr_img, &(e->img->bpp),
			&(e->img->size_line), &(e->img->end))))
		print_error_code(11);
}

void	init_keys_value(t_env *e)
{
	e->k->up = 0;
	e->k->down = 0;
	e->k->left = 0;
	e->k->right = 0;
	e->k->sprint = 0;
	e->k->sneak = 0;
	e->k->jump = 50;
	e->k->jump_state = -2;
	e->k->dec.x = 0;
	e->k->dec.y = 50;
	e->k->rotation = 1;
}

void	init_skybox(t_env *e)
{
	if (!(e->s = (t_sky *)malloc(sizeof(t_sky))))
		print_error_code(6);
	if (!(e->s->img = (t_img *)malloc(sizeof(t_img))))
		print_error_code(7);
	if (!(e->s->img->ptr_img = mlx_xpm_file_to_image(e->mlx,
		"resources/sky.xpm", &e->s->a.x, &e->s->a.y)))
		print_error_code(8);
	if (!(e->s->img->bts = mlx_get_data_addr(e->s->img->ptr_img,
		&(e->s->img->bpp), &(e->s->img->size_line), &(e->s->img->end))))
		print_error_code(9);
}

t_env	*init(char *name)
{
	t_env	*e;
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		print_error_code(0);
	if (!(e->mlx = mlx_init()))
		print_error_code(1);
	if (!(e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Wolf 3D")))
		print_error_code(2);
	if (!(e->img = (t_img *)malloc(sizeof(t_img))))
		print_error_code(3);
	if (!(e->p = (t_player *)malloc(sizeof(t_player))))
		print_error_code(4);
	if (!(e->k = (t_keys *)malloc(sizeof(t_keys))))
		print_error_code(5);
	if (!(e->map = parse(name)))
		exit (-1);
	init_img(e);
	init_keys_value(e);
	init_skybox(e);
	mlx_hook(e->win, 17, (1L << 17), red_cross, e);
	mlx_hook(e->win, 2, (1L << 0), key_press, e);
	mlx_hook(e->win, 3, (1L << 1), key_release, e);
	mlx_loop_hook(e->mlx, game_loop, e);
	return (e);
}
