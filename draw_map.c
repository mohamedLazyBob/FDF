/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 00:55:40 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/10 00:55:44 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_idx(int *index, int dimlen, int start)
{
	index[0] = start;
	index[1] = index[0] + 1;
	index[2] = index[0] + dimlen;
}

/*
** ***************************************************************************
*/

void	call_bresenham(t_hook *vars, t_point pt, int *index, int nbr)
{
	if (nbr == 0)
	{
		bresenham(vars->mlxparams, \
				translation2(pt.x, pt.y, vars->map->tab[index[0]]), \
				translation2(pt.x, pt.y, vars->map->tab[index[1]]));
		bresenham(vars->mlxparams, \
				translation2(pt.x, pt.y, vars->map->tab[index[0]]),\
				translation2(pt.x, pt.y, vars->map->tab[index[2]]));
	}
	else if (nbr == 1)
	{
		bresenham(vars->mlxparams, \
				translation2(pt.x, pt.y, vars->map->tab[index[0]]), \
				translation2(pt.x, pt.y, vars->map->tab[index[1]]));
	}
	else if (nbr == 2)
	{
		bresenham(vars->mlxparams, \
				translation2(pt.x, pt.y, vars->map->tab[index[0]]), \
				translation2(pt.x, pt.y, vars->map->tab[index[2]]));
	}
}

/*
** ***************************************************************************
*/

void	call_iso_bresenham(t_hook *vars, t_point pt, int *index, int nbr)
{
	if (nbr == 0)
	{
		bresenham(vars->mlxparams, \
				translation2(pt.x, pt.y, iso(vars->map->tab[index[0]])), \
				translation2(pt.x, pt.y, iso(vars->map->tab[index[1]])));
		bresenham(vars->mlxparams, \
				translation2(pt.x, pt.y, iso(vars->map->tab[index[0]])), \
				translation2(pt.x, pt.y, iso(vars->map->tab[index[2]])));
	}
	else if (nbr == 1)
	{
		bresenham(vars->mlxparams, \
				translation2(pt.x, pt.y, iso(vars->map->tab[index[0]])), \
				translation2(pt.x, pt.y, iso(vars->map->tab[index[1]])));
	}
	else if (nbr == 2)
	{
		bresenham(vars->mlxparams, \
				translation2(pt.x, pt.y, iso(vars->map->tab[index[0]])), \
				translation2(pt.x, pt.y, iso(vars->map->tab[index[2]])));
	}
}

/*
** ***************************************************************************
*/

void	parallel_proj(t_hook *vars, t_point pt)
{
	int		i;
	int		j;
	int		index[3];

	j = -1;
	while (++j < vars->map->dim.width - 1)
	{
		i = -1;
		while (++i < vars->map->dim.length - 1)
		{
			ft_idx(index, vars->map->dim.length, j * vars->map->dim.length + i);
			call_bresenham(vars, pt, index, 0);
		}
		ft_idx(index, vars->map->dim.length, j * vars->map->dim.length + i);
		call_bresenham(vars, pt, index, 2);
	}
	i = -1;
	while (++i < vars->map->dim.length - 1)
	{
		ft_idx(index, vars->map->dim.length, j * vars->map->dim.length + i);
		call_bresenham(vars, pt, index, 1);
	}
	mlx_put_image_to_window(vars->mlxparams->mlx_ptr, \
							vars->mlxparams->mlx_win, \
							vars->mlxparams->img_ptr, 0, 0);
}

/*
** ***************************************************************************
*/

void	iso_proj(t_hook *vars, t_point pt)
{
	int		i;
	int		j;
	int		index[3];

	j = -1;
	while (++j < vars->map->dim.width - 1)
	{
		i = -1;
		while (++i < vars->map->dim.length - 1)
		{
			ft_idx(index, vars->map->dim.length, j * vars->map->dim.length + i);
			call_iso_bresenham(vars, pt, index, 0);
		}
		ft_idx(index, vars->map->dim.length, j * vars->map->dim.length + i);
		call_iso_bresenham(vars, pt, index, 2);
	}
	i = -1;
	while (++i < vars->map->dim.length - 1)
	{
		ft_idx(index, vars->map->dim.length, j * vars->map->dim.length + i);
		call_iso_bresenham(vars, pt, index, 1);
	}
	mlx_put_image_to_window(vars->mlxparams->mlx_ptr, \
							vars->mlxparams->mlx_win, \
							vars->mlxparams->img_ptr, 0, 0);
}

/*
** ***************************************************************************
*/
