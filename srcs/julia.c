/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:36:42 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/13 20:12:48 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_julia(t_fractol *fractol);
static void	set_julia_limits(t_fractol *fractol);

void	create_julia(t_fractol *fractol, t_mlx *mlx)
{
	int	x;
	int	y;

	set_julia_limits(fractol);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			window_to_viewport(x, y, fractol);
			calculate_julia(fractol);
			my_mlx_pixel_put(x, y, fractol, mlx);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

static void	calculate_julia(t_fractol *fractol)
{
	double	x_tmp;

	x_tmp = 0.0;
	fractol->iter = 0;
	while (fractol->x_view * fractol->x_view + fractol->y_view * fractol->y_view
		<= 4 && fractol->iter < MAX_ITER)
	{
		x_tmp = fractol->x_view * fractol->x_view
			- fractol->y_view * fractol->y_view;
		fractol->y_view = 2 * fractol->x_view * fractol->y_view + 0.355;
		fractol->x_view = x_tmp + 0.355;
		fractol->iter++;
	}
}

static void	set_julia_limits(t_fractol *fractol)
{
	fractol->x_max = 2.0;
	fractol->x_min = -2.0;
	fractol->y_max = 1.2;
	fractol->y_min = -1.2;
}
