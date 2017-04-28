/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:08:58 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/04 15:09:05 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	pos;

	if (n < 0)
		ft_putchar_fd('-', fd);
	pos = ABS(n);
	if (pos >= 10)
	{
		ft_putnbr_fd(pos / 10, fd);
		ft_putnbr_fd(pos % 10, fd);
	}
	else
		ft_putchar_fd(pos + '0', fd);
}
