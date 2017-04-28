/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:27:50 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/14 12:27:22 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (str1 > str2)
	{
		str1 = str1 + n - 1;
		str2 = str2 + n - 1;
		while (n--)
			*str1-- = *str2--;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
