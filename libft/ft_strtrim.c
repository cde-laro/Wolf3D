/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:30:15 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/13 15:48:54 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		st;
	size_t		end;
	char		*sub;

	st = 0;
	if (!s)
		return (NULL);
	while ((s[st] == ' ' || s[st] == '\n' || s[st] == '\t') && s[st])
		st++;
	if (s[st] != '\0')
	{
		end = ft_strlen(s) - 1;
		while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end > 0)
			end--;
		end++;
		if (!(sub = ((char *)malloc(sizeof(char) * (end - st)))))
			return (NULL);
		sub = ft_strsub(s, st, end - st);
	}
	else
	{
		sub = (char *)malloc(sizeof(char) * 1);
		sub[0] = '\0';
	}
	return (sub);
}
