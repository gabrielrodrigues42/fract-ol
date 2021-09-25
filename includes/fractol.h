/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 02:09:53 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/25 12:05:56 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define ESC 65307
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define WIDTH 1280
# define HEIGHT 720

# define MAX_ITER 512

typedef struct s_points
{
	double	real;
	double	imaginary;
	double	scale_x;
	double	scale_y;
	double	x_view;
	double	y_view;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	int		iter;
}	t_points;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
}	t_mlx;

typedef struct s_fractol
{
	char		*set;
	void		(*fn)(t_points *);
}	t_fractol;

void	parse_args(int argc, char **argv, t_fractol *fractol);
void	create_fractol(t_fractol *fractol);
void	set_limits(t_fractol *fractol, t_points *points);
void	render_frame(t_fractol *fractol, t_mlx *mlx, t_points *points);
void	window_to_viewport(int x, int y, t_points *points);
void	calculate_mandelbrot(t_points *points);
void	calculate_burningship(t_points *points);
void	calculate_julia(t_points *points);
void	pixel_put(int x, int y, t_mlx *mlx, t_points *points);
int		put_image_to_window(t_mlx *mlx);
int		destroyer(t_mlx *mlx);
int		key_hook(int key, t_mlx *mlx);
int		mouse_hook(int key, int x, int y);
int		mouse_motion_hook(int x, int y);

#endif
