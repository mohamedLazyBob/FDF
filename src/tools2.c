/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:08:08 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/31 18:13:16 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

/*
** ---------------------------------------------------------------------------
*/

int		max(int a, int b, int c, int d)
{
	int tab[4];
	int i;
	int max;

	tab[0] = a;
	tab[1] = b;
	tab[2] = c;
	tab[3] = d;
	i = 1;
	max = a;
	while (i < 4)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

/*
** ---------------------------------------------------------------------------
*/

int		min(int a, int b, int c, int d)
{
	int tab[4];
	int i;
	int min;

	tab[0] = a;
	tab[1] = b;
	tab[2] = c;
	tab[3] = d;
	i = 1;
	min = a;
	while (i < 4)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

/*
** ***************************************************************************
*/

int		is_min_size(t_map *map)
{
	int len;
	int	wid;
	int	maxx;
	int	maxy;

	(map->dim.length % 2 == 1) ? (maxx = (map->dim.length / 2 + 1)) : \
												(maxx = map->dim.length / 2);
	(map->dim.width % 2 == 1) ? (maxy = (map->dim.width / 2 + 1)) : \
												(maxy = map->dim.width / 2);
	len = (map->tab[map->dim.length - 1].x - maxx) - \
									(map->tab[0].x - map->dim.length / 2);
	wid = (map->tab[map->dim.length * (map->dim.width - 1)].y - maxy) - \
										(map->tab[0].y + map->dim.width / 2);
	if (len < 200 || wid < 200)
		return (TRUE);
	return (FALSE);
}

/*
** ***************************************************************************
*/

void	zoomin(t_map *map)
{
	int i;
	int xinc;
	int yinc;
	int	maxx;
	int	maxy;

	yinc = -map->dim.width / 2;
	(map->dim.length % 2 == 1) ? (maxx = (map->dim.length / 2 + 1)) : \
						(maxx = map->dim.length / 2);
	(map->dim.width % 2 == 1) ? (maxy = (map->dim.width / 2 + 1)) : \
						(maxy = map->dim.width / 2);
	i = 0;
	while (yinc < maxy)
	{
		xinc = -map->dim.length / 2 - 1;
		while (++xinc < maxx)
		{
			map->tab[i].x = map->tab[i].x + xinc;
			map->tab[i].y = map->tab[i].y + yinc;
			map->tab[i].z = map->tab[i].z + map->tab[i].v;
			i++;
		}
		yinc++;
	}
}

/*
** ***************************************************************************
*/

void	zoomout(t_map *map)
{
	int i;
	int xinc;
	int yinc;
	int	maxx;
	int	maxy;

	if (is_min_size(map) == TRUE)
		return ;
	(map->dim.length % 2 == 1) ? (maxx = (map->dim.length / 2 + 1)) : \
												(maxx = map->dim.length / 2);
	(map->dim.width % 2 == 1) ? (maxy = (map->dim.width / 2 + 1)) : \
												(maxy = map->dim.width / 2);
	yinc = -map->dim.width / 2 - 1;
	i = 0;
	while (--i >= -1 && ++yinc < maxy)
	{
		xinc = -map->dim.length / 2 - 1;
		while (++i >= 0 && ++xinc < maxx)
		{
			map->tab[i].x = map->tab[i].x - xinc;
			map->tab[i].y = map->tab[i].y - yinc;
			map->tab[i].z = map->tab[i].z - map->tab[i].v;
		}
	}
}

/*
** ****************************************************************************
*/
