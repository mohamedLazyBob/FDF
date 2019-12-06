/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 00:50:25 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/06 21:55:59 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*t_point     translation(t_point vect, t_point point)
{
	t_point pt;

	pt.x = point.x + vect.x;
	pt.y = point.y + vect.y;
	pt.z = point.z + vect.z;
	pt.color = point.color;
	return (pt);
}*/

void     translation(int xt, int yt, t_map *map)
{
	int taill;
	int i;

	taill = map->dim.length * map->dim.width;
	i = 0;
	while (i < taill)
	{
		map->tab[i].x = map->tab[i].x + xt;
		map->tab[i].y = map->tab[i].y + yt;
		i++;
	}
}

/*t_point     homothetie(int k, t_point point)
{
	t_point     pt;

	pt.x = point.x * k;
	pt.y = point.y * k;
	pt.z = point.z * k;
	pt.color = point.color;
	return (pt);
}*/

void     homothetie(int k, t_map *map)
{
	int taill;
	int i;

	taill = map->dim.length * map->dim.width;
	i = 0;
	while (i < taill)
	{
		map->tab[i].x = map->tab[i].x * k;
		map->tab[i].y = map->tab[i].y * k;
		map->tab[i].z = map->tab[i].z * k;
		i++;
	}
}

void	zoom(t_map *map)
{
	int taill;
	int i;
	int xinc;
	int yinc;

	taill = map->dim.length * map->dim.width;
	yinc = 0;
	i = 0;
	while (yinc < map->dim.width)
	{
		xinc = 0;
		while (xinc < map->dim.length)
		{
			map->tab[i].x = map->tab[i].x + xinc;
			map->tab[i].y = map->tab[i].y + yinc;
			xinc++;
			i++;
		}
		yinc++;
	}

}

t_point	iso(t_point point)
{
	t_point		pt;

	pt.x = (point.x - point.y) * cos(0.523599);
	pt.y = -point.z + (point.x + point.y) * sin(0.523599);
	pt.z = point.z;
	pt.color = point.color;
	return (pt);
}

/*void	iso(t_map *map, t_isomap *isomap)
{
	int taill;
	int i;

	taill = map->dim.length * map->dim.width;
	//ft_memdel(&(void*)isomap);
	isomap = (t_isomap*)malloc(sizeof(*isomap));
	isomap->tab = (t_isopt*)malloc(sizeof(t_isopt) * taill);
	i = 0;
	while (i < taill)
	{
		isomap->tab[i].x = (map->tab[i].x - map->tab[i].y) * cos(0.523599);
		isomap->tab[i].y = -map->tab[i].z + (map->tab[i].x + map->tab[i].y) * sin(0.523599);
		isomap->tab[i].color = map->tab[i].color;
		i++;
	}
}
*/

/*t_point     xrotation(t_point origin, angle, t_point point)
{
	t_point     pt;

	pt.x =;
}
t_point     yrotation(t_point origin, angle, t_point point)
{
	t_point     pt;

	pt.x =;
}
t_point     zrotation(t_point origin, angle, t_point point)
{
	t_point     pt;

	pt.x =;
}*/
