/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:13:22 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/18 22:42:46 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_fractol(t_vars *vars)
{
	vars->mlx.ptr = mlx_init();
	vars->mlx.win = mlx_new_window(vars->mlx.ptr, WIDTH, HEIGHT, "fractol");
	vars->mlx.img = mlx_new_image(vars->mlx.ptr, WIDTH, HEIGHT);
	vars->mlx.addr = mlx_get_data_addr(vars->mlx.img, &vars->mlx.bpp,
			&vars->mlx.len, &vars->mlx.end);
	set_default_color(vars);
	set_default_limits(vars);
	render_frame(vars);
	mlx_expose_hook(vars->mlx.win, put_image_to_window, vars);
	mlx_key_hook(vars->mlx.win, key_hook, vars);
	mlx_mouse_hook(vars->mlx.win, mouse_hook, vars);
	mlx_hook(vars->mlx.win, 17, 1L << 0, destroyer, vars);
	mlx_loop(vars->mlx.ptr);
}
