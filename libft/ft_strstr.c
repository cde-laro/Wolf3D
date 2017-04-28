/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:38:49 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/11 15:32:54 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		ibis;
	int		j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i])
	{
		ibis = i;
		while (big[ibis] == little[j] && little[j] && big[ibis])
		{
			ibis++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
