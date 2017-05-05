/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 03:07:13 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/05 02:51:57 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map	*create_empty_map(int x, int y)
{
	t_map	*map;
	int		i;
	int		j;

	j = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->data = (int **)malloc(sizeof(int *) * y);
	map->maxx = x;
	map->maxy = y;
	while (j < y)
	{
		map->data[j] = (int *)malloc(sizeof(int) * x);
		i = 0;
		while (i < x)
		{
			if (i == 0 || j == 0 || i == x - 1 || j == y - 1 )
				map->data[j][i] = 1;
			else
				map->data[j][i] = 0;
			ft_putnbr(map->data[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	return (map);
}
