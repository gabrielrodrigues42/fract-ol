/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:42:13 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/03 14:01:09 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_frame(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			window_to_viewport(x, y, vars);
			vars->fn(vars);
			put_pixel(x, y, vars);
			y++;
		}
		x++;
	}
	put_image_to_window(vars);
}

void	render_julia_frame(int x, int y, t_vars *vars)
{
	window_to_viewport(x, y, vars);
	vars->points.real = vars->points.x_view;
	vars->points.imaginary = vars->points.y_view;
	render_frame(vars);
}
