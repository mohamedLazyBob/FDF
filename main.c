/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:58:51 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/07 01:37:57 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(t_map *map)
{
	t_mlxparams	*mlxparams;
	t_temp 	temp;
	//t_isomap	*isomap;

	if (!(mlxparams = malloc(sizeof(*mlxparams))))
	{
		perror("");
		exit(0);
	}
	fill_mlxparams(mlxparams);
	//iso_proj(mlxparams, *map);
	
	temp.mlxparams = mlxparams;
	temp.map = map;
	homothetie(20, map);
	translation(10, 10, map);
	parallel_proj(mlxparams, *map);

	mlx_key_hook(mlxparams->mlx_win, put, (void*)&temp);
	mlx_loop(mlxparams->mlx_ptr);
}

int 	main(int ac, char **av)
{
	int		fd;
	t_map	*map;
//	t_map	map2;

	if (!(fd = is_file_valid(ac, av)))
		return (0);
	//printf("---%lu---\n",sizeof(*map));
	if (!(map = malloc(sizeof(*map))))
	{
		perror("");
		return (0);
	}
	get_map(fd, map);
	close (fd);
	//map2 = dupmap(map);
	//printf("%d\n", map2.dim.length);
	//printf("%d\n", map2.dim.width);
	//printmap(*map);
	fdf(map);
	return (0);
}
