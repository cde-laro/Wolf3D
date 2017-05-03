/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 05:30:32 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/03 03:04:22 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char		*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*dest;

	n = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[n])
	{
		dest[n] = s1[n];
		n++;
	}
	i = 0;
	while (s2[i])
	{
		dest[n] = s2[i];
		n++;
		i++;
	}
	dest[n] = '\0';
	free(s1);
	return (dest);
}

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
}

void	print_error_code(int code)
{
	ft_putstr("An error has occured: ");
	ft_putnbr(code);
	ft_putstr("   Leaving Wolf 3D ...");
	exit(-1);
}

void	print_map(t_env *e, int **data, int maxx, int maxy)
{
	int		x;
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
		ft_putchar('\n');
	}
}
