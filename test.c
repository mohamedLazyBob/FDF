/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhribec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 00:06:13 by nkhribec          #+#    #+#             */
/*   Updated: 2019/12/05 19:35:47 by nkhribec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>

typedef struct	s_info
{
		int bits_per_pixel;
		int size_line;
		int endian;
}				t_info;

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int *img_ptr;
	t_info info;
	int *image;
	int i = 0;
/*
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	img_ptr = (int *)mlx_new_image(mlx_ptr, 500, 500);
	image = (int *)mlx_get_data_addr(img_ptr, &info.bits_per_pixel, &info.size_line, &info.endian);
*/
	/*printf("%d\n", info.bits_per_pixel);
	printf("%d\n", info.size_line);
	printf("%d\n", info.endian);
	info.bits_per_pixel = 64;
	printf("22   %d\n", info.bits_per_pixel);
	image = mlx_get_data_addr(img_ptr, &info.bits_per_pixel, &info.size_line, &info.endian);
	printf("33   %d\n", info.bits_per_pixel);*/
	//img_ptar[3] = 0xffffff;
/*	while (i < 500*70)
	{
		image[i] = 0xffffff;
		i += 500;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 250, 250);
	mlx_loop(mlx_ptr);
*/
	printf("cos == %f;\n", cos(0.523599));
	printf("sin == %f;\n", sin(0.523599));
}
