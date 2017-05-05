/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 06:11:04 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/05 06:16:36 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_xpm	*get_xpm(t_env *e, int id)
{
	if (id == 1)
		return (e->txt->txt_1);
	else if (id == 2)
		return (e->txt->txt_2);
	else if (id == 3)
		return (e->txt->txt_3);
	else if (id == 4)
		return (e->txt->txt_4);
	else if (id == 5)
		return (e->txt->txt_5);
	else if (id == 6)
		return (e->txt->txt_6);
	else if (id == 7)
		return (e->txt->txt_7);
	else if (id == 8)
		return (e->txt->txt_8);
	else if (id == 9)
		return (e->txt->txt_9);
	else
		return (e->txt->txt_1);
}
