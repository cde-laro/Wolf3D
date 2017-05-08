/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 12:37:42 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/08 17:00:08 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	switch_song(t_env *e)
{
	e->music = (e->music == 9 ? 0 : e->music + 1);
	system("killall afplay");
	if (e->music == 1)
		system("afplay resources/sounds/music1.mp3 &");
	else if (e->music == 2)
		system("afplay resources/sounds/music2.mp3 &");
	else if (e->music == 3)
		system("afplay resources/sounds/music3.mp3 &");
	else if (e->music == 4)
		system("afplay resources/sounds/music4.mp3 &");
	else if (e->music == 5)
		system("afplay resources/sounds/music5.mp3 &");
	else if (e->music == 6)
		system("afplay resources/sounds/music6.mp3 &");
	else if (e->music == 7)
		system("afplay resources/sounds/music7.mp3 &");
	else if (e->music == 8)
		system("afplay resources/sounds/music8.mp3 &");
}

void	print_music_name(t_env *e)
{
	if (e->music == 0)
		return ;
	else if (e->music == 1)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 10, WHITE,
			"HOTLINE MIAMI - Perturbator");
	else if (e->music == 2)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 10, WHITE,
			"UNDERTALE - Megalovania");
	else if (e->music == 3)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 10, WHITE, "OVERWATCH");
	else if (e->music == 4)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 10, WHITE,
			"PORTAL - Want you gone");
	else if (e->music == 5)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 10, WHITE,
			"SHOOTING STAR");
	else if (e->music == 6)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 10, WHITE,
			"WOLFENSTEIN THE NEW ORDER - Boom Boom");
	else if (e->music == 7)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 10, WHITE,
			"Crypt of the Necrodancer - Disco Descent");
	else if (e->music == 8)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 10, WHITE,
			"EPIC AH GUY - Denis Brogniart");
}

void	print_texture_name(t_env *e)
{
	if (e->pack == 0)
		return ;
	else if (e->pack == 1)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 35, WHITE,
			"Default");
	else if (e->pack == 2)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 35, WHITE,
			"Portal");
	else if (e->pack == 3)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 35, WHITE,
			"WOLFENSTEIN");
	else if (e->pack == 4)
		mlx_string_put(e->mlx, e->win, WIN_X - 550, 35, WHITE,
			"Don't know why i made this");
}
