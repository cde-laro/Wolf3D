/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 03:28:30 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/05 06:17:12 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	load_txt_4(t_env *e)
{
	if (e->pack == 9)
	{
		e->txt->txt_1 = init_xpm(e, "resources/textures/txt9/t1.xpm");
		e->txt->txt_2 = init_xpm(e, "resources/textures/txt9/t2.xpm");
		e->txt->txt_3 = init_xpm(e, "resources/textures/txt9/t3.xpm");
		e->txt->txt_4 = init_xpm(e, "resources/textures/txt9/t4.xpm");
		e->txt->txt_5 = init_xpm(e, "resources/textures/txt9/t5.xpm");
		e->txt->txt_6 = init_xpm(e, "resources/textures/txt9/t6.xpm");
		e->txt->txt_7 = init_xpm(e, "resources/textures/txt9/t7.xpm");
		e->txt->txt_8 = init_xpm(e, "resources/textures/txt9/t8.xpm");
		e->txt->txt_9 = init_xpm(e, "resources/textures/txt9/t9.xpm");
	}
	else if (e->pack == 10)
	{
		e->txt->txt_1 = init_xpm(e, "resources/textures/txt10/t1.xpm");
		e->txt->txt_2 = init_xpm(e, "resources/textures/txt10/t2.xpm");
		e->txt->txt_3 = init_xpm(e, "resources/textures/txt10/t3.xpm");
		e->txt->txt_4 = init_xpm(e, "resources/textures/txt10/t4.xpm");
		e->txt->txt_5 = init_xpm(e, "resources/textures/txt10/t5.xpm");
		e->txt->txt_6 = init_xpm(e, "resources/textures/txt10/t6.xpm");
		e->txt->txt_7 = init_xpm(e, "resources/textures/txt10/t7.xpm");
		e->txt->txt_8 = init_xpm(e, "resources/textures/txt10/t8.xpm");
		e->txt->txt_9 = init_xpm(e, "resources/textures/txt10/t9.xpm");
	}
}

void	load_txt_3(t_env *e)
{
	if (e->pack == 7)
	{
		e->txt->txt_1 = init_xpm(e, "resources/textures/txt7/t1.xpm");
		e->txt->txt_2 = init_xpm(e, "resources/textures/txt7/t2.xpm");
		e->txt->txt_3 = init_xpm(e, "resources/textures/txt7/t3.xpm");
		e->txt->txt_4 = init_xpm(e, "resources/textures/txt7/t4.xpm");
		e->txt->txt_5 = init_xpm(e, "resources/textures/txt7/t5.xpm");
		e->txt->txt_6 = init_xpm(e, "resources/textures/txt7/t6.xpm");
		e->txt->txt_7 = init_xpm(e, "resources/textures/txt7/t7.xpm");
		e->txt->txt_8 = init_xpm(e, "resources/textures/txt7/t8.xpm");
		e->txt->txt_9 = init_xpm(e, "resources/textures/txt7/t9.xpm");
	}
	else if (e->pack == 8)
	{
		e->txt->txt_1 = init_xpm(e, "resources/textures/txt8/t1.xpm");
		e->txt->txt_2 = init_xpm(e, "resources/textures/txt8/t2.xpm");
		e->txt->txt_3 = init_xpm(e, "resources/textures/txt8/t3.xpm");
		e->txt->txt_4 = init_xpm(e, "resources/textures/txt8/t4.xpm");
		e->txt->txt_5 = init_xpm(e, "resources/textures/txt8/t5.xpm");
		e->txt->txt_6 = init_xpm(e, "resources/textures/txt8/t6.xpm");
		e->txt->txt_7 = init_xpm(e, "resources/textures/txt8/t7.xpm");
		e->txt->txt_8 = init_xpm(e, "resources/textures/txt8/t8.xpm");
		e->txt->txt_9 = init_xpm(e, "resources/textures/txt8/t9.xpm");
	}
	load_txt_4(e);
}

void	load_txt_2(t_env *e)
{
	if (e->pack == 5)
	{
		e->txt->txt_1 = init_xpm(e, "resources/textures/txt5/t1.xpm");
		e->txt->txt_2 = init_xpm(e, "resources/textures/txt5/t2.xpm");
		e->txt->txt_3 = init_xpm(e, "resources/textures/txt5/t3.xpm");
		e->txt->txt_4 = init_xpm(e, "resources/textures/txt5/t4.xpm");
		e->txt->txt_5 = init_xpm(e, "resources/textures/txt5/t5.xpm");
		e->txt->txt_6 = init_xpm(e, "resources/textures/txt5/t6.xpm");
		e->txt->txt_7 = init_xpm(e, "resources/textures/txt5/t7.xpm");
		e->txt->txt_8 = init_xpm(e, "resources/textures/txt5/t8.xpm");
		e->txt->txt_9 = init_xpm(e, "resources/textures/txt5/t9.xpm");
	}
	else if (e->pack == 6)
	{
		e->txt->txt_1 = init_xpm(e, "resources/textures/txt6/t1.xpm");
		e->txt->txt_2 = init_xpm(e, "resources/textures/txt6/t2.xpm");
		e->txt->txt_3 = init_xpm(e, "resources/textures/txt6/t3.xpm");
		e->txt->txt_4 = init_xpm(e, "resources/textures/txt6/t4.xpm");
		e->txt->txt_5 = init_xpm(e, "resources/textures/txt6/t5.xpm");
		e->txt->txt_6 = init_xpm(e, "resources/textures/txt6/t6.xpm");
		e->txt->txt_7 = init_xpm(e, "resources/textures/txt6/t7.xpm");
		e->txt->txt_8 = init_xpm(e, "resources/textures/txt6/t8.xpm");
		e->txt->txt_9 = init_xpm(e, "resources/textures/txt6/t9.xpm");
	}
	load_txt_3(e);
}

