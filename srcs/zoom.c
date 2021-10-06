/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:22:55 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/05 23:12:22 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int x, int y, int scale_direction, t_vars *vars)
{
	double	x_ratio;
	double	y_ratio;
	double	x_delta;
	double	y_delta;

	x_ratio = (double)x / WIDTH;
	y_ratio = (double)y / HEIGHT;
	x_delta = vars->points.x_max - vars->points.x_min;
	y_delta = vars->points.y_max - vars->points.y_min;
	if (scale_direction == ZOOM_IN)
	{
		x_delta = (ZOOM_FACTOR * x_delta) - x_delta;
		y_delta = (ZOOM_FACTOR * y_delta) - y_delta;
	}
	if (scale_direction == ZOOM_OUT)
	{
		y_delta = (1 / ZOOM_FACTOR * y_delta) - y_delta;
		x_delta = (1 / ZOOM_FACTOR * x_delta) - x_delta;
	}
	vars->points.x_min -= x_delta * x_ratio;
	vars->points.x_max += x_delta * (1 - x_ratio);
	vars->points.y_max += y_delta * (1 - y_ratio);
	vars->points.y_min -= y_delta * y_ratio;
	render_frame(vars);
}
