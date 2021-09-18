/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 02:09:53 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/17 20:46:12 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_ITER 128
# define WIDTH 1280
# define HEIGHT 720

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_fractol
{
	char	*set;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	double	x_view;
	double	y_view;
	int		iter;
	void	(*f)(struct s_fractol *, struct s_mlx *);
}	t_fractol;

void	parse_args(int argc, char **argv, t_fractol *fractol);
void	mlx_handler(t_fractol *fractol);
void	create_mandelbrot(t_fractol *fractol, t_mlx *mlx);
void	create_julia(t_fractol *fractol, t_mlx *mlx);
void	create_burning_ship(t_fractol *fractol, t_mlx *mlx);
void	window_to_viewport(int x, int y, t_fractol *fractol, t_mlx *mlx);
void	pixel_put(int x, int y, t_fractol *fractol, t_mlx *mlx);
int		put_image_to_window(t_mlx *mlx);

#endif
