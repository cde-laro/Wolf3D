/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:43:09 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/04 15:07:04 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	pos;

	if (n < 0)
		ft_putchar('-');
	pos = ABS(n);
	if (pos >= 10)
	{
		ft_putnbr(pos / 10);
		ft_putnbr(pos % 10);
	}
	else
		ft_putchar(pos + '0');
}
