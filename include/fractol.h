/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 02:09:53 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/19 21:18:53 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define C 99
# define R 114
# define ESC 65307
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MOUSE_LEFT 1

# define ZOOM_IN 1
# define ZOOM_OUT -1
# define ZOOM_FACTOR 1.05
# define SHIFT_FACTOR 0.05

# define WIDTH 600
# define HEIGHT 480

# define MAX_ITER 100

typedef struct s_points
{
	double	real;
	double	imaginary;
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

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
	int	index;
}	t_colors;

typedef struct s_vars
{
	t_colors	colors;
	t_points	points;
	t_mlx		mlx;
	char		*set;
	void		(*fn_calculate)(struct s_vars *);
	int			(*fn_color)(struct s_vars *);
}	t_vars;

void	parse_args(int argc, char **argv, t_vars *vars);
void	parse_julia(int argc, char **argv, t_vars *vars);
void	parse_complex(char **argv, t_vars *vars);
void	print_help(void);
void	create_fractol(t_vars *vars);
void	set_default_julia(t_vars *vars);
void	set_default_color(t_vars *vars);
void	set_default_limits(t_vars *vars);
void	render_frame(t_vars *vars);
void	render_julia_frame(int x, int y, t_vars *vars);
void	window_to_viewport(int x, int y, t_vars *vars);
void	zoom(int x, int y, int scale_direction, t_vars *vars);
void	calculate_mandelbrot(t_vars *vars);
void	calculate_burningship(t_vars *vars);
void	calculate_julia(t_vars *vars);
void	shift(int key, t_vars *vars);
void	reset_image(t_vars *vars);
void	change_color(int index, t_vars *vars);
void	put_pixel(int x, int y, t_vars *vars);
int		put_image_to_window(t_vars *vars);
int		color(t_vars *vars);
int		red(t_vars *vars);
int		green(t_vars *vars);
int		blue(t_vars *vars);
int		destroyer(t_vars *vars);
int		key_hook(int key, t_vars *vars);
int		mouse_hook(int key, int x, int y, t_vars *vars);
int		check_valid_characters(char *str);
int		count_valid_characters(char *str);
int		check_valid_position(char *str);

#endif
