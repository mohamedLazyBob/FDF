/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:52:26 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/06 14:57:16 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_mlxparams(t_mlxparams *mlxparams)
{
	mlxparams->mlx_ptr = mlx_init();
	mlxparams->mlx_win = mlx_new_window(mlxparams->mlx_ptr, 800, 800, "mlx 42");
	mlxparams->img_ptr = (int*)mlx_new_image(mlxparams->mlx_ptr, 800, 800);
	mlxparams->length_img = 800;
	mlxparams->width_img = 800;
	mlxparams->image = (int *)mlx_get_data_addr(mlxparams->img_ptr,\
	&mlxparams->bits_per_pixel, &mlxparams->size_line, &mlxparams->endian);
}
