/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 02:09:26 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/27 00:18:29 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	t_env		e;

	if (ac != 2)
	{
		ft_putendl("usage: ./wolf <map name>");
		return (-1);
	}
	init(&e);
	(void)av;
	ft_putendl("Extraction ...");
	if (!(e.map = parse(av[1])))
		return (-1);
	ft_putendl("Extracted");
	start(&e);
	mlx_loop(e.mlx);
	return (0);
}
