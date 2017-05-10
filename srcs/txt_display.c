/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 01:39:40 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/10 17:24:58 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	print_ammo(t_env *e)
{
	char	*ammo;

	if (e->p->ammo_tick != 0)
		mlx_string_put(e->mlx, e->win, 10, WIN_Y - 50, RED, "RELOADING");
	else
	{
		ammo = ft_itoa(e->p->ammo);
		mlx_string_put(e->mlx, e->win, 10, WIN_Y - 50, (e->p->ammo == 0 ? RED :
			WHITE), ammo);
		free(ammo);
	}
}

void	print_instruction(void)
{
	ft_putendl("===================== Wolf 3D - cde-laro ====================");
	ft_putendl("||                        Commands :                       ||");
	ft_putendl("||---------------------------------------------------------||");
	ft_putendl("|| Use W or the up arrow to walk                           ||");
	ft_putendl("|| Use S or the down arrow to walk forward                 ||");
	ft_putendl("|| Use A or the left arrow to look left                    ||");
	ft_putendl("|| Use D or the right arrow to look right                  ||");
	ft_putendl("|| If you use an AZERTY keyboard i'm really sad for you    ||");
	ft_putendl("|| Use LEFT SHIFT to sprint                                ||");
	ft_putendl("|| Use Z to sneak                                          ||");
	ft_putendl("|| Use T to switch the wall textures                       ||");
	ft_putendl("|| Use M to choose or turn of the music                    ||");
	ft_putendl("|| Use F to choose the color on the floor                  ||");
	ft_putendl("|| Use SPACE to jump (yeah, it's useless, don't judge me)  ||");
	ft_putendl("|| Press S if you want want to stop the sky rotation       ||");
	ft_putendl("|| Left Click anywhere on the window to shoot              ||");
	ft_putendl("|| Press R to reload when you are out of ammo              ||");
	ft_putendl("|| Press Tab to toggle the display of text on screen       ||");
	ft_putendl("|| Press ESC to leave the game                             ||");
	ft_putendl("=============================================================");
}

void	print_error_code(int code)
{
	system("afplay resources/sounds/erro.mp3 &");
	ft_putstr("An error has occured: ");
	ft_putnbr(code);
	ft_putstr("   Leaving Wolf 3D ...");
	exit(-1);
}
