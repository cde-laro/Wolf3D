/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 03:11:12 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/10 17:41:25 by cde-laro         ###   ########.fr       */
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
	e->music = 0;
	e->ui = 1;
	e->pack = 1;
}

void	start(t_env *e)
{
	if (e->map->data[e->map->maxy / 2][e->map->maxx / 2])
	{
		ft_putendl("The center must be empty");
		exit(-1);
	}
	e->p->pos.x = e->map->maxx / 2 + 0.5;
	e->p->pos.y = e->map->maxy / 2 + 0.5;
	e->p->dir.x = -0.5;
	e->p->dir.y = 0;
	e->p->plane.x = 0;
	e->p->plane.y = 0.66;
	e->p->speed = DEF_SPEED;
	e->p->r_s = 0.1;
	e->p->crossy = 40;
	e->p->ammo = DEF_AMMO;
	e->p->ammo_tick = 0;
	e->floor_color = GREY;
}

t_map	*init_map(char *param)
{
	int		fd;

	if (ft_strequ(param, "generator") == 1)
		return (create_empty_map(40, 40));
	else
	{
		if ((fd = open(param, O_RDONLY)) == -1)
			print_error_code(42);
		return (map_extract(fd, param));
	}
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
	e->map = init_map(name);
	init_img(e);
	init_keys_value(e);
	init_all_xpm(e);
	mlx_hook(e->win, 17, (1L << 17), red_cross, e);
	mlx_hook(e->win, 2, (1L << 0), key_press, e);
	mlx_hook(e->win, 3, (1L << 1), key_release, e);
	mlx_mouse_hook(e->win, mouse_funct, e);
	mlx_loop_hook(e->mlx, game_loop, e);
	return (e);
}
