/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:55:34 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/10 15:55:18 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	*ft_strjoin_free(char *s1, char *s2)
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
		dest[n++] = s2[i++];
	dest[n] = s2[i];
	free(s1);
	free(s2);
	return (dest);
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
				print_error_code(25);
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
	if (!(m->data = put_in_map(m->data, fd, m->maxx, m->maxy)))
		return (NULL);
	return (m);
}

char	*extracting(int fd)
{
	char	*str;
	char	*buf;
	int		ret;

	if (!(str = (char *)malloc(sizeof(char) * 11)))
		print_error_code(33);
	if (!(buf = (char *)malloc(sizeof(char) * 10001)))
		print_error_code(34);
	ft_memset(buf, '\0', 10);
	ft_memset(str, '\0', 11);
	while ((ret = read(fd, buf, 10000)) > 0)
	{
		if (ft_isfullnum(buf) == -1)
			print_error_code(43);
		if (!(str = ft_strjoin_free(str, buf)))
			print_error_code(35);
	}

	if (ret == -1)
		print_error_code(41);
	if (check_map(str) == -1)
		print_error_code(43);
	return (str);
}

int		**put_in_map(int **map, int fd, int maxx, int maxy)
{
	int		n;
	int		s;
	int		i;
	char	*str;

	n = 0;
	i = 0;
	s = 0;
	str = extracting(fd);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			map[n][s] = ft_atoi(&str[i]);
			while (str[i] && (str[i] >= '0' && str[i] <= '9'))
				i++;
		}
		if ((!n || n == maxy - 1 || !s || s == maxx - 1) && map[n][s] == 0)
			map[n][s] = 1;
		n += (str[i] && str[i] == '\n' ? 1 : 0);
		s = (str[i] && str[i++] == '\n' ? 0 : s + 1);
		i += (str[i] && str[i] == ' ' ? 1 : 0);
	}
	free(str);
	return (map);
}
