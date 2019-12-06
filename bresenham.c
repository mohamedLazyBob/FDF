/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 22:10:03 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/06 14:42:08 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	swap_coordinats(t_point point)
{
	t_point		new_pt;
	
	new_pt.x = point.y;
	new_pt.y = point.x;
	return (new_pt);
}

int		is_horizontal(int dx, int dy)
{
	if (dy == 0 && dx != 0)
		return (1);
	return (0);
}

int		is_vertical(int dx, int dy)
{
	if (dx == 0 && dy != 0)
		return (1);
	return (0);
}

int		abs(int a)
{
	return (a >= 0 ? a : -a);
}

int		is_diagonal(int dx, int dy)
{
	if (abs(dx) == abs(dy))
		return (1);
	return (0);
}

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

void	swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

void    draw_in_octant1458(t_mlxparams *mlxparams, t_point p1, t_point p2)
{
	int     edx;
	int     pdx;
	int     dx;
	int     dy;
	int		incrx;
	int		incry;
	int		i;
	int		index;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	pdx = dy;
	edx = 0;
	incrx = dx > 0 ? 1 : -1;
	dx = dx > 0 ? dx : -dx;
	incry = dy > 0 ? 1 : -1;
	dy = dy > 0 ? dy : -dy;
	i = abs(dx);
	while (i-- >= 0)
	{
		index = mlxparams->length_img * p1.y + p1.x;
		if (index >= 0/*&& p1.y < mlxparams.width_img && p1.x < mlxparams.length_img*/)
			mlxparams->image[index] = 0xffffff;
		if ((2 * (edx + abs(pdx))) < abs(dx))//les tests en nbr entiers est plus efficaces
			edx += abs(dy);
		else
		{
			p1.y += incry;
			edx += abs(pdx) - abs(dx);
		}
		p1.x += incrx;
	}
}

void	draw_in_octant2367(t_mlxparams *mlxparams, t_point p1, t_point p2)
{
	int     edx;
	int     pdx;
	int     dx;
	int     dy;
	int		incrx;
	int		incry;
	int		i;
	int		index;

	p1 = swap_coordinats(p1);
	p2 = swap_coordinats(p2);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	pdx = dy;
	edx = 0;
	incrx = dx > 0 ? 1 : -1;
	dx = dx > 0 ? dx : -dx;
	incry = dy > 0 ? 1 : -1;
	dy = dy > 0 ? dy : -dy;
	i = abs(dx);
	while (i-- >= 0)
	{
		p1 = swap_coordinats(p1);
		index = mlxparams->length_img * p1.y + p1.x;
		if (index >= 0 /*&& p1.y < mlxparams.width_img && p1.x < mlxparams.length_img*/)
			mlxparams->image[index] = 0xffffff;
		p1 = swap_coordinats(p1);
		if ((2 * (edx + abs(pdx))) < abs(dx))//les tests en nbr entiers est plus efficaces
			edx += abs(dy);
		else
		{
			p1.y += incry;
			edx += abs(pdx) - abs(dx);
		}
		p1.x += incrx;
	}

}

void	draw_horizontal_line(t_mlxparams *mlxparams, t_point pt1, t_point pt2)
{
	int     dx;
	int		y;
	int		index;

	dx = pt2.x - pt1.x;
	y = pt1.y;
	if (dx < 0)
		swap(&pt1.x, &pt2.x);
	while (pt1.x <= pt2.x)
	{
		index = mlxparams->length_img * y + pt1.x;
		if (index >= 0)
			mlxparams->image[index] = 0xffffff;
		pt1.x++;
	}
}

void	draw_vertical_line(t_mlxparams *mlxparams, t_point pt1, t_point pt2)
{
	int     dy;
	int		x;
	int		index;

	dy = pt2.y - pt1.y;
	x = pt1.x;
	if (dy < 0)
		swap(&pt1.y, &pt2.y);
	while (pt1.y <= pt2.y)
	{
		//mlx_pixel_put(mlxparams.mlx_ptr, mlxparams.mlx_win, x, pt1.y, 0xffffff);
		index = mlxparams->length_img * pt1.y + x;
		if (index >= 0)
			mlxparams->image[index] = 0xffffff;
		pt1.y++;
	}
}

void	draw_diagonal_line(t_mlxparams *mlxparams, t_point pt1, t_point pt2)
{
	int     dx;
	int     dy;
	int		xincr;
	int		yincr;
	int		index;

	dx = pt2.x - pt1.x;
	dy = pt2.y - pt1.y;
	xincr = dx > 0 ? 1 : -1;
	yincr = dy > 0 ? 1 : -1;
	dx = abs(dx);
	while (dx-- >= 0)
	{
		//mlx_pixel_put(mlxparams.mlx_ptr, mlxparams.mlx_win, pt1.x, pt1.y, 0xffffff);
		index = mlxparams->length_img * pt1.y + pt1.x;
		if (index >= 0)
			mlxparams->image[index] = 0xffffff;
		pt1.x += xincr;
		pt1.y += yincr;
	}
}

void    bresenham(t_mlxparams *mlxparams, t_point pt1, t_point pt2)
{
	int     dx;
	int     dy;
	int		n;
	void	(*draw_trivial_line[3])(t_mlxparams *mlxparams, t_point pt1, t_point pt2);
	int		index;

	draw_trivial_line[0] = draw_horizontal_line;
	draw_trivial_line[1] = draw_vertical_line;
	draw_trivial_line[2] = draw_diagonal_line;
	//pt1 = translation((t_point){250, 250}, pt1);
	//pt2 = translation((t_point){250, 250}, pt2);
	//printf("pt1.x = %d;\tpt1.y = %d;\npt2.x = %d;\tpt2.y = %d;\n", pt1.x, pt1.y, pt2.x, pt2.y);
	dx = pt2.x - pt1.x;
	dy = pt2.y - pt1.y;
//	printf("dx = %d;\tdy = %d;\n-------------------\n", dx, dy);
	if (dx == 0 && dy == 0)
	{
		index = mlxparams->length_img * pt1.y + pt1.x;
		if (index >= 0)
		mlxparams->image[index] = 0xffffff;
	}
	else if ((n = is_trivial_line(dx, dy)) != -1)
   		draw_trivial_line[n](mlxparams, pt1, pt2);
	else
	{
		if (abs(dx) > abs(dy))
			draw_in_octant1458(mlxparams, pt1, pt2);
		else
		{
//			printf("hi\n");
			draw_in_octant2367(mlxparams, pt1, pt2);
//			printf("hi\n");
		}
	}
}
