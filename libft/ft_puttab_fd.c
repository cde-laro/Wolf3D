/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:52:04 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/13 19:04:05 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_fd(char **tab, size_t len, int fd)
{
	size_t		i;

	i = 0;
	while (tab[i][0] != '\0' && i <= len)
	{
		ft_putnbr_fd(i, fd);
		ft_putstr_fd("\t [", fd);
		ft_putstr_fd(tab[i], fd);
		ft_putstr_fd("]\n", fd);
		i++;
	}
}
