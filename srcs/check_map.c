/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:25:10 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/11 14:09:31 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		check_map(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !ft_isdigit(str[i]) && str[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

int		ft_count_s(char *str)
{
	int i;
	int s;

	i = 0;
	s = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\n' )
			s++;
		i++;
	}
	s++;
	return (s);
}

int		ft_isfullnum(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' &&	str[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

int		check_file(int *l, int *a, int fd)
{
	char	*str1;
	char	*buf;
	int		ret;

	if (!(str1 = (char *)malloc(sizeof(char) * 11)))
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * 10001)))
		return (-1);
	ft_memset(buf, '\0', 10001);
	ft_memset(str1, '\0', 11);
	while ((ret = read(fd, buf, 10000)) > 0)
	{
		if (ft_isfullnum(buf))
			print_error_code(36);
		if (!(str1 = ft_strjoin_free(str1, buf)))
			print_error_code(37);
		if (!(buf = (char *)malloc(sizeof(char) * 10001)))
			return (-1);
		ft_memset(buf, '\0', 10001);
	}
	ft_putendl(str1);
	free(buf);
	if (ret == -1 || ft_strlen(str1) < 10)
		print_error_code(38);
	return (check_file2(&str1, l, a));
}
