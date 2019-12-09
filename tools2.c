/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:08:08 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/09 19:14:37 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		xinc = -map->dim.length / 2;
		while (xinc < maxx)
		{
			map->tab[i].x = map->tab[i].x + xinc;
			map->tab[i].y = map->tab[i].y + yinc;
			xinc++;
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

	(map->dim.length % 2 == 1) ? (maxx = (map->dim.length / 2 + 1)) : \
												(maxx = map->dim.length / 2);
	(map->dim.width % 2 == 1) ? (maxy = (map->dim.width / 2 + 1)) : \
												(maxy = map->dim.width / 2);
	yinc = -map->dim.width / 2;
	i = 0;
	while (yinc < maxy)
	{
		xinc = -map->dim.length / 2;
		while (xinc < maxx)
		{
			map->tab[i].x = map->tab[i].x - xinc;
			map->tab[i].y = map->tab[i].y - yinc;
			xinc++;
			i++;
		}
		yinc++;
	}
}

/*
** ****************************************************************************
*/


