/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 03:07:13 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/03 03:51:25 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	create_empty_map(t_env *e, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	e->map = (t_map *)malloc(sizeof(t_map));
	e->map->data = (int **)malloc(sizeof(int *) * y);
	e->map->maxx = x;
	e->map->maxy = y;
	while (j < y)
	{
		e->map->data[j] = (int *)malloc(sizeof(int) * x);
		i = 0;
		while (i < x)
		{
			if (i == 0 || j == 0 || i == x - 1 || j == y - 1 )
				e->map->data[j][i] = 1;
			else
				e->map->data[j][i] = 0;
			ft_putnbr(e->map->data[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
