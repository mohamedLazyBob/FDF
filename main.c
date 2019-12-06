/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:58:51 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/06 22:05:38 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_temp
{
	t_mlxparams	*mlxparams;
	t_map		*map;
}				t_temp;

int put(int keycode, void *temp1)
{
	t_temp *temp = (t_temp*)temp1;
	t_map *map = temp->map;
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
	{
		zoom(map);
		ft_memset(temp->mlxparams->image, 0x0000, temp->mlxparams->length_img * temp->mlxparams->width_img * 4);
		parallel_proj(temp->mlxparams, *map);
	}
	return (0);
}

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
