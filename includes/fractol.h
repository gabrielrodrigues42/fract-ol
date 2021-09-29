/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 02:09:53 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/28 15:10:03 by gandrade         ###   ########.fr       */
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

# define ZOOM_IN 1
# define ZOOM_OUT -1

# define WIDTH 400
# define HEIGHT 300

# define MAX_ITER 128

typedef struct s_zoom
{
	double	x_ratio;
	double	y_ratio;
	double	x_delta;
	double	y_delta;
	double	x_delta2;
	double	y_delta2;
}	t_zoom;

typedef struct s_points
{
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
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
}	t_mlx;

typedef struct s_fractol
{
	char	*set;
}	t_fractol;

typedef struct s_vars
{
	t_fractol	fractol;
	t_points	points;
	t_zoom		zoom;
	t_mlx		mlx;
	void		(*fn)(struct s_vars *);
}	t_vars;

void	parse_args(int argc, char **argv, t_vars *vars);
void	create_fractol(t_vars *vars);
void	set_limits(t_vars *vars);
void	render_frame(t_vars *vars);
void	window_to_viewport(int x, int y, t_vars *vars);
void	calculate_mandelbrot(t_vars *vars);
void	calculate_burningship(t_vars *vars);
void	calculate_julia(t_vars *vars);
void	zoom(int x, int y, int scale_direction, t_vars *vars);
void	pixel_put(int x, int y, t_vars *vars);
int		put_image_to_window(t_vars *vars);
int		destroyer(t_vars *vars);
int		key_hook(int key, t_vars *vars);
int		mouse_hook(int key, int x, int y, t_vars *vars);

#endif
