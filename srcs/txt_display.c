/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 01:39:40 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/02 02:58:57 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
	ft_putendl("|| Use SPACE to jump (yeah, it's useless, don't judge me)  ||");
	ft_putendl("|| Press R if you want want to stop the sky rotation       ||");
	ft_putendl("|| Press ESC to leave the game                             ||");
	ft_putendl("=============================================================");
}
