/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaboub <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:34:08 by mzaboub           #+#    #+#             */
/*   Updated: 2019/12/10 00:56:38 by mzaboub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>
# define LEN 2500
# define WID 1500
# define COLOR 0X00FFFFFF
# define TRUE 1
# define FALSE 0
# define ABS(v) ((v > 0) ? v : -v)

typedef struct	s_mapdim
{
	int		length;
	int		width;
}				t_mapdim;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		v;
}				t_point;

typedef struct	s_map
{
	t_point		*tab;
	t_mapdim	dim;
}				t_map;

/*
**typedef struct	s_isopt
** {
** 	int		x;
** 	int		y;
** 	int		color;
** }				t_isopt;
*/

/*
** typedef struct	s_isomap
** {
** 	t_isopt		*tab;
** 	t_mapdim	dim;
** }				t_isomap;
** typedef struct	s_homothetie
** {
** 	t_point (*p)(int k, t_point pt);
** 	int k;
** }				t_homothetie;
*/

typedef struct	s_mlxxparams
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			length_win;
	int			width_win;
	void		*img_ptr;
	int			*image;
	int			length_img;
	int			width_img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlxparams;

/*
** ***************************************************************************
*/

typedef	struct	s_draw_vars
{
	int	edx;
	int	pdx;
	int	dx;
	int	dy;
	int	incrx;
	int	incry;
	int	i;
	int	index;
}				t_draw_vars;

/*
**  typedef struct	s_drowparams
**  {
** 	int zoom;
** 	int translation;
** 	int altitude_z;
** }				t_drowparams;
** typedef struct s_vars
** {
** 	t_mlxparams     *mlxparams;
** 	t_map           *map;
** 	t_drowparams    *drawparams;
**                t_vars;
** }
*/
typedef struct	s_hook
{
	t_mlxparams	*mlxparams;
	t_map		*map;
	t_point		proj_params[2];
}				t_hook;

int				put(int keycode, void *vartemp);
void			zoomin(t_map *map);
void			zoomout(t_map *map);
void			zoom(t_map *map);
void			get_params_to_center_isoproject(int *x, int *y, t_map *map);
void			get_params_to_center_parallelproject(int *x, int *y, \
		t_map *map);

/*
** ***************************************************************************
*/

void			fdf(t_map *map);
int				is_file_valid(int nbr_of_arg, char **arg);
void			get_map(int *fd, t_map *map, char *arg);
void			get_mapdim(int fd, t_map *map);
int				get_length(char *s);
void			skip_space(char **s);
void			skip_notspace(char **s);
int				digitlength(int n);
int				max(int a, int b, int c, int d);
int				min(int a, int b, int c, int d);
void			printmap(t_map map);
void			*ft_memdup(void *mem, size_t size);
t_map			dupmap(t_map map);
void			bresenham(t_mlxparams *mlxparams, t_point p1, t_point p2);
void			draw_in_octant1458(t_mlxparams *mlxparams, t_point p1, \
												t_point p2);
void			draw_in_octant2367(t_mlxparams *mlxparams, t_point p1, \
		t_point p2);
void			draw_horizental_line(t_mlxparams *mlxparams, t_point pt1, \
		t_point pt2);
void			draw_vertical_line(t_mlxparams *mlxparams, t_point pt1, \
		t_point pt2);
void			draw_diagonal_line(t_mlxparams *mlxparams, t_point pt1, \
		t_point pt2);
int				is_trivial_line(int dx, int dy);
int				is_horizontal(int dx, int dy);
int				is_vertical(int dx, int dy);
int				is_diagonal(int dx, int dy);
void			swap(int *a, int *b);
t_point			swap_coordinats(t_point point);
void			translation(int x, int y, t_map *map);
t_point			translation2(int x, int y, t_point point);
void			parallel_proj(t_hook *vars, t_point pt);
void			iso_proj(t_hook *vars, t_point pt);

void			homothetie(int k, t_map *map);
t_point			iso(t_point point);
void			fill_mlxparams(t_mlxparams *mlxparams);
void			ft_get_params_to_center_isoproject(int *x, int *y, t_map *map);
void			ft_get_params_to_center_parallelproject(int *x, int *y, \
		t_map *map);

/*
** in file : bresenham draw function
*/

int				ft_color(t_point p1, t_point p2);
void			initialize_draw_vars(t_draw_vars *var, t_point p1, \
														t_point p2);
void			draw_in_octant2367(t_mlxparams *mlxparams, t_point p1, \
															t_point p2);
void			draw_in_octant1458(t_mlxparams *mlxparams, t_point p1, \
															t_point p2);
void			draw_horizontal_line(t_mlxparams *mlxparams, t_point pt1, \
																t_point pt2);

/*
**  in file : bresenham help function
*/

t_point			swap_coordinats(t_point point);
int				is_horizontal(int dx, int dy);
int				is_vertical(int dx, int dy);
int				is_diagonal(int dx, int dy);
void			swap(int *a, int *b);

/*
** in file : tools 2
*/

void			zoomout(t_map *map);
void			zoomin(t_map *map);
int				min(int a, int b, int c, int d);
int				max(int a, int b, int c, int d);

int				ft_exit(void *hook);
/*
** t_point			homothetie(int k, t_point point);
** t_point			translation(t_point vect, t_point point);
*/

#endif
