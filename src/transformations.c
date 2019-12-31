/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 00:57:19 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/31 18:13:03 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

/*
** ***************************************************************************
*/

t_point	translation2(int x, int y, t_point point)
{
	t_point pt;

	pt.x = point.x + x;
	pt.y = point.y + y;
	pt.z = point.z;
	return (pt);
}

/*
** ***************************************************************************
*/

void	translation(int xt, int yt, t_map *map)
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

/*
** ***************************************************************************
*/

/*
** t_point     homothetie(int k, t_point point)
** {
** 	t_point     pt;
** 	pt.x = point.x * k;
** 	pt.y = point.y * k;
** 	pt.z = point.z * k;
** 	pt.color = point.color;
** 	return (pt);
** }
*/

/*
** ***************************************************************************
*/

void	homothetie(int k, t_map *map)
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

/*
** ***************************************************************************
*/

t_point	iso(t_point point)
{
	t_point		pt;

	pt.x = (point.x - point.y) * cos(0.523599);
	pt.y = -point.z + (point.x + point.y) * sin(0.523599);
	pt.z = point.z;
	return (pt);
}

/*
** ***************************************************************************
*/

/*
** void	iso(t_map *map, t_isomap *isomap)
** {
** 	int taill;
** 	int i;
** 	taill = map->dim.length * map->dim.width;
** 	//ft_memdel(&(void*)isomap);
** 	isomap = (t_isomap*)malloc(sizeof(*isomap));
**  	isomap->tab = (t_isopt*)malloc(sizeof(t_isopt) * taill);
** 	i = 0;
** 	while (i < taill)
** 	{
** 		isomap->tab[i].x = (map->tab[i].x - map->tab[i].y) * cos(0.523599);
** 		isomap->tab[i].y = -map->tab[i].z + (map->tab[i].x + map->tab[i].y) * \
**				sin(0.523599);
** 		isomap->tab[i].color = map->tab[i].color;
** 		i++;
** 	}
** }
** t_point     xrotation(t_point origin, angle, t_point point)
** {
** 	t_point     pt;
**
** 	pt.x =;
** }
** t_point     yrotation(t_point origin, angle, t_point point)
** {
** 	t_point     pt;
**
** 	pt.x =;
** }
** t_point     zrotation(t_point origin, angle, t_point point)
** {
** 	t_point     pt;
** 	pt.x =;
** }
*/
