/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:11:41 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/14 23:02:42 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_mandelbrot(t_fractol *fractol);
static void	set_mandelbrot_limits(t_fractol *fractol);

void	create_mandelbrot(t_fractol *fractol, t_mlx *mlx)
{
	int	x;
	int	y;

	set_mandelbrot_limits(fractol);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			window_to_viewport(x, y, fractol, mlx);
			calculate_mandelbrot(fractol);
			my_mlx_pixel_put(x, y, fractol, mlx);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

static void	calculate_mandelbrot(t_fractol *fractol)
{
	double	x_tmp;
	double	x;
	double	y;

	x_tmp = 0.0;
	x = 0.0;
	y = 0.0;
	fractol->iter = 0;
	while (x * x + y * y <= 4 && fractol->iter < MAX_ITER)
	{
		x_tmp = x * x - y * y + fractol->x_view;
		y = 2 * x * y + fractol->y_view;
		x = x_tmp;
		fractol->iter++;
	}
}

static void	set_mandelbrot_limits(t_fractol *fractol)
{
	fractol->x_max = 1.0;
	fractol->x_min = -2.5;
	fractol->y_max = 1.1;
	fractol->y_min = -1.1;
}
