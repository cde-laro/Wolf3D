/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:24:41 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/10 16:32:17 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		s;

	i = 0;
	while (dest[i] && i < size)
		i++;
	s = i;
	while (src[i - s] && i < (size - 1))
	{
		dest[i] = src[i - s];
		i++;
	}
	if (s < size)
		dest[i] = '\0';
	return (s + ft_strlen(src));
}
