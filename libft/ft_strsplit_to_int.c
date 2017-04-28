/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_to_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:43:26 by cde-laro          #+#    #+#             */
/*   Updated: 2017/02/09 18:09:15 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		*ft_b(int *dest, char const *s, char c)
{
	size_t		box;
	size_t		i;
	size_t		start;

	i = 0;
	box = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			start = i;
			dest[box] = ft_atoi(&s[i]);
			while (s[i] != c && s[i])
				i++;
			box++;
		}
	}
	return (dest);
}

int				*ft_strsplit_to_int(char const *s, char c)
{
	int		*dest;
	int		n;

	if (!s)
		return (NULL);
	n = ft_countelem(s, c);
	if (!(dest = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	dest = ft_b(dest, s, c);
	return (dest);
}
