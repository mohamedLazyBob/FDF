/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_draw_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:04:21 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/31 18:04:14 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

/*
** ****************************************************************************
*/

int		ft_color(t_point p1, t_point p2)
{
	if (ABS(p1.z) == 0 && ABS(p2.z) == 0)
		return (0XFFFFFF);
	else if (p2.z == 0 || p1.z == 0)
		return (0X66FFFF);
	else if (ABS(p2.z) <= 5 || ABS(p1.z) <= 5)
		return (0X66FF99);
	else
		return (0X0099FF);
}

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
	var->i = ABS(var->dx);
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
			mlxparams->image[var.index] = ft_color(p1, p2);
		if ((2 * (var.edx + ABS(var.pdx))) < ABS(var.dx))
			var.edx += ABS(var.dy);
		else
		{
			p1.y += var.incry;
			var.edx += ABS(var.pdx) - ABS(var.dx);
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
			mlxparams->image[var.index] = ft_color(p1, p2);
		p1 = swap_coordinats(p1);
		if ((2 * (var.edx + ABS(var.pdx))) < ABS(var.dx))
			var.edx += ABS(var.dy);
		else
		{
			p1.y += var.incry;
			var.edx += ABS(var.pdx) - ABS(var.dx);
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
			mlxparams->image[index] = ft_color(pt1, pt2);
		pt1.x++;
	}
}
