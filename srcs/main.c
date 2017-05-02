/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 02:09:26 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/02 06:25:41 by cde-laro         ###   ########.fr       */
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
	ft_putendl("Extracted");
	e = init(av[1]);
	start(e);
	print_instruction();
	print_map(e, e->map->data, e->map->maxx, e->map->maxy);
	ft_putendl("start loop");
	mlx_loop(e->mlx);
	return (0);
}
