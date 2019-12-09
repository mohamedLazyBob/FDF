/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_draw_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:04:21 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/08 23:07:58 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ****************************************************************************
*/

void	initialize_draw_vars(t_draw_vars *var, t_point p1, t_point p2)
{
	var->dx = p2.x - p1.x;
	var->dy = p2.y - p1.y;
	var->pdx = var->dy;
	var->edx = 0;
	var->incrx = var->dx > 0 ? 1 : -1;
	var->dx = var->dx > 0 ? var->dx : -var->dx;
	var->incry = var->dy > 0 ? 1 : -1;
	var->dy = var->dy > 0 ? var->dy : -var->dy;
	var->i = abs(var->dx);
}

/*
** ****************************************************************************
*/

void	draw_in_octant1458(t_mlxparams *mlxparams, t_point p1, t_point p2)
{
	t_draw_vars var;

	initialize_draw_vars(&var, p1, p2);
	while (var.i-- >= 0)
	{
		var.index = mlxparams->length_img * p1.y + p1.x;
		if (var.index >= 0 && p1.y < mlxparams->width_img && \
				p1.x < mlxparams->length_img && p1.y >= 0 && p1.x >= 0)
			mlxparams->image[var.index] = COLOR;
		if ((2 * (var.edx + abs(var.pdx))) < abs(var.dx))
			var.edx += abs(var.dy);
		else
		{
			p1.y += var.incry;
			var.edx += abs(var.pdx) - abs(var.dx);
		}
		p1.x += var.incrx;
	}
}

/*
** ****************************************************************************
*/

void	draw_in_octant2367(t_mlxparams *mlxparams, t_point p1, t_point p2)
{
	t_draw_vars var;

	p1 = swap_coordinats(p1);
	p2 = swap_coordinats(p2);
	initialize_draw_vars(&var, p1, p2);
	while (var.i-- >= 0)
	{
		p1 = swap_coordinats(p1);
		var.index = mlxparams->length_img * p1.y + p1.x;
		if (var.index >= 0 && p1.y < mlxparams->width_img && \
				p1.x < mlxparams->length_img && p1.y >= 0 && p1.x >= 0)
			mlxparams->image[var.index] = COLOR;
		p1 = swap_coordinats(p1);
		if ((2 * (var.edx + abs(var.pdx))) < abs(var.dx))
			var.edx += abs(var.dy);
		else
		{
			p1.y += var.incry;
			var.edx += abs(var.pdx) - abs(var.dx);
		}
		p1.x += var.incrx;
	}
}

/*
** ****************************************************************************
*/

void	draw_horizontal_line(t_mlxparams *mlxparams, t_point pt1, t_point pt2)
{
	int	dx;
	int	y;
	int	index;

	dx = (pt2.x - pt1.x);
	y = pt1.y;
	if (dx < 0)
		swap(&pt1.x, &pt2.x);
	while (pt1.x <= pt2.x)
	{
		index = mlxparams->length_img * y + pt1.x;
		if (index >= 0 && pt1.x < mlxparams->length_img && \
				pt1.y < mlxparams->width_img && pt1.y >= 0 && pt1.x >= 0)
			mlxparams->image[index] = COLOR;
		pt1.x++;
	}
}
