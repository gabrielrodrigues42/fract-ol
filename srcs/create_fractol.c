/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:13:22 by gandrade          #+#    #+#             */
/*   Updated: 2021/09/25 12:05:17 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_fractol(t_fractol *fractol)
{
	t_mlx		mlx;
	t_points	points;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, fractol->set);
	mlx.img = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.len, &mlx.endian);
	set_limits(fractol, &points);
	render_frame(fractol, &mlx, &points);
	mlx_expose_hook(mlx.win, put_image_to_window, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_hook(mlx.win, 6, 1L << 6, mouse_motion_hook, &mlx);
	mlx_hook(mlx.win, 17, 1L << 0, destroyer, &mlx);
	mlx_loop(mlx.ptr);
}
