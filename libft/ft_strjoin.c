/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:01:11 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/12 19:53:57 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		n;
	char	*dst;

	n = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[n])
	{
		dst[n] = s1[n];
		n++;
	}
	i = 0;
	while (s2[i])
	{
		dst[n] = s2[i];
		n++;
		i++;
	}
	dst[n] = '\0';
	return (dst);
}
