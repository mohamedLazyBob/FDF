/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 22:10:03 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/09 19:13:26 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** ****************************************************************************
*/

int		is_trivial_line(int dx, int dy)
{
	if (is_horizontal(dx, dy))
		return (0);
	if (is_vertical(dx, dy))
		return (1);
	if (is_diagonal(dx, dy))
		return (2);
	return (-1);
}

/*
** ****************************************************************************
*/

void	draw_vertical_line(t_mlxparams *mlxparams, t_point pt1, t_point pt2)
{
	int	dy;
	int	x;
	int	index;

	dy = pt2.y - pt1.y;
	x = pt1.x;
	if (dy < 0)
		swap(&pt1.y, &pt2.y);
	while (pt1.y <= pt2.y)
	{
		index = mlxparams->length_img * pt1.y + x;
		if (index >= 0 && pt1.y < mlxparams->width_img && \
				pt1.x < mlxparams->length_img && pt1.y >= 0 && pt1.x >= 0)
			mlxparams->image[index] = ft_color(pt1, pt2);
		pt1.y++;
	}
}

/*
** ****************************************************************************
*/

void	draw_diagonal_line(t_mlxparams *mlxparams, t_point pt1, t_point pt2)
{
	int	dx;
	int	dy;
	int	xincr;
	int	yincr;
	int	index;

	dx = pt2.x - pt1.x;
	dy = pt2.y - pt1.y;
	xincr = dx >= 0 ? 1 : -1;
	yincr = dy >= 0 ? 1 : -1;
	dx = ABS(dx);
	while (dx-- >= 0)
	{
		index = mlxparams->length_img * pt1.y + pt1.x;
		if (index >= 0 && pt1.y < mlxparams->width_img && \
				pt1.x < mlxparams->length_img && pt1.y >= 0 && pt1.x >= 0)
			mlxparams->image[index] = ft_color(pt1, pt2);
		pt1.y += yincr;
		pt1.x += xincr;
	}
}

/*
** ****************************************************************************
*/

int		is_out_win(t_point p1, t_point p2)
{
	if ((p1.x > LEN && p2.x > LEN) || (p1.x < 0 && p2.x < 0))
		return (TRUE);
	if ((p1.y > WID && p2.y > WID) || (p1.y < 0 && p2.y < 0))
		return (TRUE);
	return (FALSE);
}

/*
** ****************************************************************************
*/

void	bresenham(t_mlxparams *mlxparams, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	int		n;
	void	(*trivial_line[3])(t_mlxparams *mlxparams, t_point p1, t_point p2);

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	trivial_line[0] = draw_horizontal_line;
	trivial_line[1] = draw_vertical_line;
	trivial_line[2] = draw_diagonal_line;
	if (is_out_win(p1, p2) == TRUE)
		return ;
	if (dx == 0 && dy == 0 && ((mlxparams->length_img * p1.y + p1.x) >= 0))
		mlxparams->image[mlxparams->length_img * p1.y + p1.x] = ft_color(p1, p2);
	else if ((n = is_trivial_line(dx, dy)) != -1)
		trivial_line[n](mlxparams, p1, p2);
	else
	{
		if (ABS(dx) > ABS(dy))
			draw_in_octant1458(mlxparams, p1, p2);
		else
			draw_in_octant2367(mlxparams, p1, p2);
	}
}
