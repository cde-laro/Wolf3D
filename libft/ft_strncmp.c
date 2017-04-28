/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:08:44 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/11 17:07:37 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t		i;

	i = 0;
	if (len == 0)
		return (0);
	len--;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i] && s2[i]
			&& len > i)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
