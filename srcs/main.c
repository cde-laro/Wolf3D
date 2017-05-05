/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 02:09:26 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/05 02:36:10 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	t_env		*e;

	if (ac != 2)
	{
		ft_putendl("usage: ./wolf <map name>");
		return (-1);
	}
	e = init(av[1]);
	e->generator = ft_strequ(av[0], "generator");
	start(e);
	print_instruction(e->generator);
	print_map(e, e->map->data, e->map->maxx, e->map->maxy);
	mlx_loop(e->mlx);
	return (0);
}
