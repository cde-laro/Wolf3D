/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:09:54 by cde-laro          #+#    #+#             */
/*   Updated: 2016/11/10 11:50:16 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		dest;
	int		n;
	char	isneg;

	dest = 0;
	n = 0;
	isneg = 0;
	while (str[n] == ' ' || str[n] == '\n' || str[n] == '\t' || str[n] == '\f'
			|| str[n] == '\v' || str[n] == '\r')
		n++;
	if (str[n] == '-')
	{
		isneg = 1;
		n++;
	}
	else if (str[n] == '+')
		n++;
	while (str[n] >= '0' && str[n] <= '9')
	{
		dest = dest * 10 + (str[n] - '0');
		n++;
	}
	return (isneg ? -dest : dest);
}
