/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:42:40 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/13 16:04:20 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	n;
	char			*d;

	n = 0;
	if (!s)
		return (NULL);
	if (!(d = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[n])
	{
		d[n] = (*f)(s[n]);
		n++;
	}
	d[n] = '\0';
	return (d);
}
