/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:52:26 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/08 06:10:16 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_mlxparams(t_mlxparams *mlxparams)
{
	mlxparams->mlx_ptr = mlx_init();
	mlxparams->mlx_win = mlx_new_window(mlxparams->mlx_ptr, LEN, WID, "mlx 42");
	mlxparams->img_ptr = (int*)mlx_new_image(mlxparams->mlx_ptr, LEN, WID);
	mlxparams->length_img = LEN;
	mlxparams->width_img = WID;
	mlxparams->image = (int *)mlx_get_data_addr(mlxparams->img_ptr,\
	&mlxparams->bits_per_pixel, &mlxparams->size_line, &mlxparams->endian);
}
