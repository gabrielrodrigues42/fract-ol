/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandrade <gandrade@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:22:55 by gandrade          #+#    #+#             */
/*   Updated: 2021/10/03 14:04:57 by gandrade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int x, int y, int scale_direction, t_vars *vars)
{
	vars->zoom.x_ratio = (double)x / WIDTH;
	vars->zoom.y_ratio = (double)y / HEIGHT;
	vars->zoom.x_delta = vars->points.x_max - vars->points.x_min;
	vars->zoom.y_delta = vars->points.y_max - vars->points.y_min;
	if (scale_direction == ZOOM_IN)
	{
		vars->zoom.x_delta2 = (ZOOM_FACTOR * vars->zoom.x_delta)
			- vars->zoom.x_delta;
		vars->zoom.y_delta2 = (ZOOM_FACTOR * vars->zoom.y_delta)
			- vars->zoom.y_delta;
	}
	if (scale_direction == ZOOM_OUT)
	{
		vars->zoom.x_delta2 = (1 / ZOOM_FACTOR * vars->zoom.x_delta)
			- vars->zoom.x_delta;
		vars->zoom.y_delta2 = (1 / ZOOM_FACTOR * vars->zoom.y_delta)
			- vars->zoom.y_delta;
	}
	vars->points.x_min -= vars->zoom.x_delta2 * vars->zoom.x_ratio;
	vars->points.x_max += vars->zoom.x_delta2 * (1 - vars->zoom.x_ratio);
	vars->points.y_max += vars->zoom.y_delta2 * (1 - vars->zoom.y_ratio);
	vars->points.y_min -= vars->zoom.y_delta2 * vars->zoom.y_ratio;
	render_frame(vars);
}
