/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:48:52 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/26 23:59:54 by cde-laro         ###   ########.fr       */
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
	dest[n] = '\0';
	free(s1);
	return (dest);
}

char		*fdf_extract(int fd, char *filename)
{
	int		i;
	int		ret;
	char	buf[BUFF_SIZE];
	char	*filecontent;

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

t_map		*fdf_parse(char *path)
{
	t_map	*map;
	char	*filecontent;
	char	**tab;
	int		fd;
	int		n;

	if (!(map = (t_map *)malloc(sizeof(map))))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (!(filecontent = fdf_extract(fd, path)))
		return (NULL);
	map->maxy = ft_countchar(filecontent, '\n');
	close(fd);
	tab = ft_strsplit(filecontent, '\n');
	map->data = (int **)malloc(sizeof(int *) * map->maxy + 1);
	n = -1;
	while (++n < (int)map->maxy)
	{
		map->data[n] = ft_strsplit_to_int(tab[n], ' ');
		free(tab[n]);
	}
	free(filecontent);
	free(tab);
	return (map);
}
