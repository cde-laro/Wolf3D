/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:24:44 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/10 13:21:32 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t		i;
	size_t		len;

	len = 0;
	i = ft_strlen(s1);
	while (s2[len] && n != 0)
	{
		s1[i] = s2[len];
		i++;
		len++;
		n--;
	}
	s1[i] = '\0';
	return (s1);
}
