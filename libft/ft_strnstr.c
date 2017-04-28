/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:12:20 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/13 20:12:35 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t		i;
	size_t		ibis;
	size_t		j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < n)
	{
		ibis = i;
		while (big[ibis] == little[j] && little[j] && j < n)
		{
			ibis++;
			j++;
		}
		if (little[j] == '\0' && ibis - 1 < n)
			return ((char *)&big[i]);
		else if (j > n)
			return (NULL);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
