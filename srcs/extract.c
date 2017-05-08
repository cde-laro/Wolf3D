/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:55:34 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/08 10:29:13 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char		*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*dest;

	n = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[n])
	{
		dest[n] = s1[n];
		n++;
	}
	i = 0;
	while (s2[i])
	{
		dest[n] = s2[i];
		n++;
		i++;
	}
	dest[n] = s2[i];
	free(s1);
	free(s2);
	return (dest);
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
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\n')
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
		if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
			return (-1);
		else if (str[i] == '-' && ft_isdigit(str[i + 1]) == 0)
			return (-1);
		else if (ft_isdigit(str[i]) == 0 && str[i] != ' '
			&& str[i] != '\0' && str[i] != '-')
			return (-1);
		i++;
	}
	return (0);
}

int		check_file(int *l, int *a, int fd)
{
	char	*str1;
	char	*buf;

	if (!(str1 = (char *)malloc(sizeof(char) * 11)))
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * 10001)))
		return (-1);
	ft_memset(buf, '\0', 10001);
	ft_memset(str1, '\0', 11);
	while (read(fd, buf, 10000) > 0)
	{
		if (!(str1 = ft_strjoin_free(str1, buf)))
			return (-1);
	}
	return (check_file2(&str1, l, a));
}

int		check_file2(char **str1, int *l, int *a)
{
	char	**map;
	int		i;

	map = ft_strsplit(*str1, '\n');
	i = 0;
	while (map[i])
	{
		if (*l == 0)
			*a = ft_count_s(map[i]);
		else
		{
			if (*a != ft_count_s(map[i]))
				return (-1);
		}
		if (ft_isfullnum(map[i]) == -1)
			return (-1);
		*l += 1;
		free(map[i]);
		i++;
	}
	free(*str1);
	free(map);
	return (0);
}

t_map	*map_extract(int fd, char *filename)
{
	int		l;
	int		a;
	t_map	*m;

	l = 0;
	m = NULL;
	if (check_file(&l, &a, fd) == -1)
		return (NULL);
	if (!(m = malloc(sizeof(t_map))))
		return (NULL);
	m->data = NULL;
	if (!(m->data = (int **)malloc(sizeof(int *) * l)))
		return (NULL);
	m->maxy = 0;
	while (m->maxy < l)
	{
		if (!(m->data[m->maxy++] = (int *)malloc(sizeof(int) * a)))
			return (NULL);
	}
	m->maxx = a;
	close(fd);
	fd = open(filename, O_RDONLY);
	if (!(m->data = put_in_map(m->data, fd)))
		return (NULL);
	return (m);
}

char	*extracting(int fd)
{
	char	*str;
	char	*buf;

	if (!(str = (char *)malloc(sizeof(char) * 11)))
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * 10001)))
		return (NULL);
	ft_memset(buf, '\0', 10001);
	ft_memset(str, '\0', 11);
	while (read(fd, buf, 10000) > 0)
	{
		if (!(str = ft_strjoin_free(str, buf)))
			return (NULL);
	}
	return (str);
}

int		**put_in_map(int **map, int fd)
{
	int		n;
	int		s;
	int		i;
	char	*str;

	n = 0;
	i = 0;
	s = 0;
	if (!(str = extracting(fd)))
		return (NULL);
	while (str[i])
	{
		if (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		{
			map[n][s++] = ft_atoi(&str[i]);
			while (str[i] && (str[i] == '-'
				|| (str[i] >= '0' && str[i] <= '9')))
				i++;
		}
		n += (str[i] && str[i] == '\n' ? 1 : 0);
		s = (str[i] && str[i++] == '\n' ? 0 : s);
		i += (str[i] && str[i] == ' ' ? 1 : 0);
	}
	free(str);
	return (map);
}
