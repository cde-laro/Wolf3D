/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 05:30:32 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/05 07:43:39 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_intp		int_to_intp(int x, int y)
{
	t_intp		a;

	a.x = x;
	a.y = y;
	return(a);
}

int		set_color(int side, int stepx, int stepy)
{
	if (side == 0)
		return(stepx == -1 ? RED : GREEN);
	else
		return(stepy == -1 ? BLUE : YELLOW);
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
	mlx_put_image_to_window(e->mlx, e->win, e->gun->img->ptr_img, WIN_X / 2 + 100,
		WIN_Y - e->gun->a.y);
	mlx_put_image_to_window(e->mlx, e->win, e->cross->img->ptr_img, WIN_X / 2 +
		e->cross->a.x / 2, WIN_Y / 2 + e->cross->a.y / 2 - e->p->crossy);
}

void	print_error_code(int code)
{
	system("afplay resources/sounds/erro.mp3 &");
	ft_putstr("An error has occured: ");
	ft_putnbr(code);
	ft_putstr("   Leaving Wolf 3D ...");
	exit(-1);
}

void	print_map(t_env *e, int **data, int maxx, int maxy)
{
	/*int		x;
	int		y;

	y = 0;
	while (y < maxy)
	{
		x = 0;
		while (x < maxx)
		{
			if (x == (int)e->p->pos.x && y == (int)e->p->pos.y)
				ft_putchar('A');
			else
				(data[y][x] ? ft_putchar(data[y][x] + '0') : ft_putchar(' '));
			x++;
		}
		y++;
		ft_putchar('\n');*/
		(void)e;
		(void)data;
		(void)maxx;
		(void)maxy;
	//}
}
