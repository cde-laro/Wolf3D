/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:54:14 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/13 16:33:08 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*d;
	unsigned char			*s;
	size_t					i;
	unsigned char			x;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	x = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == x)
			return (&d[i + 1]);
		i++;
	}
	return (NULL);
}
