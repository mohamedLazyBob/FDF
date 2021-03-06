/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_help_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:06:53 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/31 18:04:17 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

/*
** ****************************************************************************
*/

t_point			swap_coordinats(t_point point)
{
	t_point		new_pt;

	new_pt.x = point.y;
	new_pt.y = point.x;
	new_pt.z = point.z;
	new_pt.v = point.v;
	return (new_pt);
}

/*
** ****************************************************************************
*/

int				is_horizontal(int dx, int dy)
{
	if (dy == 0 && dx != 0)
		return (1);
	return (0);
}

/*
** ****************************************************************************
*/

int				is_vertical(int dx, int dy)
{
	if (dx == 0 && dy != 0)
		return (1);
	return (0);
}

/*
** ****************************************************************************
*/

int				is_diagonal(int dx, int dy)
{
	if (ABS(dx) == ABS(dy))
		return (1);
	return (0);
}

/*
** ****************************************************************************
*/

void			swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
** ****************************************************************************
*/
