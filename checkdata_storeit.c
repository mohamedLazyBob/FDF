/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:16:24 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/06 13:16:43 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_length(char *s)
{
	int		length;

	length = 0;
	while (*s)
	{
		skip_space(&s);
		if (*s)
		{
			skip_notspace(&s);
			length++;
		}
	}
	return (length);
}

void	get_mapdim(int fd, t_map *map)
{
	char		*s;

	get_next_line(fd, &s);
	if (!(map->dim.length = get_length(s)))
	{
		ft_putendl("No data found.");
		ft_strdel(&s);
		exit(0);
	}
	ft_strdel(&s);
	map->dim.width = 1;
	while (get_next_line(fd, &s) > 0)
	{
		if (get_length(s) < map->dim.length)
		{
			ft_putendl("Found wrong line length. Exiting.");
			ft_strdel(&s);
			exit(0);
		}
		ft_strdel(&s);
		map->dim.width++;
	}
}

t_point		*get_points(int fd, int length, int width)
{
	t_point		*tab;
	char		*s;
	int			counter[4];
	char		*to_free;

	ft_bzero(counter, sizeof(int) * 4);
	if (!(tab = (t_point*)malloc(sizeof(t_point) * (width * length))))
	{
		perror("");
		exit(0);
	}
	while (get_next_line(fd, &s) > 0)
	{
		to_free = s;
		counter[0] = 0;
		counter[2] = 0;
		while (*s && counter[2]++ < length)
		{
			skip_space(&s);
			tab[counter[3]].x = counter[0]++;
			tab[counter[3]].y = counter[1];
			tab[counter[3]++].z = ft_atoi(s);
			skip_notspace(&s);
		}
		counter[1]++;
		ft_strdel(&to_free);
	}
	return (tab);
}

void		get_map(int fd, t_map *map)
{
	get_mapdim(fd, map);
	lseek(fd, 0, SEEK_SET);
	map->tab = get_points(fd, map->dim.length, map->dim.width);
}
