/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 23:03:35 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/03 02:46:03 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_xpm	*init_xpm(t_env *e, char *path)
{
	t_xpm	*target;

	if (!(target = (t_xpm *)malloc(sizeof(t_xpm))))
		print_error_code(6);
	if (!(target->img = (t_img *)malloc(sizeof(t_img))))
		print_error_code(7);
	if (!(target->img->ptr_img = mlx_xpm_file_to_image(e->mlx,
		path, &target->a.x, &target->a.y)))
		print_error_code(8);
	if (!(target->img->bts = mlx_get_data_addr(target->img->ptr_img,
		&(target->img->bpp), &(target->img->size_line), &(target->img->end))))
		print_error_code(9);
	return (target);
}

void	mlx_paste_img(t_env *e, t_xpm *xpm, t_intp coord, int sky)
{
	t_intp	dec;
	t_intp  tmp;


	dec.x =  (!sky ? 0 : e->k->dec.x % xpm->a.x);
	dec.y =  (!sky ? 0 : e->k->dec.y % xpm->a.y);
	tmp.x = coord.x;
	while (tmp.x < WIN_X)
	{
	 	tmp.y = coord.y;
		while (tmp.y < WIN_Y)
		{
			mlx_img_copy(e, tmp, dec, xpm);
			tmp.y++;
		}
		tmp.x++;
	}
}

void	mlx_img_copy(t_env *e, t_intp coord, t_intp dec, t_xpm *src)
{
	if (coord.y >= 0 && coord.x >= 0 && coord.y < WIN_Y && coord.x < WIN_X)
	{
		e->img->bts[((coord.y * e->img->size_line) + (e->img->bpp / 8) *
			coord.x) + 2] =	src->img->bts[((coord.y + dec.y) *
			src->img->size_line) + ((src->img->bpp / 8) *
			(coord.x + dec.x)) + 2];
		e->img->bts[((coord.y * e->img->size_line) + (e->img->bpp / 8) *
			coord.x) + 1] = src->img->bts[((coord.y + dec.y) *
			src->img->size_line) + ((src->img->bpp / 8) *
			(coord.x + dec.x)) + 1];
		e->img->bts[((coord.y * e->img->size_line) + (e->img->bpp / 8) *
		 	coord.x)] =	src->img->bts[((coord.y + dec.y) *
			src->img->size_line) + ((src->img->bpp / 8) * (coord.x + dec.x))];
	}
}
