/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:09:21 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/12 20:24:14 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_b(char **dest, char const *s, char c)
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
			while (s[i] != c && s[i])
				i++;
			dest[box] = ft_strsub(s, start, (i - start));
			box++;
		}
	}
	dest[box] = NULL;
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**dest;

	if (!s)
		return (NULL);
	if (!(dest = (char**)malloc(sizeof(*dest) * ((ft_countwords(s, c) + 1)))))
		return (NULL);
	dest = ft_b(dest, s, c);
	return (dest);
}
