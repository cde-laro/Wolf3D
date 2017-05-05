/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 23:55:59 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/02 06:30:44 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		check_char(char *str, char *filename)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || (str[i] == '\n' || str[i] == '\t' ||
						str[i] == ' ' || str[i] == '-')))
		{
			system("clear");
			ft_putendl("There is a \"");
			ft_putchar(str[i]);
			ft_putendl("\" on char: ");
			ft_putnbr(i);
			ft_putendl(" of ");
			ft_putendl(filename);
			ft_putendl("\nPlease check your file");
			return (-1);
		}
		i++;
	}
	return (0);
}

char	*extract(int fd, char *filename)
{
	int			i;
	int			ret;
	char		buf[BUFF_SIZE];
	char		*filecontent;

	i = 0;
	filecontent = ft_strdup("");
	while (0 < (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		filecontent = ft_strjoin_free(filecontent, buf);
	}
	if (-1 == check_char(filecontent, filename) || !ft_strlen(filecontent))
		return (NULL);
	return (filecontent);
}

int		check_line_len(char **tab, int maxy)
{
	int		i;
	int		dest;

	i = 1;
	dest = ft_countelem(tab[0], ' ');
	while (i < maxy)
	{
		if (ft_countelem(tab[i], ' ') != dest)
		{
			system("clear");
			ft_putendl("Line ");
			ft_putnbr(i);
			ft_putendl(" don't have the same lenght than other lines");
			ft_putendl("Check your map");
			return (-1);
		}
		i++;
	}
	return (dest);
}

t_map	*parse(char *path)
{
	t_map		*map;
	char		*filecontent;
	char		**tab;
	int			fd;

	if (!(map = (t_map *)malloc(sizeof(map))))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (!(filecontent = extract(fd, path)))
		return (NULL);
	map->maxy = ft_countchar(filecontent, '\n');
	close(fd);
	tab = ft_strsplit(filecontent, '\n');
	if ((map->maxx = check_line_len(tab, map->maxy)) == -1)
		return (NULL);
	map->data = (int **)malloc(sizeof(int *) * map->maxy + 1);
	fd = -1;
	while (++fd < (int)map->maxy)
	{
		map->data[fd] = ft_strsplit_to_int(tab[fd], ' ');
		free(tab[fd]);
	}
	free(filecontent);
	free(tab);
	return (map);
}