void	load_txt_1(t_env *e)
{
	if (e->pack == 3)
	{
		e->txt->txt_1 = init_xpm(e, "resources/textures/txt3/t1.xpm");
		e->txt->txt_2 = init_xpm(e, "resources/textures/txt3/t2.xpm");
		e->txt->txt_3 = init_xpm(e, "resources/textures/txt3/t3.xpm");
		e->txt->txt_4 = init_xpm(e, "resources/textures/txt3/t4.xpm");
		e->txt->txt_5 = init_xpm(e, "resources/textures/txt3/t5.xpm");
		e->txt->txt_6 = init_xpm(e, "resources/textures/txt3/t6.xpm");
		e->txt->txt_7 = init_xpm(e, "resources/textures/txt3/t7.xpm");
		e->txt->txt_8 = init_xpm(e, "resources/textures/txt3/t8.xpm");
		e->txt->txt_9 = init_xpm(e, "resources/textures/txt3/t9.xpm");
	}
	else if (e->pack == 4)
	{
		e->txt->txt_1 = init_xpm(e, "resources/textures/txt4/t1.xpm");
		e->txt->txt_2 = init_xpm(e, "resources/textures/txt4/t2.xpm");
		e->txt->txt_3 = init_xpm(e, "resources/textures/txt4/t3.xpm");
		e->txt->txt_4 = init_xpm(e, "resources/textures/txt4/t4.xpm");
		e->txt->txt_5 = init_xpm(e, "resources/textures/txt4/t5.xpm");
		e->txt->txt_6 = init_xpm(e, "resources/textures/txt4/t6.xpm");
		e->txt->txt_7 = init_xpm(e, "resources/textures/txt4/t7.xpm");
		e->txt->txt_8 = init_xpm(e, "resources/textures/txt4/t8.xpm");
		e->txt->txt_9 = init_xpm(e, "resources/textures/txt4/t9.xpm");
	}
	load_txt_2(e);
}

void	load_txt(t_env *e)
{
	e->txt = (t_txt *)malloc(sizeof(t_txt));
	if (e->pack == 1)
	{
		e->txt->txt_1 = init_xpm(e, "resources/textures/txt1/t1.xpm");
		e->txt->txt_2 = init_xpm(e, "resources/textures/txt1/t2.xpm");
		e->txt->txt_3 = init_xpm(e, "resources/textures/txt1/t3.xpm");
		e->txt->txt_4 = init_xpm(e, "resources/textures/txt1/t4.xpm");
		e->txt->txt_5 = init_xpm(e, "resources/textures/txt1/t5.xpm");
		e->txt->txt_6 = init_xpm(e, "resources/textures/txt1/t6.xpm");
		e->txt->txt_7 = init_xpm(e, "resources/textures/txt1/t7.xpm");
		e->txt->txt_8 = init_xpm(e, "resources/textures/txt1/t8.xpm");
		e->txt->txt_9 = init_xpm(e, "resources/textures/txt1/t9.xpm");
	}
	else if (e->pack == 2)
	{
		e->txt->txt_1 = init_xpm(e, "resources/textures/txt2/t1.xpm");
		e->txt->txt_2 = init_xpm(e, "resources/textures/txt2/t2.xpm");
		e->txt->txt_3 = init_xpm(e, "resources/textures/txt2/t3.xpm");
		e->txt->txt_4 = init_xpm(e, "resources/textures/txt2/t4.xpm");
		e->txt->txt_5 = init_xpm(e, "resources/textures/txt2/t5.xpm");
		e->txt->txt_6 = init_xpm(e, "resources/textures/txt2/t6.xpm");
		e->txt->txt_7 = init_xpm(e, "resources/textures/txt2/t7.xpm");
		e->txt->txt_8 = init_xpm(e, "resources/textures/txt2/t8.xpm");
		e->txt->txt_9 = init_xpm(e, "resources/textures/txt2/t9.xpm");

	}
	load_txt_1(e);
}
