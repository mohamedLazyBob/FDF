/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:25:03 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/06 21:19:36 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parallel_proj(t_mlxparams *mlxparams, t_map map)
{
	int		i;
	int		j;
	int		index1;
	int		index2;
	int		index3;

	j = 0;
	while (j < map.dim.width - 1)
	{
		i = 0;
		while (i < map.dim.length - 1)
		{
			index1 = j * map.dim.length + i;
			index2 = index1 + 1;
			index3 = index1 + map.dim.length;
			bresenham(mlxparams, map.tab[index1], map.tab[index2]);
			bresenham(mlxparams, map.tab[index1], map.tab[index3]);
			i++;
		}
		index1 = j * map.dim.length + i;
		index3 = index1 + map.dim.length;
		bresenham(mlxparams, map.tab[index1], map.tab[index3]);
		j++;
	}
	i = 0;
	while (i < map.dim.length - 1)
	{
		index1 = j * map.dim.length + i;
		index2 = index1 + 1;
		bresenham(mlxparams, map.tab[index1], map.tab[index2]);
		i++;
	}
	mlx_put_image_to_window(mlxparams->mlx_ptr, mlxparams->mlx_win, mlxparams->img_ptr, 0, 0);
}

void	iso_proj(t_mlxparams *mlxparams, t_map map)
{
	int		i;
	int		j;
	int		index1;
	int		index2;
	int		index3;
	
	homothetie(15, &map);
	translation(500, 100, &map);
	j = 0;
	while (j < map.dim.width - 1)
	{
		i = 0;
		while (i < map.dim.length - 1)
		{
			index1 = j * map.dim.length + i;
			index2 = index1 + 1;
			index3 = index1 + map.dim.length;
			bresenham(mlxparams, iso(map.tab[index1]), iso(map.tab[index2]));
			bresenham(mlxparams, iso(map.tab[index1]), iso(map.tab[index3]));
			i++;
		}
		index1 = j * map.dim.length + i;
		index3 = index1 + map.dim.length;
		bresenham(mlxparams, iso(map.tab[index1]), iso(map.tab[index3]));
		j++;
	}
	i = 0;
	while (i < map.dim.length - 1)
	{
		index1 = j * map.dim.length + i;
		index2 = index1 + 1;
		bresenham(mlxparams, iso(map.tab[index1]), iso(map.tab[index2]));
		i++;
	}
	mlx_put_image_to_window(mlxparams->mlx_ptr, mlxparams->mlx_win, mlxparams->img_ptr, 0, 0);
}
